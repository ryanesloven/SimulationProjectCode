#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
#include "Railcar.h"

class OutboundYard{
    int NumberTracks;
    std::vector<OutboundTrack> Tracks;
    public:
        OutboundYard(int TrackNumber){
            NumberTracks = TrackNumber;
            for(int i = 0; i<NumberTracks; i++){
                int TrackId = i+1;
                OutboundTrack temp(TrackId);
            }
        }
        int getNumberTracks(){
            return NumberTracks;
        }

        void addTrain(Train outbound){
            for(int i = 0; i < outbound.Cars; i++){
                Tracks[outbound.Cars[i].Destination].push(outbound.Cars[i]);
            }
        }
        void addRailcar(Railcar outbound){
            Tracks[outbound.Destination].push(outbound);
            Tracks[outbound.Destination].available = Tracks[outbound.Destination].available - 1;
        }
};
class OutboundTrack{
    int TrackNumber;
    int available;
    int TrackCapacity;
    int TrackID;
    std::queue<Railcar> storedCars;
    std::queue<Train> storedTrains;
    int temp;
    public:
        OutboundTrack(int ID){
            TrackCapacity = 65;
            available = 65;
            TrackID = ID;
        }


        void addRailcars(std::vector<Railcar> outbound){
            for(int i = 0; i<outbound.size(); i++){
                if (available > 0){
                    storedCars.push(outbound[i]);
                    temp = outbound[i].getTrainID();
                    available =- 1;
                    if (std::count(storedTrains.begin(), storedTrains.end(), temp) < 1){
                        storedTrains.push_back(temp);
                    }
                }
            }
        }
};