#pragma once
#include <string>
#include <vector>

class Observer;

class Observable {
public:
    ~Observable();

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);

    void warning(const std::string& message) const;
    void error(const std::string& message) const;
    void fatalError(const std::string& message) const;

private:
    std::vector<Observer*> observers_;
};
