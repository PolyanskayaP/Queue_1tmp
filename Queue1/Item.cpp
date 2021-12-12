#include "Item.h"
#include "NaslQueue.h"
#include "Queue.h"

Item::Item(Item* recentItem, int newValue) {
    recent = recentItem;
    value = newValue;
}

Item* Item::getRecent() {
    return recent;
}

void Item::setRecent(Item* recentItem) {
    recent = recentItem;
}

int Item::getValue() {
    return value;
}

void Item::setValue(int newValue) {
    value = newValue;
}
