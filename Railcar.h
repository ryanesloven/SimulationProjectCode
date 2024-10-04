#ifndef Railcar_h
#define Railcar_h
class Train{
    public:
        int TrainID;
        int TrackNumber;
        int length;
        int carDestination; 
        int carPrio;
        int TotalPriority;
        std::queue<Railcar> Cars;
        int Destinations[];
        Train(int TrackID, int TrainID, int len);
};

class Railcar{
    int RailcarID;
    int Destination;
    int Priority;
    int TrackNumber;
    int RepairMiles;
    int IDTrack;
    int TrainID;
    bool status;

    public:
        Railcar(int Dest, int Prio, int TrackNum, int ID);
        int getTrainID();
        int getDestination();
        int getPriority();
        int getTrackNumber();
        int getRepairMiles();
        void Repair();
    
};
#endif