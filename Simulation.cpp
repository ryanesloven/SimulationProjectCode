#include <vector>
#include <string>
#include "Driver.h"
#include "InboundYard.h"
#include "Railcar.h"
class Simulation{
    int policy;
    int algorithm;
    std::vector<Train> TrainsUnclassified;
    std::vector<Train> TrainsClassified;
    std::vector<Railcar> RailcarsUnClassified;
    std::vector<Railcar> RailcarsClassified;
    Simulation(int Policy, int Algorithm){
        policy = Policy;
        algorithm = Algorithm;
    }
    void callPolicy(){
        //"Option 1: TMP-Full
        //"Option 2: TMP-Last
        //"Option 3: TMP-Split
        if (policy == 1){
            
        }

        else if (policy == 2){

        }

        else if (policy == 3){
            RailcarsUnClassified =  
        }
        
    }
    void callAlgorithm(){
        if (algorithm == 1){
            
        }

        else if (algorithm == 2){

        }

        else if (algorithm == 3){
            RailcarsUnClassified =  
        }
    }
};