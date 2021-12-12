#pragma once
class Item
{
private:
    int value;
    Item* recent;

public:
    Item(Item* recentItem = nullptr, int newValue = 0);

    Item* getRecent();
    void setRecent(Item*);
    int getValue();
    void setValue(int newValue);
    int& getValueAddress();
};

