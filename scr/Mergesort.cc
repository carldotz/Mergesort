/*
 * Mergesort.cc
 *
 *  Created on: Nov 25, 2014
 *      Author: carl
 */

#include <iostream>
#include <stdlib.h>
#include <cstring>

using std::cout;
using std::endl;

const size_t WIDTH = 100;

void mergesort(int *a, size_t size) {
	if(size==1) return;
	size_t point = size%2? size/2+1 : size/2;
	mergesort(a, point);
	mergesort(a+point, size-point);
	size_t i=0, j=point, k=0;
	int *t = new int[size];
	while(k<size) {
		if((i<point) && (j<size)) t[k++] = a[i] > a[j] ? a[j++] : a[i++];
		else if(j>=size) t[k++] = a[i++];
		else if(i>=point) t[k++] = a[j++];
	}
	for(size_t i=0;i<size;++i) a[i] = t[i];
	delete [] t;
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



