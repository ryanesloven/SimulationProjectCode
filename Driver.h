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
        void getSettings();
        void start();
        InboundYard Inbound();
        OutboundYard Outbound();
        Simulation Sim();
        DataTracker Track();
};
#endif