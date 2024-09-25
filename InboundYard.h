#ifndef InboundYard_h
#define InboundYard_h
class InboundYard{
    int NumberTracks;
    std::vector<InboundTrack> Tracks;
};
class InboundTrack{
    int TrackNumber;
    int available;
    int TrackCapacity;
    std::vector<Railcar> storedCars;
    std::vector<int> storedTrains;
    int temp;
    InboundTrack();
    void addRailcars(std::vector<Railcar> outbound);
};
#endif