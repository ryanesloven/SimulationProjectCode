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
    void callPolicy(){
        //"Option 1: TMP-Full
        //"Option 2: TMP-Last
        //"Option 3: TMP-Split
        //resets local data for new iteration
        RailcarsInboundYard.clear;
        RailcarsOutboundYard.clear;
        RailcarsOperation.clear;
        TrainsClassified.clear;
        TrainsUnclassified.clear;

        if (policy == 1){
            for(int i = 0; i < Inbound.NumberTracks; i++){
                TrainsUnclassified.push_back(Inbound.Tracks[i].storedTrains);
            }
        }

        else if (policy == 2){
            for(int i = 0; i < Inbound.NumberTracks; i++){
                TrainsUnclassified.push_back(Inbound.Tracks[i].storedTrains);
            }
            for(int i = 0; i < Inbound.Tracks.size(); i++){
                RailcarsInboundYard.push_back(Inbound.Tracks[i].storedCars);
            }
        }

        else if (policy == 3){ 
            for(int i = 0; i < Inbound.Tracks.size(); i++){
                RailcarsInboundYard.push_back(Inbound.Tracks[i].storedCars);
            }
        }
        else{
            std::cout << "Error has occurred.";
        }
        
    }

    void callGreedy(){
        int max; //used to compare priority values of railcars and trains.
        int index; //used to prevent unnecessary looping for queue/vector operations.
        int skip[]; //used to skip railcars whose destination track is full.
        auto start = std::chrono::high_resolution_clock::now();
        if (policy == 1){
            max = 0;
            index = 0;
            bool notValid = true; // used to indicate if the max is valid or not
            int InvalidChoices;
            int findSkipIndex;
            //install checks for available space of tracks.
            
            //finds max priority of top value in queues.
            while (notValid){
                InvalidChoices = 0;
                for (int i = 0; i < TrainsUnclassified.size(); i++){
                    //ensures that the maximum, VALID railcar will be chosen
                    if(TrainsUnclassified[i].front.TotalPriority > max && find(skip.begin(), skip.end(), i) != skip.end()){
                        max = TrainsUnclassified[i].front;
                        index = i;
                    }
                    if (find(skip.begin(), skip.end(), i) != skip.end()){ //used to determine if no valid choices exist
                        InvalidChoices = InvalidChoices + 1;
                    }
                    if (InvalidChoices == TrainsUnclassified.size()){
                        std::cout << "No Valid Choices";
                        break;
                    }
                }
                //move railcar to outbound yard and remove from inbound yard, also updates local data
                for(int i = 0; i < TrainsUnclassified[index].Destinations; i++){
                    if(Outbound.Tracks[TrainsUnclassfieid[index].Cars[i].Destination].Available - 1 < 1){
                        skip.append(index);
                    }
                }
                //checks that a valid option is chosen
                findSkipIndex = std::find(skip.begin(), skip.end(), index);
                if(findSkipIndex == skip.end()){
                    notValid = false;
                    Outbound.addTrain(TrainsUnclassified[index].front);
                    Inbound.removeRailcars(TrainsUnclassified[index].front);
                    TrainsUnclassified[index].pop; //removes railcar from local stored info
                }
            }
        }
        else if(policy == 2){
            max = 0;
            index = 0;
            bool notValid = true; // used to indicate if the max is valid or not
            int InvalidChoices;
            int findSkipIndex;
            //install checks for available space of tracks.
            
            //finds max priority of top value in queues.
            while (notValid){
                InvalidChoices = 0;
                for (int i = 0; i < TrainsUnclassified.size(); i++){
                    //ensures that the maximum, VALID railcar will be chosen
                    if(TrainsUnclassified[i].front.TotalPriority > max && find(skip.begin(), skip.end(), i) != skip.end()){
                        max = TrainsUnclassified[i].front;
                        index = i;
                    }
                    if (find(skip.begin(), skip.end(), i) != skip.end()){ //used to determine if no valid choices exist
                        InvalidChoices = InvalidChoices + 1;
                    }
                    if (InvalidChoices == TrainsUnclassified.size()){
                        std::cout << "No Valid Choices";
                        max = 0;
                        for (int i = 0; i < TrainsUnclassified.size(); i++){
                            //ensures that the maximum, railcar will be chosen
                            if(TrainsUnclassified[i].front.Cars[0].Priority > max){
                                max = TrainsUnclassified[i].front;
                                index = i;
                            }
                        }
                        
                        for (int i = 0; i < TrainsUnclassified[index].Cars.size(); i++){
                            if(Outbound.Tracks[TrainsUnclassfieid[index].Cars[i].Destination].Available > 0){
                                Outbound.Tracks[TrainsUnclassfieid[index].Cars[i].Destination].Available =-1;
                                Outbound.addRailcar(RailcarsInboundYard[index].front);
                                Inbound.removeRailcar(TrainsUnclassified[index].Cars[0]);
                                TrainsUnclassified[index].Cars.erase(0); //removes railcar from local stored info
                            }
                            else{
                                //exit gracefully/look at later
                                break;
                            }
                        }
                    }
                }
                //move railcar to outbound yard and remove from inbound yard, also updates local data
                for(int i = 0; i < TrainsUnclassified[index].Destinations; i++){
                    if(Outbound.Tracks[i].available - TrainsUnclassified[index].Destinations[i] < 1){
                        skip.append(index);
                    }
                }
                findSkipIndex = std::find(skip.begin(), skip.end(), index);
                if(findSkipIndex == skip.end()){
                    notValid = false;
                    Outbound.addTrain(TrainsUnclassified[index].front);
                    Inbound.removeRailcars(TrainsUnclassified[index].front);
                    TrainsUnclassified[index].pop; //removes railcar from local stored info
                }
        }
        }
        else if (policy == 3){
            max = 0;
            index = 0;
            bool notValid = true; // used to indicate if the max is valid or not

            //install checks for available space of tracks.
            
            //finds max priority of top value in queues.
            while (notValid){
                for (int i = 0; i < RailcarsInboundYard.size(); i++){
                    //ensures that the maximum, VALID railcar will be chosen
                    if(RailcarsInboundYard[i].front > max && find(skip.begin(), skip.end(), i) != skip.end()){
                        max = RailcarsInboundYard[i].front;
                        index = i;
                    }
                }
                //move railcar to outbound yard and remove from inbound yard, also updates local data
                if(Outbound.Tracks[RailcarsInboundYard[index].destination].available < 1){
                    skip.append(index);
                }
                else{
                    notValid = false;
                    Outbound.addRailcar(RailcarsInboundYard[index].front);
                    Inbound.removeRailcar(RailcarsInboundYard[index].front);
                    RailcarsInboundYard[i].pop; //removes railcar from local stored info
                }
            }
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        Tracker.functionTime(duration);
    }
}