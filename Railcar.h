#ifndef Railcar_h
#define Railcar_h
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
        int getTrainID();
        int getDestination();
        int getRepairMiles();
        int getPriority();
        int getTrackNumber();
        void Repair();
};
class Train{
    int TrainID;
    int TrackNumber;
    int length;
    int carDestination; 
    int carPrio;
    std::vector<Railcar> Cars;
    Train(int TrackNum, int ID);
};
#endif