#include "Logger.h"
#include <fstream>
#include <iostream>

using namespace std;

Logger::Logger() : stepCount(0), enableLogging(true) {
    log["steps"] = json::array();
    log["metadata"] = json::object();
}

void Logger::setLoggingEnabled(bool enabled) {
    enableLogging = enabled;
}

void Logger::logInitialMetadata(const vector<int>& arrayState, int arraySize) {
    log["metadata"]["array_size"] = arraySize;
    log["metadata"]["initial_state"] = arrayState;
}

void Logger::logOperationMetadata(const string& operation, const string& order) {
    json operationMetadata;
    operationMetadata["operation"] = operation;
    operationMetadata["order"] = order;
    log["operations"].push_back(operationMetadata);
}

void Logger::logState(const vector<int>& arrayState, const string& annotation) {
    if (!enableLogging) return;

    json step;
    step["step"] = stepCount++;
    step["array_state"] = arrayState;
    step["annotation"] = annotation;
    log["steps"].push_back(step);
}

void Logger::saveToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << log.dump(4);
        file.close();
        cout << "Log saved to " << filename << endl;
    }
    else {
        cerr << "Error: Unable to save log to " << filename << endl;
    }
}

Logger::~Logger() { saveToFile("output.json"); }
