#pragma once
#include <set>
#include <string>

class Observable;

class Observer {
public:
    virtual ~Observer();

    virtual void onWarning(const std::string& /*message*/) {}
    virtual void onError(const std::string& /*message*/) {}
    virtual void onFatalError(const std::string& /*message*/) {}

protected:
    friend class Observable;

    void attachTo(Observable* observable) { observables_.insert(observable); }
    void detachFrom(Observable* observable) { observables_.erase(observable); }

private:
    std::set<Observable*> observables_;
};
