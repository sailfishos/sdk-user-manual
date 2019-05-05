#include "counter-06.h"

Counter * Counter::instance = nullptr;

void Counter::instantiate(QObject *parent) {
    if (instance == nullptr) {
        instance = new Counter(parent);
    }
}

Counter & Counter::getInstance() {
    return *instance;
}

QObject * Counter::provider(QQmlEngine *, QJSEngine *) {
    return instance;
}
