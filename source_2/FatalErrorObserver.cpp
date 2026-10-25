#include "FatalErrorObserver.h"
#include <fstream>
#include <iostream>
#include <utility>

FatalErrorObserver::FatalErrorObserver(std::string filePath)
    : filePath_(std::move(filePath)) {}

void FatalErrorObserver::onFatalError(const std::string& message) {
    std::cout << "[FATAL] " << message << std::endl;

    std::ofstream out(filePath_, std::ios::app);
    if (out) out << "[FATAL] " << message << '\n';
}
