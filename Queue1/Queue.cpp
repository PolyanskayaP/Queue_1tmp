#include "Queue.h"
#include "Item.h"
#include "NaslQueue.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

Queue::Queue() {
    first = nullptr;
    last = nullptr;
    size = 0;
}

void Queue::push(int newValue) {
    Item* newItem = new Item(last, newValue);
    last = newItem;
    ++size;
    if (size == 1)
        first = newItem;
}

int Queue::pop() {
    int ExValue;
    if (isempty()) {
        Item* Exfirst = first;
        ExValue = Exfirst->getValue();

        Item* walkItem = last;
        for (int i = 1; i < size - 1; i++)
            walkItem = walkItem->getRecent();

        first = walkItem;
        first->setRecent(NULL);

        delete Exfirst;
        --size;
        if (size == 0) {
            first = NULL;
            last = NULL;
        }
    }
    return ExValue;
}

void Queue::init(int n) {
    time_t timer = time(NULL);
    srand(timer % 50);

    for (int i = 0; i < n; i++) {
        int val = rand() % 1000;
        push(val);
    }

    size = n;
}

void Queue::init(int* a, int n) {
    for (int i = 0; i < n; i++) {
        int val;
        val = *(a + i);
        push(val);
    }
}

int Queue::isempty() {  //empty - 0, not empty - 1  ;(pustoy)
    int f = 1;
    if (last == NULL) f = 0;
    return f;
}

unsigned int Queue::getSize() {
    return size;
}

Queue::~Queue() {
    unsigned int s = size;
    for (int i = 0; i < s; i++) {
        pop();
    }
}
