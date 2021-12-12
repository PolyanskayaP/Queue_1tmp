#pragma once
#include "Queue.h"
class NaslQueue :
    public Queue
{
public:
	~NaslQueue();
	int get(unsigned int);
	void set(int, unsigned int);
	void sort();
};

