#include <string>
#include <iostream>
#include <vector>
#include "Railcar.h"
#include "InboundYard.h"
#include "OutboundYard.h"
#include "Simulation.h"
#include "DataTracker.h"
#ifndef Driver_h
#define Driver_h
class Driver{
    public:
        int inboundTrackNum;
        int outboundTrackNum;
        int policy;
        int algorithm;
        int SimulationTimer;
        int currentTime;
        InboundYard Inbound();
        OutboundYard Outbound();
        Simulation Sim();
        DataTracker Track();

        //std::vector<Railcar> 
        void getSettings();
        void start();

};
#endif