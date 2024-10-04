#ifndef Arrival_h
#define Arrival_h
class Arrival{
    Train newTrain;
    InboundYard Inbound;
    DataTracker Tracker;
    int lastTime;
    int MaxTime;
    int delay;
    Arrival(InboundYard In, DataTracker Track, int SimTime);
    int forecast(int time);
}
#endif