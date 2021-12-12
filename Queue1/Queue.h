#pragma once
#include "Item.h"

class Queue
{
private:
    Item* first;
    Item* last;
    unsigned int size;

public:
    Queue();
    ~Queue();
    void init(int);
    void init(int*, int);
    void push(int);
    int pop();
    int isempty();
    unsigned int getSize();
};

