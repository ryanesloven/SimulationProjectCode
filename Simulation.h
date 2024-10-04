#ifndef Simulation_h
#define Simulation_h
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
    Simulation(int Policy, int Algorithm, InboundYard inbound, OutboundYard outbound, DataTracker Tracker);
    void sendOutbound();
    int callGreedy();
}
#endif