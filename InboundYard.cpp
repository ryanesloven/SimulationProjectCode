#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "Railcar.h"

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
    InboundTrack(){
        TrackCapacity = 65;
        available = 65;
    }
    void addRailcars(std::vector<Railcar> inbound){
        for(int i = 0; i<inbound.size(); i++){
            if (available > 0){
                storedCars.push_back(inbound[i]);
                temp = inbound[i].getTrainID();
                available =- 1;
                if (std::count(storedTrains.begin(), storedTrains.end(), temp) < 1){
                    storedTrains.push_back(temp);
                }
            }
        }
    }
};