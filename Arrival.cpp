#include <random>
#include "InboundYard.h"
#include "DataTracker.h"
#include "Driver.h"
#include "Railcar.h"
class Arrival{
    Train newTrain;
    InboundYard Inbound;
    DataTracker Tracker;
    int SimTimerMax;
    Arrival(InboundYard In, DataTracker Track, int SimTime){
        Inbound = In;
        Tracker = Track;
        SimTimerMax = SimTime;
    }

    void newTrains(){
        while(Tracker.Time < SimTimerMax){
            if(//some specific criteria// ){
                
            
        }
    }
}