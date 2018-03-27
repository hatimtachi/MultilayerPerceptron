//
//  readFile.c
//  perceptronMultiCouche
//
//  Created by hatim tachi on 19/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#include "readFile.h"


int getLengthFile(char* fileName){
    
    FILE* file  = fopen(fileName,"r");
    
    int nbLine  = 0;
    char *line  = NULL;
    size_t size = getBuffer(fileName) * sizeof(char);
    
    while (getline (&line,&size,file)!= -1) {nbLine++;}
    
    fclose(file);
    return nbLine;
}

/*********************************************************************************************/

int getBuffer(char* fileName){
    FILE* file = fopen(fileName,"r");
    int buf = 0;
    while (!feof(file)) {
        if (getc(file) != '\n') {
            buf++;
        }else{
            break;
        }
    }
    fclose(file);
    return buf*3;
}

/*********************************************************************************************/

void getDataFromFile (char* fileName, Data *inputData, Data *outputData, int numberOfInputNeurons, int lengthOfOutput){
    FILE* file = fopen(fileName,"r");
    
    char line[getBuffer(fileName)];
    char *token;
    const char specialC[2]  = ",";
    int position = 0;
    int it = 0;
    int itPosOut = 0;
    while (fgets(line ,getBuffer(fileName) * sizeof(char) ,file)) {
        inputData[it].vector    = malloc(numberOfInputNeurons   * sizeof(double));
        outputData[it].vector   = malloc(lengthOfOutput         * sizeof(double));
        
        token = strtok(line,specialC);
        while (token != NULL) {
        
            double x = strtod(token, NULL);
            
            if(position < numberOfInputNeurons){
                inputData[it].vector[position] = x;
            }else{
                outputData[it].vector[itPosOut] = x;
                itPosOut++;
            }
            position++;
            token = strtok(NULL, specialC);
        }
        position = 0;
        itPosOut = 0;
        it++;
    }
    fclose(file);
}

/*********************************************************************************************/

int getWidthFile(char *fileName){
    
    FILE* file = fopen(fileName, "r");
    char line[getBuffer(fileName)];
    char *token;
    const char specialC[2]  = ",";
    
    int width = 0;
    fgets(line ,getBuffer(fileName) * sizeof(char) ,file);
    token = strtok(line,specialC);
    while (token != NULL) {
        width++;
        token = strtok(NULL, specialC);
    }
    
    fclose(file);
    
    return width;
    
}

/*********************************************************************************************/

void getConfigurationFile(char *fileName, int *numberOfInputNeurons, int *numberOfHiddenAndOutputNeurons, int *lengthOfOutput,int *vectornumberOfNeuronsPerLayer){

    FILE* file = fopen(fileName, "r");
    char line[getBuffer(fileName)];
    char *token;
    const char specialC[2]  = ",";
    int position            = 0;
    int width               = getWidthFile(fileName);
    while (fgets(line ,getBuffer(fileName) * sizeof(char) ,file)) {
    
        token = strtok(line,specialC);
        while (token != NULL) {
            
            double x = strtod(token, NULL);
            
            if (position == 0) {
            
                *numberOfInputNeurons = x;
         
            }else {
                
                vectornumberOfNeuronsPerLayer[position - 1] = x;
            
            }
            
            position++;
            
            token = strtok(NULL, specialC);
        }
    }
    *numberOfHiddenAndOutputNeurons = width - 1;
    *lengthOfOutput = vectornumberOfNeuronsPerLayer[*numberOfHiddenAndOutputNeurons - 1];
    
    fclose(file);
}

/*********************************************************************************************/

void viewData(Data *inputData, Data *ouputData, int numberOfInputNeurons, int lengthOfOutput,int lengthData){
    
    for (int i = 0; i < lengthData; i++) {
        
        for (int j = 0; j < numberOfInputNeurons; j++) {
            printf(" %lf ",inputData[i].vector[j]);
        }
        for (int j = 0; j < lengthOfOutput; j++) {
            printf(" -- %lf ",ouputData[i].vector[j]);
        }
        printf("\n");
    }
    
}










