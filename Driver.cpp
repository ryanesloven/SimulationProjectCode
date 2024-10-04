#include <string>
#include <iostream>
#include <vector>
#include <thread>
#include "Railcar.h"
#include "InboundYard.h"
#include "OutboundYard.h"
#include "Simulation.h"
#include "DataTracker.h"
#include "Arrival.h"

class Driver{
    public:
        int inboundTrackNum = 1;
        int outboundTrackNum = 1;
        int policy = 1;
        int algorithm = 1;
        int SimulationTimer = 28800;
        int currentTime = 0;
        InboundYard Inbound();
        OutboundYard Outbound();
        Simulation Sim();
        DataTracker Track();

        //std::vector<Railcar> 
        void getSettings(){
            std::cout << "Enter the number of tracks the inbound yard will have (integer).";
            std::cin >> inboundTrackNum;
            std::cout << "Enter the number of tracks the outbound yard will have (integer).";
            std::cin >> outboundTrackNum;
            std::cout << "What policy will be used for this run of the simulation?";
            std::cout << "Option 1: TMP-Full";
            std::cout << "Option 2: TMP-Last";
            std::cout << "Option 3: TMP-Split";
            std::cout << "Enter a number corresponding to desired policy (1, 2, or 3).";
            std::cin >> policy;
            std::cout << "What algorithm will be used for this run of the simulation?";
            std::cout << "Option 1: Dynamic Programming";
            std::cout << "Option 2: Greedy";
            std::cout << "Enter a number corresponding to desired algorithm (1 or 2).";
            std::cin >> algorithm;
        }
        void start(){
            InboundYard Inbound(inboundTrackNum, outboundTrackNum); //second value needed to allow Train to work properly
            OutboundYard Outbound(outboundTrackNum);
            DataTracker Track();
            Simulation Sim(policy, algorithm, Inbound, Outbound, Track);
            Arrival Arrive(Inbound, Track, SimulationTimer);
            //Code that setsup first trains. 

            while (currentTime < SimulationTimer){
                if(algorithm == 1){
                    currentTime =+ Sim.callGreedy();
                    currentTime =+ Arrive.forecast();
                }
                else if(algorithm == 2){
                    currentTime =+ Sim.callDynamic();
                    currentTime =+ Arrive.forecast();
                }
            }
        }
        int main(){
            getSettings();
            start();
        }
};