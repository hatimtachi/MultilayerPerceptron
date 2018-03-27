//
//  Network.h
//  perceptronMultiCouche
//
//  Created by hatim tachi on 27/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#ifndef Network_h
#define Network_h

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "NeuronStructure.h"
#include "NeuronConfiguration.h"
#include "CalculatedNeuron.h"


void    testTraining    (int lengthDataTest,int numberOfHiddenAndOutputNeurons,int numberOfInputNeurons,
                         int *vectornumberOfNeuronsPerLayer,inputNeuron *inputNeuronNetwork,
                         Data *inputDataTest,layer *layerOfNeuronNetwork);


void saveWeightsTraining(int numberOfHiddenAndOutputNeurons,int numberOfInputNeurons,
                         int *vectornumberOfNeuronsPerLayer,layer *layerOfNeuronNetwork);


#endif /* Network_h */
