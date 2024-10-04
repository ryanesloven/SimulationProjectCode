#ifndef DataTracker_h
#define DataTracker_h
class DataTracker{
    std::string FunctionDataStorage;
    std::string OperationDataStorage;
    std::fstream Function;
    std::fstream Operation;
    DataTracker();
    void operationTime(int carsProcessed);
    void functionTime(auto duration);
};
#endif