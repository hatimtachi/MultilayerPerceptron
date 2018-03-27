//
//  main.c
//  perceptronMultiCouche
//
//  Created by hatim tachi on 09/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "NeuronStructure.h"
#include "NeuronConfiguration.h"
#include "CalculatedNeuron.h"
#include "readFile.h"
#include "Network.h"

#define FILENAME_TRANING "Traning.txt"
#define FILENAME_CONFIGURATION "Configuration.txt"


int main(int argc, const char * argv[]) {
    
    /***************************************** Parametre ***************************************************************/
    srand((unsigned int)time(NULL));
    double eta                          = atof(argv[1]);
    int maxIteration                    = 200000;
        
    int numberOfInputNeurons            = 0;
    int numberOfHiddenAndOutputNeurons  = 0;
    int lengthOfOutput                  = 0;
    int lengthDataTraning               = getLengthFile(FILENAME_TRANING);    
    
    Data *inputData                     = malloc(lengthDataTraning * sizeof(Data));
    Data *ouputData                     = malloc(lengthDataTraning * sizeof(Data));
    
    int vectornumberOfNeuronsPerLayer[getWidthFile(FILENAME_CONFIGURATION) - 1];

    getConfigurationFile(FILENAME_CONFIGURATION, &numberOfInputNeurons, &numberOfHiddenAndOutputNeurons, &lengthOfOutput,vectornumberOfNeuronsPerLayer);
    
    getDataFromFile(FILENAME_TRANING, inputData, ouputData, numberOfInputNeurons,lengthOfOutput);
    
    double vectorExpected[lengthOfOutput];
    
    
    /***************************************** Configuration du reseau ***************************************************/

 
    layer layerOfNeuronNetwork;
    inputNeuron *inputNeuronNetwork = calloc(numberOfInputNeurons, sizeof(inputNeuron));
    layerOfNeuronNetwork.layer      = calloc(numberOfHiddenAndOutputNeurons, sizeof(hiddenAndOutputNeuron*));
    
    if (layerOfNeuronNetwork.layer != NULL) {
        
        for (int i = 0; i < numberOfHiddenAndOutputNeurons; i++) {
            
            layerOfNeuronNetwork.layer[i] = calloc(vectornumberOfNeuronsPerLayer[i], sizeof(hiddenAndOutputNeuron));
        
        }
    }
    
    
    
    configurationLayers(numberOfHiddenAndOutputNeurons, numberOfInputNeurons, vectornumberOfNeuronsPerLayer, &layerOfNeuronNetwork);
  
    networkInitialization(numberOfInputNeurons, numberOfHiddenAndOutputNeurons, lengthOfOutput, vectornumberOfNeuronsPerLayer, vectorExpected, inputNeuronNetwork, inputData, ouputData, &layerOfNeuronNetwork);
    
    /******************************************** Apprentissage *************************************************************/

    int test = 0;
    int nbit = 0;
    double errorQuadratique = 0;
    double outputValue = .0;
    bool stopCondi = true;
    while ((stopCondi) && (nbit < maxIteration)){
        test = 0;
        nbit++;
        for (int indexEntree = 0; indexEntree < lengthDataTraning; indexEntree++)
            {
        
                for (int j = 0; j < numberOfInputNeurons; j++)
                    {
                
                        inputNeuronNetwork[j].value = inputData[indexEntree].vector[j];
            
                    }
            
                for (int j = 0; j < lengthOfOutput; j++)
                    {
                   
                        vectorExpected[j] = ouputData[indexEntree].vector[j];

                    }
        
                    propagationInNetwork(numberOfHiddenAndOutputNeurons, vectornumberOfNeuronsPerLayer, inputNeuronNetwork,
                                 &layerOfNeuronNetwork);
                        
                    backpropagationInNetwork(numberOfHiddenAndOutputNeurons,eta,vectornumberOfNeuronsPerLayer,
                      &layerOfNeuronNetwork,inputNeuronNetwork, vectorExpected);
                    
            }
            for (int indexEntree = 0; indexEntree < lengthDataTraning; indexEntree++){
                for (int j = 0; j < numberOfInputNeurons; j++)
                {
            
                    inputNeuronNetwork[j].value = inputData[indexEntree].vector[j];
        
                }
        
            for (int j = 0; j < lengthOfOutput; j++)
                {
               
                    vectorExpected[j] = ouputData[indexEntree].vector[j];

                }
                outputValue = propagationInNetwork(numberOfHiddenAndOutputNeurons, vectornumberOfNeuronsPerLayer, inputNeuronNetwork,
                    &layerOfNeuronNetwork);
            
                errorQuadratique +=  pow(vectorExpected[0] -  outputValue ,2);                                
            }            
            errorQuadratique = sqrt(errorQuadratique);
            printf("-->>> StopValue <<<--- || %lf / %d ",errorQuadratique,lengthDataTraning);    
            errorQuadratique = (double) (errorQuadratique/ lengthDataTraning);
            printf("== %lf\n",errorQuadratique);       
            if(errorQuadratique < 0.001)
            {

                stopCondi = false;

            }
            
                errorQuadratique = .0;                
    }

    
    
    /*********************************************************************************************************/

    
    saveWeightsTraining(numberOfHiddenAndOutputNeurons,numberOfInputNeurons,vectornumberOfNeuronsPerLayer,&layerOfNeuronNetwork);
    
    
    
    printf("*********************************************\n");
    printf("nombre d'iteration == %d avec un max d'iteration == %d\n",nbit,maxIteration);
    printf("*********************************************\n");
    
    free(inputData);
    free(ouputData);
    free(inputNeuronNetwork);
    return 0;
}
