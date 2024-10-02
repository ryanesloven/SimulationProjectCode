#ifndef Simulation_h
#define Simulation_h
class Simulation{
    public:
        Simulation(int Policy, int Algorithm, InboundYard inbound, OutboundYard outbound);
        int inboundTrackNum;
        int outboundTrackNum;
        int policy;
        int algorithm;
        void getSettings();
        void start();
};
#endif