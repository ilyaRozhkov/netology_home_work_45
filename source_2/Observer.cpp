#include "Observer.h"
#include "Observable.h"

Observer::~Observer() {
    auto copy = observables_;
    for (auto* observable : copy) {
        observable->removeObserver(this);
    }
}
