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

void    numberOfNeuronsPerLayer     (int *vectornumberOfNeuronsPerLayer,int numberOfHiddenAndOutputNeurons);

void    configurationLayers         (int numberOfHiddenAndOutputNeurons,int numberOfInputNeurons,int *vectornumberOfNeuronsPerLayer
                                     ,layer *layerOfNeuronNetwork);

void    configurationOfNeuronsValue (int numberOfHiddenAndOutputNeurons,int *vectornumberOfNeuronsPerLayer
                                     ,inputNeuron *inputNeuronNetwork, layer *layerOfNeuronNetwork);

void    displaysTheNeuralNetwork    (int *vectorOfNumberOfNeuronsPerLayer,int numberOfInputNeurons
                                     ,int numberOfHiddenAndOutputNeurons ,inputNeuron *inputNeuronNetwork
                                     ,layer *layerOfNeuronNetwork);

double  sigmoidEquation             (double value);

double  sigmoidDerivative           (double value);
#endif /* NeuronConfiguration_h */
