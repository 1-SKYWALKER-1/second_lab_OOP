#ifndef OBS_H
#define OBS_H
#include <QStringList>
class Obs{

private:
    QStringList data;
    std::function<void(const QStringList&)> update;
    bool shouldSort = false;
public:
    Obs(std::function<void(const QStringList&)> update);
    void removeItem(const QString& item);
    void replaceItem(const QString& oldItem, const QString& newItem);
    void addItem(const QString& item);
    void removeAll();
    void insertAt(const QString& newItem, const QString& oldItem);
    void sort();
};

#endif // OBS_H
