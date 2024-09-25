#ifndef Simulation_h
#define Simulation_h
class Simulation{
    Simulation();
    int inboundTrackNum;
    int outboundTrackNum;
    int policy;
    int algorithm;
    void getSettings();
    void start();
};
#endif