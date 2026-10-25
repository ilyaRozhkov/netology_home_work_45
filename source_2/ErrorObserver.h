#pragma once
#include "Observer.h"
#include <string>

class ErrorObserver : public Observer {
public:
    explicit ErrorObserver(std::string filePath);
    void onError(const std::string& message) override;

private:
    std::string filePath_;
};
