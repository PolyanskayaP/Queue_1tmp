#include "NaslQueue.h"
#include "Item.h"
#include "Queue.h"

int NaslQueue::get(unsigned int pos) {  //pozitsiya s 0lya
	unsigned int size = getSize();
	int result = 0;
	int i, tempValue;

	for (i = 0; i <= pos; i++) {
		result = pop();
		push(result);
	}//result==a[pos]

	for (i = 1; i < size - pos; i++) {
		tempValue = pop();
		push(tempValue);
	}

	return result;
}

void NaslQueue::set(int newValue, unsigned int pos) {
	unsigned int size = getSize();
	int i, tempValue;

	for (i = 0; i < pos; i++) {
		tempValue = pop();
		push(tempValue);
	}

	pop();
	push(newValue);

	for (i = 1; i < size - pos; i++) {
		tempValue = pop();
		push(tempValue);
	}
}

void NaslQueue::sort() {
	unsigned int size = getSize();
	int i, j, min, temp;
	for (i = 0; i < size - 1; i++) {
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (get(j) < get(min))
				min = j;
		}

		temp = get(i); //temp = a[i]; 
		set(get(min), i); //a[i] = a[min];  
		set(temp, min); //a[min] = temp;     
	}
}

NaslQueue::~NaslQueue() {
	unsigned int s = getSize();
	for (int i = 0; i < s; i++) {
		pop();
	}
}
