#include <random>
#include <vector>
#include "OutboundYard.h"
#include "Driver.h"

class Train{
    public:
        int TrainID;
        int TrackNumber;
        int length;
        int carDestination; 
        int carPrio;
        int TotalPriority = 0;
        std::queue<Railcar> Cars;
        int Destinations[];
        Train(int TrackID, int TrainID, int len){
            length = len;
            Destinations[TrackNum];
            for(int i = 0; i < length; i++){
                carDestination = rand() % TrackNum;
                carPrio = rand() % 4;
                Destinations[carDestination] +=1;
                TotalPriority = TotalPriority + carPrio;
                Railcar temp(carDestination, carPrio, TrackID, TrainID);
                Cars.push(temp);
            }
            TrainID = ID;

        }
};

class Railcar{
    int RailcarID;
    int Destination;
    int Priority;
    int TrackNumber;
    int RepairMiles;
    int IDTrack = 1;
    int TrainID;
    bool status = true;

    public:
        Railcar(int Dest, int Prio, int TrackNum, int ID){
            RailcarID = IDTrack;
            IDTrack++;
            Destination = Dest;
            Priority = Prio;
            RepairMiles = rand() %1150;
            TrainID = ID;
            TrackNumber = TrackNum;
        }
        int getTrainID(){
            return TrainID;
        }
        int getDestination(){
            return Destination;
        }
        int getPriority(){
            return Priority;
        }
        int getTrackNumber(){
            return TrackNumber;
        }
        int getRepairMiles(){
            return RepairMiles;
        }
        //have function set status/availability to false for specific amount of time.
        void Repair(){
            status = false;
        }
    
};