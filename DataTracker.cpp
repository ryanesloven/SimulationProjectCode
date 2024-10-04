#include<string>
#include<chrono>
#include <fstream>
class DataTracker{
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
        Operation << "Cars Processed: " << carsProcessed << "\n";
    }
    void functionTime(auto duration){
        Function << "Classification Time: "<<duration.count() << " milliseconds\n";
    }
};