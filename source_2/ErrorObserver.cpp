#include "ErrorObserver.h"
#include <fstream>
#include <utility>

ErrorObserver::ErrorObserver(std::string filePath)
    : filePath_(std::move(filePath)) {}

void ErrorObserver::onError(const std::string& message) {
    std::ofstream out(filePath_, std::ios::app);
    if (out) out << "[ERROR] " << message << '\n';
}
