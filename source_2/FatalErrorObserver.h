#pragma once
#include "Observer.h"
#include <string>

class FatalErrorObserver : public Observer {
public:
    explicit FatalErrorObserver(std::string filePath);
    void onFatalError(const std::string& message) override;

private:
    std::string filePath_;
};
