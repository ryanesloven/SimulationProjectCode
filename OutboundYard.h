#ifndef OutboundYard_h
#define OutboundYard_h
class OutboundYard{
    int NumberTracks;
    std::vector<OutboundTrack> Tracks;
    public:
        int getNumberTracks();
};
class OutboundTrack{
    int TrackNumber;
    int available;
    int TrackCapacity;
    std::vector<Railcar> storedCars;
    std::vector<int> storedTrains;
    int temp;
    OutboundTrack();
    void addRailcars(std::vector<Railcar> outbound);
};
#endif