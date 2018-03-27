//
//  readFile.h
//  perceptronMultiCouche
//
//  Created by hatim tachi on 19/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#ifndef readFile_h
#define readFile_h

#include <stdio.h>
#include "NeuronStructure.h"
#include <stdlib.h>
#include <string.h>


int     getLengthFile       (char* fileName);

int     getBuffer           (char* fileName);

int     getWidthFile        (char *fileName);

void    getConfigurationFile(char *fileName, int *numberOfInputNeurons,
                             int *numberOfHiddenAndOutputNeurons, int *lengthOfOutput,int *vectornumberOfNeuronsPerLayer);

void    getDataFromFile     (char* fileName, Data *inputData, Data *vectorExpected,
                             int numberOfInputNeurons, int lengthOfOutput);

void    viewData            (Data *inputData, Data *ouputData, int numberOfInputNeurons,
                             int lengthOfOutput,int lengthData);
#endif /* readFile_h */
