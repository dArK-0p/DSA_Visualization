#pragma once
#include <vector>
#include <string>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Logger {
private:
    json log;
    int stepCount;
    bool enableLogging;

public:
    Logger();

    void logInitialMetadata(const vector<int>& arrayState, int arraySize); // Log array size and state
    void logOperationMetadata(const string& operation, const string& order = "N/A"); // Log operation name and order
    void logState(const vector<int>&, const string&);
    void saveToFile(const string&);
    void setLoggingEnabled(bool);

    ~Logger();
};
