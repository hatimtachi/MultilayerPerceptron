//
//  CalculatedNeuron.c
//  perceptronMultiCouche
//
//  Created by hatim tachi on 13/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#include "CalculatedNeuron.h"




double propagationInNetwork(int numberOfHiddenAndOutputNeurons,int *vectornumberOfNeuronsPerLayer,inputNeuron *inputNeuronNetwork, layer *layerOfNeuronNetwork){
    double outputValue = .0;

    for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
        for (int j = 0; j < vectornumberOfNeuronsPerLayer[i]; j++) {
            
            layerOfNeuronNetwork->layer[i][j].value = 0;
            if (i == 0) {
                for (int k = 0; k < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; k++) {
                    layerOfNeuronNetwork->layer[i][j].value +=
                    layerOfNeuronNetwork->layer[i][j].weights[k] * inputNeuronNetwork[k].value;
                    
                }
            }else{
                
                for (int k = 0; k < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; k++) {
                    
                    layerOfNeuronNetwork->layer[i][j].value +=
                    layerOfNeuronNetwork->layer[i][j].weights[k] * layerOfNeuronNetwork->layer[i - 1][k].value;
                }
            }
            
            layerOfNeuronNetwork->layer[i][j].value = tangenteHyperbolique(layerOfNeuronNetwork->layer[i][j].value);
            outputValue = layerOfNeuronNetwork->layer[i][j].value;
        }
    }
    return outputValue;
}

/*********************************************************************************************/
void backpropagationInNetwork(int numberOfHiddenAndOutputNeurons,double eta,int *vectornumberOfNeuronsPerLayer, layer *layerOfNeuronNetwork,inputNeuron *inputNeuronNetwork,double *vectorExpected){
    
    double erroValue = 0;
    
    for(int i = numberOfHiddenAndOutputNeurons - 1;i >= 0; i--){
        for (int j = 0; j < vectornumberOfNeuronsPerLayer[i]; j++) {
            
            if( i == numberOfHiddenAndOutputNeurons - 1){
                
                layerOfNeuronNetwork->layer[i][j].value =
                errorOutputValue(vectorExpected[j] ,layerOfNeuronNetwork->layer[i][j].value);
                
                for (int w = 0; w < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; w++) {
                    
                    layerOfNeuronNetwork->layer[i][j].weights[w] +=
                    deltaWeight(layerOfNeuronNetwork->layer[i][j].value,
                                layerOfNeuronNetwork->layer[i-1][w].value) * eta;
                  
                }
                
            }else{
                
                
                if (i != 0) {
                    for (int k = 0; k < vectornumberOfNeuronsPerLayer[i+1]; k++) {
                        
                        erroValue +=
                        errorLayerValue(layerOfNeuronNetwork->layer[i+1][k].value,
                                        layerOfNeuronNetwork->layer[i+1][k].oldWeights[j],
                                        layerOfNeuronNetwork->layer[i][j].value);
                        
                    }
                    layerOfNeuronNetwork->layer[i][j].value = erroValue;
                    erroValue = 0;
                    
                    for (int k = 0; k < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; k++) {
                        
                        layerOfNeuronNetwork->layer[i][j].weights[k] +=
                        deltaWeight(layerOfNeuronNetwork->layer[i+1][k].value,
                                    layerOfNeuronNetwork->layer[i][j].value) * eta;
                        
                    
                    }
                    
                }else{
                
                    for (int k = 0; k < vectornumberOfNeuronsPerLayer[i+1]; k++) {
                        erroValue +=
                        errorLayerValue(layerOfNeuronNetwork->layer[i+1][k].value,
                                        layerOfNeuronNetwork->layer[i+1][k].oldWeights[j],
                                        layerOfNeuronNetwork->layer[i][j].value);
                    }
                    
                    layerOfNeuronNetwork->layer[i][j].value = erroValue;
                    erroValue = 0;
                    
                    for (int k = 0; k < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; k++) {
                        
                        layerOfNeuronNetwork->layer[i][j].weights[k] +=
                        deltaWeight(inputNeuronNetwork[k].value,
                                    layerOfNeuronNetwork->layer[i][j].value) * eta;
                        
                    
                        
                    }
                    
                }
                
            }
        }
    }
    changeWeights(layerOfNeuronNetwork, numberOfHiddenAndOutputNeurons, vectornumberOfNeuronsPerLayer);
}

/*********************************************************************************************/

void changeWeights(layer *layerOfNeuronNetwork, int numberOfHiddenAndOutputNeurons,int *vectornumberOfNeuronsPerLayer){
    
    for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
        for (int j = 0; j < vectornumberOfNeuronsPerLayer[i]; j++) {
            
            for (int w = 0; w < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; w++) {
                
                layerOfNeuronNetwork->layer[i][j].oldWeights[w] = layerOfNeuronNetwork->layer[i][j].weights[w];
                
            }
            
        }
    }
    
}

/*********************************************************************************************/

bool stopCondition(layer *layerOfNeuronNetwork, int numberOfHiddenAndOutputNeurons, int *vectornumberOfNeuronsPerLayer, double *vectorExpected, int errorPercentage){
    
    int i = numberOfHiddenAndOutputNeurons - 1;
    double errorV = errorValue(errorPercentage);

    for(int j = 0;j < vectornumberOfNeuronsPerLayer[i] ; j++){
        
        if(vectorExpected[j] == -1){
        
            if(layerOfNeuronNetwork->layer[i][j].value > (vectorExpected[j] + errorV)){return false;}
        
        }else{
         
            if(layerOfNeuronNetwork->layer[i][j].value < (vectorExpected[j] - errorV)){return false;}
        }
    }
    return true;
}

/*********************************************************************************************/

double errorValue(int errorPercentage){
    return (double)errorPercentage/100;
}

/*********************************************************************************************/

double tangenteHyperbolique(double value){
    return tanh(value);
}

/*********************************************************************************************/

double tangenteHyperboliqueDerivative(double value){
    return  (1 - pow(value, 2));
}

/*********************************************************************************************/

double randBetweenZandO(){
    return (double)rand() / (double)RAND_MAX;
    
}

/*********************************************************************************************/

double errorOutputValue(double valueExpected, double value){
    return (double)(valueExpected - value) * (double)tangenteHyperboliqueDerivative(value);
}

/*********************************************************************************************/

double errorLayerValue(double sigma, double weight, double value){
    return (double)(sigma * weight * tangenteHyperboliqueDerivative(value));
}

/*********************************************************************************************/

double deltaWeight(double sigma, double value){
    return (double)(sigma * value);
}







