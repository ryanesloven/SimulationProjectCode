#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include "DataTracker.h"
#include "Driver.h"
#include "InboundYard.h"
#include "Railcar.h"
#include "OutboundYard.h"

class Simulation{
    int policy;
    int algorithm;
    InboundYard Inbound;
    OutboundYard Outbound;
    std::vector<std::queue<Train>> TrainsUnclassified;
    std::vector<std::queue<Train>> TrainsClassified;
    std::vector<std::queue<Railcar>> RailcarsInboundYard;
    std::vector<std::queue<Railcar>> RailcarsOperation; //Used for computation.
    std::vector<std::queue<Railcar>> RailcarsOutboundYard;

    //Setsup all information needed for the Simulation Object to function properly
    Simulation(int Policy, int Algorithm, InboundYard inbound, OutboundYard outbound, DataTracker Tracker){
        this.policy = Policy;
        this.algorithm = Algorithm;
        this.Inbound = inbound;
        this.Outbound = outbound;
        this.Tracker = Tracker;
    }
    void sendOutbound(){
        //clears out queue if it reaches its size limit
        for(int i = 0; i < RailcarsOutboundYard.size(); i++){
            if (RailcarsOutboundYard[i].size() == 65){
                RailcarsOutboundYard[i] = {};
            }
        }
    }

