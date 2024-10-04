#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <random>
#include <queue>
#include "Railcar.h"

class InboundYard{
    public:
        int NumberTracks;
        int TrainIDIncrement = 1;
        std::vector<InboundTrack> Tracks;
        int outboundTrackNum;
        InboundYard(int NumTracks, int OutboundTrackNum){
            NumberTracks = NumTracks;
            outboundTrackNum = OutboundTrackNum;
            for(int i = 0; i<NumberTracks; i++){
                int TrackId = i+1;
                InboundTrack temp(TrackId, OutboundTrackNum, TrainIDIncrement);
                TrainIDIncrement++;
            }
        }

        int addTrain(){
            int TrackID = rand() % Tracks.size();
            int length = rand() % 66;
            Train inbound(TrackID, TrainIDIncrement, length);
            TrainIDIncrement++;
            storedTrains.push_back(inbound);
            for (int i = 0; inbound.Cars.size(); i++){
                storedCars.push(inbound.Cars[i]);
            }
            return inbound.Cars.size();
        }
        void removeRailcar(Railcar inbound){
            int temp = std::find(Tracks[inboudn.TrackNumber].storedTrains[0].Cars.start, Tracks[inboudn.TrackNumber].storedTrains[0].Cars.end, inbound);
            Tracks[inbound.TrackNumber].storedTrains[inbound.TrainID].Cars.erase(temp);
            Tracks[inbound.TrackNumber].storedCars.pop;

        }
        void removeTrain(Train inbound){
            Tracks[inbound.TrackNumber].storedTrains.erase(0);
            for (int i = 0; i < Tracks[inbound.TrackNumber].storedCars.size()){
                if(Tracks[inbound.TrackNumber].storedCars[i].TrainID == inbound.TrainID){
                    Tracks[inbound.TrackNumber].storedCars.erase(i);
                }
            }
            //Tracks[inbound.TrackNumber].storedCars.erase(Tracks[inbound.TrackNumber].storedCars.begin());
        }
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

        InboundTrack(int TrackID, int OutboundTrackNumber, int TrainID){
            TrackCapacity = 65;
            outboundTrackNum = OutboundTrackNumber;
            available = 65;
            TrackNumber = ID;
            int chance = rand() % 3;
            int length = rand() % 66;
            if (chance!=0){
                Train inbound(OutboundTrackNumber, TrackNumber, length);
                storedTrains.push(inbound);
                for (int i = 0; inbound.Cars.size(); i++){
                    storedCars.push(inbound.Cars[i]);
                }
                available = available - inbound.Cars.size();
            }
        }

        //update this to accept trains instead of railcars.
        void addRailcars(Train inbound){
            for(int i = 0; i<inbound.Cars.size(); i++){
                if (available > 0){
                    storedCars.push(inbound.Cars[i]);
                    temp = inbound.Cars[i].getTrainID();
                    available =- 1;
                    if (std::count(storedTrains.begin(), storedTrains.end(), temp) < 1){
                        storedTrains.push_back(temp);
                    }
                }
            }
        }
};