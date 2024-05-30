#include "obs.h"

Obs::Obs(std::function<void(const QStringList&)> update) {
    this->update = update;
    data <<"first_element(1)"<<"second_element(2)"<<"third_element(3)"<<"fourth_element(4)"
         <<"five_element(5)"<<"six_element(6)"<<"seven_element(7)"<<"eight_element(8)"
         <<"nine_element(9)"<<"ten_element(10)";
    update(data);
}

void Obs::removeItem(const QString& item) {
    data.removeOne(item);
    update(data);
}
void Obs::replaceItem(const QString& oldItem, const QString& newItem) {
    if (newItem.isEmpty()) return;
    int index = data.indexOf(oldItem);
    if (index != -1) {
        data.replace(index, newItem);
        update(data);
    }
}

void Obs::addItem(const QString& item) {
    if (item.isEmpty()) return;

    data.append(item);

    if (shouldSort) data.sort();

    update(data);
}

void Obs::insertAt(const QString& newItem, const QString& oldItem) {
    int position = data.indexOf(oldItem);

    data.resize(data.size() + 1);

    for(int i = data.size() - 1; i > position; i--) {
        data[i] = data[i - 1];
    }
    data[position] = newItem;

    update(data);
}

void Obs::sort() {
    data.sort();
    shouldSort = true;
    update(data);
}

void Obs::removeAll() {
    if (data.empty()) return;
    data.clear();
    update(data);
}
