#include <queue>
#ifndef InboundYard_h
#define InboundYard_h
class InboundYard{
    public:
        int NumberTracks;
        int TrainIDIncrement;
        std::vector<InboundTrack> Tracks;
        int outboundTrackNum;
        InboundYard(int NumTracks, int OutboundTrackNum);
        int addTrain();
        void removeRailcar(Railcar inbound);
        void removeTrain(Train inbound);
};
class InboundTrack{
    public:
        int TrackNumber;
        int available;
        int TrackCapacity;
        std::queue<Railcar> storedCars;
        std::queue<Train> storedTrains;
        int temp;
        int outboundTrackNum; 
        InboundTrack(int TrackID, int OutboundTrackNumber, int TrainID);
        void addRailcars(Train inbound);
};
#endif