//
//  NeuronConfiguration.c
//  perceptronMultiCouche
//
//  Created by hatim tachi on 09/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#include "NeuronConfiguration.h"


void numberOfNeuronsPerLayer(int *vectornumberOfNeuronsPerLayer,int numberOfHiddenAndOutputNeurons){
    
    char buffer[50];
    
    for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
        
        printf("number of neurons per layer in position %d : \n",i);
        gets(buffer);
        vectornumberOfNeuronsPerLayer[i] = atoi(buffer);
        
    }
}

/*********************************************************************************************/

void configurationLayers(int numberOfHiddenAndOutputNeurons,int numberOfInputNeurons,int *vectornumberOfNeuronsPerLayer,layer *layerOfNeuronNetwork){

    for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
        for (int j = 0; j < vectornumberOfNeuronsPerLayer[i]; j++) {
        
            layerOfNeuronNetwork->layer[i][j].number = vectornumberOfNeuronsPerLayer[i];
        
            if (i == 0) {
            
                layerOfNeuronNetwork->layer[i][j].weights = calloc(numberOfInputNeurons, sizeof(double));
                layerOfNeuronNetwork->layer[i][j].lenghtOfWeights = numberOfInputNeurons;
            
            }else{
            
                layerOfNeuronNetwork->layer[i][j].weights = calloc(vectornumberOfNeuronsPerLayer[i - 1], sizeof(double));
                layerOfNeuronNetwork->layer[i][j].lenghtOfWeights = vectornumberOfNeuronsPerLayer[i - 1];
            }
        
        }
    }
}

/*********************************************************************************************/

void configurationOfNeuronsValue(int numberOfHiddenAndOutputNeurons,int *vectornumberOfNeuronsPerLayer,inputNeuron *inputNeuronNetwork, layer *layerOfNeuronNetwork){
    
    for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
        for (int j = 0; j < vectornumberOfNeuronsPerLayer[i]; j++) {
         
            if (i == 0) {
                for (int k = 0; k < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; k++) {
                    
                    layerOfNeuronNetwork->layer[i][j].value +=
                    layerOfNeuronNetwork->layer[i][j].weights[k] * inputNeuronNetwork[k].value;
                    
                }
            }else{
                
                for (int k = 0; k < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; k++) {
                    
                    layerOfNeuronNetwork->layer[i][j].value +=
                    layerOfNeuronNetwork->layer[i][j].weights[k] * layerOfNeuronNetwork->layer[i - 1][j].value;
                }
            }
            
            layerOfNeuronNetwork->layer[i][j].value = sigmoidEquation(layerOfNeuronNetwork->layer[i][j].value);
            
        }
    }
    
}

/*********************************************************************************************/

void displaysTheNeuralNetwork(int *vectorOfNumberOfNeuronsPerLayer,int numberOfInputNeurons ,int numberOfHiddenAndOutputNeurons ,inputNeuron *inputNeuronNetwork ,layer *layerOfNeuronNetwork){
    printf("input values :\n");
    for (int i = 0; i < numberOfInputNeurons; i++) {
        printf("\t %lf ",inputNeuronNetwork[i].value);
    }
    printf("\n*****************\n");
    
    for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
        printf("layer :: %d ::\n",i);
        for (int j = 0; j < vectorOfNumberOfNeuronsPerLayer[i]; j++) {
            
            printf("number of neuron in this layer : %d && size of weights is %d && value is : %lf \n",layerOfNeuronNetwork->layer[i][j].number,layerOfNeuronNetwork->layer[i][j].lenghtOfWeights,layerOfNeuronNetwork->layer[i][j].value);
            printf("weights values is :\n");
            for (int k = 0; k < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; k++) {
                printf("\t %lf ",layerOfNeuronNetwork->layer[i][j].weights[k]);
            }
            printf("\n");
        }
        printf("\n******************\n");
    }
}

/*********************************************************************************************/

double sigmoidEquation(double value){
    return 1. / (1.+ (double)exp(-1 * value));
}

/*********************************************************************************************/

double sigmoidDerivative(double value){
    return value * (1 - value);
}