    int callGreedy(){
        int max; //used to compare priority values of railcars and trains.
        int carsSorted = 0;
        int index; //used to prevent unnecessary looping for queue/vector operations.
        int skip[]; //used to skip railcars whose destination track is full.
        auto start = std::chrono::high_resolution_clock::now();
        if (policy == 1){
            //loads vector to hold available Train options for easy access
            max = 0;
            index = 0;
            bool ValidExists = true; // used to indicate if the max is valid or not
            int InvalidChoices = 0;
            int findSkipIndex;
            //install checks for available space of tracks.
            
            //finds max priority of top value in queues.
            while (ValidExists){
                for (int i = 0; i < inbound.Tracks.size(); i++){
                    //ensures that the maximum, VALID railcar will be chosen
                    if(inbound.Tracks[i].storedTrains.front.TotalPriority > max && find(skip.begin(), skip.end(), i) == skip.end()){
                        max = inbound.Tracks[i].storedTrains.front.TotalPriority;
                        index = i;
                    }
                    if (find(skip.begin(), skip.end(), i) != skip.end()){ //used to determine if no valid choices exist
                        InvalidChoices = InvalidChoices + 1;
                    }
                    //exits if no entire train can be classified validly.
                    if (InvalidChoices >= inbound.Tracks.size()){
                        //end sorting
                        ValidExists = false;
                        return;
                    }
                }
                //move railcar to outbound yard and remove from inbound yard, also updates local data
                for(int i = 0; i < inbound.Tracks[index].storedTrains.front.Cars.size(); i++){
                    if(Outbound.Tracks[inbound.Tracks[index].storedTrains.front.Cars[i].Destination].Available - 1 < 1){
                        skip.append(index);
                    }
                }
                //checks that a valid option is chosen
                findSkipIndex = std::find(skip.begin(), skip.end(), index);
                if(findSkipIndex == skip.end()){
                    //updates inbound and outbound yard with the train being removed and added respectively
                    Outbound.addTrain(inbound.Tracks[index].storedTrains.front);
                    Inbound.removeRailcars(inbound.Tracks[index].storedTrains.front);
                    carsSorted += inbound.Tracks[index].storedTrains.front.Cars.size();
                    Tracker.operationtime(inbound.Tracks[index].storedTrains.front.Cars.size());
                }
            }
        }
        else if(policy == 2){
            max = 0;
            index = 0;
            bool ValidExists = true; // used to indicate if the max is valid or not
            int InvalidChoices = 0;
            int findSkipIndex;
            //install checks for available space of tracks.
            
            //finds max priority of top value in queues.
            while (ValidExists){
                for (int i = 0; i < inbound.Tracks.size(); i++){
                    //ensures that the maximum, VALID railcar will be chosen
                    if(inbound.Tracks[i].storedTrains.front.TotalPriority > max && find(skip.begin(), skip.end(), i) == skip.end()){
                        max = inbound.Tracks[i].storedTrains.front.TotalPriority;
                        index = i;
                    }
                    if (find(skip.begin(), skip.end(), i) != skip.end()){ //used to determine if no valid choices exist
                        InvalidChoices = InvalidChoices + 1;
                    }
                    if (InvalidChoices >= inbound.Tracks.size()){
                        std::cout << "No Valid Choices";
                        max = 0;
                        for (int i = 0; i < inbound.Tracks.size(); i++){
                            //ensures that the maximum, railcar will be chosen
                            if(inbound.Tracks[i].storedTrains.front.Cars[0].Priority > max){
                                max = inbound.Tracks[i].storedTrains.front.Cars[0].Priority;
                                index = i;
                            }
                        }
                        
                        for (int i = 0; i < inbound.Tracks[index].Cars.size(); i++){
                            if(Outbound.Tracks[inbound.Tracks[index].storedTrains.front.Cars[i].Destination].Available - 1 > -1){
                                Outbound.addRailcar(inbound.Tracks[index].storedTrains.front.Cars[i]);
                                Inbound.removeRailcar(inbound.Tracks[index].storedTrains.front.Cars[i]);
                                Tracker.operationtime(1);
                                carsSorted += 1;
                            }
                            else{
                                ValidExists = false;
                                return; // gracefully exit after classification done to best of ability
                            }
                        }
                    }
                }
                //move railcar to outbound yard and remove from inbound yard, also updates local data
                for(int i = 0; i < inbound.Tracks[index].storedTrains.front.Cars.size(); i++){
                    if(Outbound.Tracks[inbound.Tracks[index].storedTrains.front.Cars[i].Destination].Available - 1 < 1){
                        skip.append(index);
                    }
                }
                //checks that a valid option is chosen
                findSkipIndex = std::find(skip.begin(), skip.end(), index);
                if(findSkipIndex == skip.end()){
                    //updates inbound and outbound yard with the train being removed and added respectively
                    Outbound.addTrain(inbound.Tracks[index].storedTrains.front);
                    Inbound.removeRailcars(inbound.Tracks[index].storedTrains.front);
                    carsSorted += inbound.Tracks[index].storedTrains.front.Cars.size();
                    Tracker.operationtime(inbound.Tracks[index].storedTrains.front.Cars.size());
                }
        }
        }
        else if (policy == 3){
            max = 0;
            index = 0;
            bool ValidExists = true; // used to indicate if the max is valid or not

            //install checks for available space of tracks.
            
            //finds max priority of top value in queues.
            while (ValidExists){
                for (int i = 0; i < inbound.Tracks.size(); i++){
                    //ensures that the maximum, VALID railcar will be chosen
                    if(inbound.Tracks[i].storedTrains.Cars.front.Priority > max && find(skip.begin(), skip.end(), i) == skip.end()){
                        max = inbound.Tracks[i].storedTrains.front.Cars.front.Priority;
                        index = i;
                    }
                }
                //stops classifying if no railcars can be sorted validly
                if(skip.size() >= inbound.Tracks.size()){
                    ValidExists = false;
                    return;
                }
                //checks if railcar can be placed in the outbound track.
                if(Outbound.Tracks[inbound.Tracks[index].storedTrains.front.Cars.front.Destination].available - 1 < 1){
                    skip.append(index);
                }
                else{
                    Outbound.addRailcar(inbound.Tracks[index].storedTrains.front.Cars.front);
                    Inbound.removeRailcar(inbound.Tracks[index].storedTrains.front.Cars.front);
                    carsSorted += 1;
                    Tracker.operationtime(1);
                }
            }
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        Tracker.functionTime(duration);
        Tracker.operationTime(carsSorted);
        return carsSorted*10;
    }
}