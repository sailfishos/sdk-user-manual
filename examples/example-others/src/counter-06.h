#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QQmlEngine>

class Counter: public QObject {
    Q_OBJECT
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
public:
    Counter(QObject * parent = 0) : QObject(parent), m_count(0) {};
    int count() { return m_count; };
    void setCount(int count) {
        if (m_count != count) { m_count = count; emit countChanged(); }
    }
signals:
    void countChanged();
private:
    int m_count;
public:
    static void instantiate(QObject *parent = nullptr);
    static Counter & getInstance();
    static QObject * provider(QQmlEngine *, QJSEngine *);
private:
    static Counter * instance;
};

#endif // COUNTER_H
