// Queue1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//66. Указатели Очередь головой и хвостом Простой выбор
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "NaslQueue.h"
#include "Queue.h"
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    //const int KolEl = 7;
    //int ProvMas[KolEl]{ 3, -2, 9, 5, 1, 3, 0 };
    unsigned int qsize; 
    NaslQueue myQueue;

    //myQueue.init(ProvMas, KolEl);
    myQueue.init(100);

    qsize = myQueue.getSize();
    std::cout << "elements in queue: " << std::endl;
    for (unsigned int i = 0; i < qsize; i++) {
        std::cout << myQueue.get(i) << " ";
    }
    cout<<endl;

    system_clock::time_point start = system_clock::now();
    myQueue.sort();
    system_clock::time_point end = system_clock::now();
    duration<double> sec = end - start;

    qsize = myQueue.getSize();
    std::cout << "sorted elements in queue: " << std::endl;
    for (unsigned int i = qsize; i > 0; --i) {
        std::cout << myQueue.pop() << " ";
    }
    cout<<endl;

    cout << "sort time: " << sec.count() << endl;
    return 0;
}

