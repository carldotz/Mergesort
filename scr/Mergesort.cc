/*
 * Mergesort.cc
 *
 *  Created on: Nov 25, 2014
 *      Author: carl
 */

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

const size_t WIDTH = 100;

void mergesort(int *a, size_t size) {

}

void gen_random(int *a, size_t size) {
	for(size_t i=0;i<size;++i) {
		*(a+i) = random()/10000000;
	}
}

void display(int *a, size_t size) {
	for(size_t i=0;i<size;++i) {
		cout << *(a+i) << "\t";
	}
	cout << endl;
}

int main() {
	int *data = NULL;
	data = new int[WIDTH];
	gen_random(data, WIDTH);
	cout << "Before Sort:" << endl;
	display(data, WIDTH);
	mergesort(data, WIDTH);
	cout << "After Sort:" << endl;
	display(data, WIDTH);
	delete [] data;
}



