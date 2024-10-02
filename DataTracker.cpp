#include<string>
#include<chrono>
#include <fstream>
class DataTracker{
    double Time = 0;
    std::string FunctionDataStorage = "FunctionDataStore.txt";
    std::string OperationDataStorage = "OperationDataStore.txt";
    std::fstream Function;
    std::fstream Operation;
    DataTracker(){
        Function.open(FunctionDataStorage);
        Operation.open(OperationDataStorage);
    }
    void operationTime(int carsProcessed){
        Time = Time + carsProcessed * 10;
    }
    void functionTime(auto duration){
        Function << duration.count() << " milliseconds\n";
        Time = Time + duration.count() / 1000;
    }
    double getCurrentTime(){
        return Time;
    }
    void updateDataStorage(){
         
    }
};