#include <random>
#include <vector>
#include "OutboundYard.h"

class Train{
    int TrainID;
    int TrackNumber;
    int length;
    int carDestination; 
    int carPrio;
    std::vector<Railcar> Cars;
    Train(int TrackNum, int ID, OutboundYard Accessor){
        for(int i = 0; i < length; i++){
            carDestination = rand() % Accessor.getNumberTracks();
            carPrio = rand() % 4;
            Railcar temp(carDestination, carPrio, TrackNumber, ID);
            Cars.push_back(temp);
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