//
//  Network.c
//  perceptronMultiCouche
//
//  Created by hatim tachi on 27/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#include "Network.h"



void testTraining(int lengthDataTest,int numberOfHiddenAndOutputNeurons,int numberOfInputNeurons,int *vectornumberOfNeuronsPerLayer,inputNeuron *inputNeuronNetwork,Data *inputDataTest,layer *layerOfNeuronNetwork){
    
    for (int i = 0; i < lengthDataTest; i++) {
        
        for (int j = 0; j < numberOfInputNeurons; j++) {
            
            inputNeuronNetwork[j].value = inputDataTest[i].vector[j];
            
        }
        
        propagationInNetwork(numberOfHiddenAndOutputNeurons, vectornumberOfNeuronsPerLayer, inputNeuronNetwork,
                             layerOfNeuronNetwork);
        
        displaysTheNeuralNetworkTest(vectornumberOfNeuronsPerLayer, numberOfInputNeurons, numberOfHiddenAndOutputNeurons, inputNeuronNetwork, layerOfNeuronNetwork);
        
    }
}


void saveWeightsTraining(int numberOfHiddenAndOutputNeurons,int numberOfInputNeurons,int *vectornumberOfNeuronsPerLayer,layer *layerOfNeuronNetwork){
    
    struct stat st = {0};
    
    if (stat("./WeightsTraining", &st) == -1) {
        mkdir("./WeightsTraining", 0700);
    }
    
    FILE* fileConfiguration = fopen("./WeightsTraining/Configuration.txt", "w");
    FILE* fileWeights       = fopen("./WeightsTraining/Weights.txt", "w");
    
    fprintf(fileConfiguration, "%d",numberOfInputNeurons);
    
    
    for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
    
        fprintf(fileConfiguration,",%d",vectornumberOfNeuronsPerLayer[i]);
    
    }
    
    fputs("\n",fileConfiguration);
    
    for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++,fputs("\n", fileWeights)) {
        for (int j = 0; j < vectornumberOfNeuronsPerLayer[i]; j++) {
            
            for (int w = 0; w < layerOfNeuronNetwork->layer[i][j].lenghtOfWeights; w++) {
                
                if ((j == vectornumberOfNeuronsPerLayer[i] - 1)&&( w ==layerOfNeuronNetwork->layer[i][j].lenghtOfWeights - 1)) {
                
                    fprintf(fileWeights, "%lf",layerOfNeuronNetwork->layer[i][j].weights[w]);
                
                }
                else{
                    
                    fprintf(fileWeights, "%lf,",layerOfNeuronNetwork->layer[i][j].weights[w]);
                
                }
            }
        }
    }
    
    
    fclose(fileWeights);
    fclose(fileConfiguration);
}







