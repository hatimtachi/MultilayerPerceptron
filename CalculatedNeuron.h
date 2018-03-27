//
//  CalculatedNeuron.h
//  perceptronMultiCouche
//
//  Created by hatim tachi on 13/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#ifndef CalculatedNeuron_h
#define CalculatedNeuron_h

#include <stdio.h>
#include "NeuronStructure.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


double  propagationInNetwork            (int numberOfHiddenAndOutputNeurons,int *vectornumberOfNeuronsPerLayer
                                         ,inputNeuron *inputNeuronNetwork, layer *layerOfNeuronNetwork);

void    backpropagationInNetwork        (int numberOfHiddenAndOutputNeurons,double eta,int *vectornumberOfNeuronsPerLayer
                                        ,layer *layerOfNeuronNetwork,inputNeuron *inputNeuronNetwork
                                        ,double *vectorExpected);                                            

void    changeWeights                   (layer *layerOfNeuronNetwork, int numberOfHiddenAndOutputNeurons,
                                         int *vectornumberOfNeuronsPerLayer);

bool    stopCondition                   (layer *layerOfNeuronNetwork, int numberOfHiddenAndOutputNeurons,
                                         int *vectornumberOfNeuronsPerLayer, double *vectorExpected, int errorPercentage);

double  tangenteHyperbolique            (double value);

double  tangenteHyperboliqueDerivative  (double value);

double  randBetweenZandO                ();

double  errorOutputValue                (double valueExpected, double value);

double  errorLayerValue                 (double sigma, double weight, double value);

double  deltaWeight                     (double sigma, double value);

double  errorValue                      (int errorPercentage);

#endif /* CalculatedNeuron_h */
