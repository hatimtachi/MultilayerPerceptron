//
//  NeuronStructure.h
//  perceptronMultiCouche
//
//  Created by hatim tachi on 09/02/2018.
//  Copyright © 2018 hatim tachi. All rights reserved.
//

#ifndef NeuronStructure_h
#define NeuronStructure_h


typedef struct {
    
    double value;
    
}inputNeuron;

typedef struct{
    
    double value;
    double *weights;
    int number;
    int lenghtOfWeights;
    
}hiddenAndOutputNeuron;


typedef struct {
    
    hiddenAndOutputNeuron **layer;

}layer;



#endif /* NeuronStructure_h */
