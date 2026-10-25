#include <iostream>
#include <memory>

#include "FatalErrorHandler.h"
#include "ErrorHandler.h"
#include "WarningHandler.h"
#include "UnknownHandler.h"

int main() {
    auto fatal   = std::make_shared<FatalErrorHandler>();
    auto error   = std::make_shared<ErrorHandler>("errors.log");
    auto warning = std::make_shared<WarningHandler>();
    auto unknown = std::make_shared<UnknownHandler>();

    fatal->setNext(error);
    error->setNext(warning);
    warning->setNext(unknown);

    fatal->handle(LogMessage(Type::Warning, "Low disk space"));

    fatal->handle(LogMessage(Type::Error, "Cannot connect to DB"));

    try {
        fatal->handle(LogMessage(Type::FatalError, "Out of memory"));
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    try {
        fatal->handle(LogMessage(Type::Unknown, "???"));
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}
