#include <random>
#include "InboundYard.h"
#include "DataTracker.h"
#include "Driver.h"
#include "Railcar.h"
class Arrival{
    Train newTrain;
    InboundYard Inbound;
    DataTracker Tracker;
    int lastTime = 0;
    int MaxTime;
    int delay = 0;
    Arrival(InboundYard In, DataTracker Track, int SimTime){
        Inbound = In;
        Tracker = Track;
        MaxTime = SimTime;
    }
    int forecast(int time){
        if(time - lastTime > rand() % 900){ //makes at least one train arrive every 15 minutes
            delay = inbound.addTrain();
            return delay*10;//increases internal timer by the number of trains classifeid multiplied by the operation time
        }
    }
}