//
//  NeuronConfiguration.c
//  perceptronMultiCouche
//
//  Created by hatim tachi on 09/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#include "NeuronConfiguration.h"



void networkInitialization(int numberOfInputNeurons,int numberOfHiddenAndOutputNeurons,int lengthOfOutput,int *vectornumberOfNeuronsPerLayer,double *vectorExpected,inputNeuron *inputNeuronNetwork,Data *inputData,Data *outputData,layer *layerOfNeuronNetwork){
    
    for (int i = 0; i < numberOfInputNeurons; i++) {
        inputNeuronNetwork[i].value = inputData[0].vector[i];
    }
    for (int i = 0; i < lengthOfOutput; i++) {
        vectorExpected[i] = outputData[0].vector[i];
    }
    
    
    double value = 0;
    for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
        for (int j = 0; j < vectornumberOfNeuronsPerLayer[i]; j++) {
            for (int w =0; w < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; w++) {
                if (i == 0) {
                    value = 0.5;
                }else{
                    value = 1;
                }
                
                
                layerOfNeuronNetwork->layer[i][j].weights[w] = randBetweenZandO();
                layerOfNeuronNetwork->layer[i][j].oldWeights[w] = layerOfNeuronNetwork->layer[i][j].weights[w];
                
            }
        }
    }
}

/*********************************************************************************************/

void configurationLayers(int numberOfHiddenAndOutputNeurons,int numberOfInputNeurons,int *vectornumberOfNeuronsPerLayer,layer *layerOfNeuronNetwork){

    for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
        for (int j = 0; j < vectornumberOfNeuronsPerLayer[i]; j++) {
        
            layerOfNeuronNetwork->layer[i][j].number = vectornumberOfNeuronsPerLayer[i];
        
            if (i == 0) {
            
                layerOfNeuronNetwork->layer[i][j].weights           = calloc(numberOfInputNeurons, sizeof(double));
                layerOfNeuronNetwork->layer[i][j].oldWeights        = calloc(numberOfInputNeurons, sizeof(double));
                layerOfNeuronNetwork->layer[i][j].lenghtOfWeights   = numberOfInputNeurons;
            
            }else{
            
                layerOfNeuronNetwork->layer[i][j].weights           = calloc(vectornumberOfNeuronsPerLayer[i - 1], sizeof(double));
                layerOfNeuronNetwork->layer[i][j].oldWeights        = calloc(vectornumberOfNeuronsPerLayer[i - 1], sizeof(double));
                layerOfNeuronNetwork->layer[i][j].lenghtOfWeights   = vectornumberOfNeuronsPerLayer[i - 1];
            }
        
        }
    }
}

/*********************************************************************************************/

void displaysTheNeuralNetwork(int *vectorOfNumberOfNeuronsPerLayer,int numberOfInputNeurons ,int numberOfHiddenAndOutputNeurons ,inputNeuron *inputNeuronNetwork ,layer *layerOfNeuronNetwork){
    printf("input values :\n\n");
    for (int i = 0; i < numberOfInputNeurons; i++) {
        printf("\t %lf ",inputNeuronNetwork[i].value);
    }
    printf("\n*****************\n");
    
    for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
        if (i == numberOfHiddenAndOutputNeurons - 1) {
            printf("output ::\n\n");
        }else{
            printf("layer :: %d ::\n\n",i);
        }
        for (int j = 0; j < vectorOfNumberOfNeuronsPerLayer[i]; j++) {
            
            printf("number of neuron in this layer : %d && size of weights is %d && value is : %lf \n\n",layerOfNeuronNetwork->layer[i][j].number,layerOfNeuronNetwork->layer[i][j].lenghtOfWeights,layerOfNeuronNetwork->layer[i][j].value);
            printf("weights values is :\n");
            for (int k = 0; k < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; k++) {
                printf("\t %lf ",layerOfNeuronNetwork->layer[i][j].weights[k]);
            }
            printf("\nold weights values is :\n");
            for (int k = 0; k < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; k++) {
                printf("\t %lf ",layerOfNeuronNetwork->layer[i][j].oldWeights[k]);
            }
            printf("\n\n");
        }
        printf("\n******************\n");
    }
}






