#include <string>
#include <iostream>
#include <vector>
#include "Railcar.h"
#include "InboundYard.h"
#include "OutboundYard.h"
#include "Simulation.h"
#include "DataTracker.h"

class Driver{
    int inboundTrackNum;
    int outboundTrackNum;
    int policy;
    int algorithm;
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
        std::cout << "Option 3: Branch&Bound";
        std::cout << "Enter a number corresponding to desired algorithm (1, 2, or 3).";
        std::cin >> algorithm;
    }
    void start(){
        InboundYard Inbound();
        OutboundYard Outbound();
        Simulation Sim();
        DataTracker Track();
    }

};