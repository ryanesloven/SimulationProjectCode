#include <queue>
#ifndef InboundYard_h
#define InboundYard_h
class InboundYard{
    public:
        int NumberTracks;
        int TrainIDIncrement;
        std::vector<InboundTrack> Tracks;
        InboundYard(int NumTracks, int OutboundTrackNum);
        void removeRailcar(Railcar inbound);
};
class InboundTrack{
    public:
        int TrackNumber;
        int available;
        int TrackCapacity;
        std::queue<Railcar> storedCars;
        std::vector<Train> storedTrains;
        int temp;
        InboundTrack(int ID, int OutboundTrackNumber, int TrainID);
        void addRailcars(Train inbound);
};
#endif