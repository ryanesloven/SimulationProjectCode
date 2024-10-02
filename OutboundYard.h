#ifndef OutboundYard_h
#define OutboundYard_h

class OutboundYard{
    int NumberTracks;
    std::vector<OutboundTrack> Tracks;
    public:
        OutboundYard(int TrackNumber);
        int getNumberTracks();
        void addRailcar(Railcar outbound);
        void addTrain(Train outbound);
};
class OutboundTrack{
    int TrackNumber;
    int available;
    int TrackCapacity;
    int TrackID;
    std::queue<Railcar> storedCars;
    std::vector<int> storedTrains;
    int temp;
    public:
        OutboundTrack(int ID);
        void addRailcars(std::vector<Railcar> outbound);
};
#endif