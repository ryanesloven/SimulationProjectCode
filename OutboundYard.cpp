#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "Railcar.h"

class OutboundYard{
    int NumberTracks;
    std::vector<OutboundTrack> Tracks;
    public:
        int getNumberTracks(){
            return NumberTracks;
        }
};
class OutboundTrack{
    int TrackNumber;
    int available;
    int TrackCapacity;
    std::vector<Railcar> storedCars;
    std::vector<int> storedTrains;
    int temp;
    OutboundTrack(){
        TrackCapacity = 65;
        available = 65;
    }
    void addRailcars(std::vector<Railcar> outbound){
        for(int i = 0; i<outbound.size(); i++){
            if (available > 0){
                storedCars.push_back(outbound[i]);
                temp = outbound[i].getTrainID();
                available =- 1;
                if (std::count(storedTrains.begin(), storedTrains.end(), temp) < 1){
                    storedTrains.push_back(temp);
                }
            }
        }
    }
};