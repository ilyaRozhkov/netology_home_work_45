#include "Observable.h"
#include "Observer.h"
#include <algorithm>

Observable::~Observable() {
    for (auto* observer : observers_) {
        observer->detachFrom(this);
    }
}

void Observable::addObserver(Observer* observer) {
    if (!observer) return;
    if (std::find(observers_.begin(), observers_.end(), observer) != observers_.end())
        return;
    observers_.push_back(observer);
    observer->attachTo(this);
}

void Observable::removeObserver(Observer* observer) {
    auto it = std::find(observers_.begin(), observers_.end(), observer);
    if (it != observers_.end()) {
        observers_.erase(it);
        observer->detachFrom(this);
    }
}

void Observable::warning(const std::string& message) const {
    for (auto* observer : observers_) observer->onWarning(message);
}

void Observable::error(const std::string& message) const {
    for (auto* observer : observers_) observer->onError(message);
}

void Observable::fatalError(const std::string& message) const {
    for (auto* observer : observers_) observer->onFatalError(message);
}
