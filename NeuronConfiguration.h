//
//  NeuronConfiguration.h
//  perceptronMultiCouche
//
//  Created by hatim tachi on 09/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#ifndef NeuronConfiguration_h
#define NeuronConfiguration_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NeuronStructure.h"
#include "CalculatedNeuron.h"

void    networkInitialization       (int numberOfInputNeurons,int numberOfHiddenAndOutputNeurons,int lengthOfOutput,
                                     int *vectornumberOfNeuronsPerLayer,double *vectorExpected,inputNeuron *inputNeuronNetwork,
                                     Data *inputData,Data *outputData,layer *layerOfNeuronNetwork);

void    configurationLayers         (int numberOfHiddenAndOutputNeurons,int numberOfInputNeurons,int *vectornumberOfNeuronsPerLayer
                                     ,layer *layerOfNeuronNetwork);

void    displaysTheNeuralNetwork    (int *vectorOfNumberOfNeuronsPerLayer,int numberOfInputNeurons
                                     ,int numberOfHiddenAndOutputNeurons ,inputNeuron *inputNeuronNetwork
                                     ,layer *layerOfNeuronNetwork);


#endif /* NeuronConfiguration_h */
