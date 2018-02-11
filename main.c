//
//  main.c
//  perceptronMultiCouche
//
//  Created by hatim tachi on 09/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#include <stdio.h>
#include "NeuronStructure.h"
#include "NeuronConfiguration.h"


int main(int argc, const char * argv[]) {
    
    int numberOfInputNeurons            = 4;
    int numberOfHiddenAndOutputNeurons  = 3;
    int vectornumberOfNeuronsPerLayer[numberOfHiddenAndOutputNeurons] ;

    
    numberOfNeuronsPerLayer(vectornumberOfNeuronsPerLayer, numberOfHiddenAndOutputNeurons);

    
    layer layerOfNeuronNetwork;
    inputNeuron *inputNeuronNetwork = calloc(numberOfInputNeurons, sizeof(inputNeuron));
    layerOfNeuronNetwork.layer      = calloc(numberOfHiddenAndOutputNeurons, sizeof(hiddenAndOutputNeuron*));
    
    if (layerOfNeuronNetwork.layer != NULL) {
        
        for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
            
            layerOfNeuronNetwork.layer[i] = calloc(vectornumberOfNeuronsPerLayer[i], sizeof(hiddenAndOutputNeuron));
        
        }
    }
    
    
    configurationLayers(numberOfHiddenAndOutputNeurons, numberOfInputNeurons, vectornumberOfNeuronsPerLayer, &layerOfNeuronNetwork);
    configurationOfNeuronsValue(numberOfHiddenAndOutputNeurons, vectornumberOfNeuronsPerLayer, inputNeuronNetwork, &layerOfNeuronNetwork);
    displaysTheNeuralNetwork(vectornumberOfNeuronsPerLayer, numberOfInputNeurons, numberOfHiddenAndOutputNeurons, inputNeuronNetwork, &layerOfNeuronNetwork);
    
    
    return 0;
}
