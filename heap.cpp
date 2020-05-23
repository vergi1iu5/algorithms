
// My implementation of a heap data structure
// Comes with a few helper functions to fully utilize the convenience
// of a heap structure

#include <iostream>
#include <exception>

using namespace std;

// Exceptions definitions
class indx: public exception
{
  virtual const char* what() const throw()
  {
    return "index outside heap size";
  }
} myex_indx;

class heap_type: public exception
{
  virtual const char* what() const throw()
  {
    return "Wrong heap type used";
  }
} myex_type;

class heap_type_creation: public exception
{
  virtual const char* what() const throw()
  {
    return "Heap type specified not valid";
  }
} myex_type_creation;

// Class header
class heap{

	int * p;

	public:
		int h_size, a_size;
		char type;

		heap(int, int[], int, char);
		
		int length() {return a_size;}

		int heap_size() {return h_size;}

		int& operator[] (const int);	
};

heap::heap(int a, int A[], int h, char t){
	h_size = h;
	a_size = a;
	p = A;

	if (t == 'x' or t == 'n'){
		type = t;
	}else{
		throw myex_type_creation;
	}
}

int& heap::operator[] (const int i){
	
	if (a_size < i){
		throw myex_indx;
	}

	return *(p + i); 

}

// Helper functions

int left(int i) {

	if(i == 0){
		return 1;
	}else{
		return i*2 + 1;
	}

}

int right(int i) {return i*2 + 2;}

int parent(int i) {

	if(i%2 == 1 && i >= 1){
		return i/2;
	}else{
		return i/2 - 1;
	}
}

void max_heapify(heap A, int i){
	
	if(A.type == 'n'){
		throw myex_type;
	}
	
	int l = left(i);
	int r = right(i);
	int max = i;

	if(l < A.heap_size() and A[l] > A[i]){
		max = l;
	}

	if(r < A.heap_size() and A[r] > A[max]){
		max = r;
	}

	if(max != i){
		int temp = A[i];
		A[i] = A[max];
		A[max] = temp;
		max_heapify(A, max);
	}
}

void min_heapify(heap A, int i){

	if(A.type == 'x'){
		throw myex_type;
	}

	int l = left(i);
	int r = right(i);
	int min = i;

	if(l <= A.heap_size() and A[l] < A[i]){
		min = l;
	}

	if(r <= A.heap_size() and A[r] < A[min]){
		min = r;
	}

	if(min != i){
		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;
		min_heapify(A, min);
	}
}

heap build_max_heap(int A[], int az){

	int hz = az;

	heap h (az, A, hz, 'x');

	for(int i = h.length()/2; i >= 0; i--){
		max_heapify(h, i);
	}

	return h;

}

void heap_sort(heap A){

	int temp;
	for(int i = A.heap_size() - 1; i >= 1; i--){
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		A.h_size = A.h_size - 1;
		max_heapify(A, 0);
	}

}

// Test

int main(){

	int A[] = {10, 5, 87, 9, 6, 7, 23, 3, 4, 7};
	int heap_size = 10;
	int array_size = 10;

	heap h = build_max_heap(A, array_size);

	try{
		h[12];
	}
	catch (exception& e){
		cout << e.what() << endl;
	}

	return 0;

}