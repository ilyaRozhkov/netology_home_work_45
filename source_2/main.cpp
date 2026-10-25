#include "Observable.h"
#include "WarningObserver.h"
#include "ErrorObserver.h"
#include "FatalErrorObserver.h"

int main() {
    Observable logger;

    {
        WarningObserver  warning;
        ErrorObserver    error("errors.log");
        FatalErrorObserver fatal("fatal.log");

        logger.addObserver(&warning);
        logger.addObserver(&error);
        logger.addObserver(&fatal);

        logger.warning("Низкий уровень заряда");
        logger.error("Ошибка сети");
        logger.fatalError("Падение ядра");
    } 

    logger.warning("Никто не слушает");

    return 0;
}
