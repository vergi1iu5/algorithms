#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void merge(int A[], int p, int q, int r);

void merge_sort(int A[], int p, int r);

int main(){

	int p, r;
	string buffer_str;
	stringstream buffer;
	getline(cin, buffer_str);

	buffer.str(buffer_str);

	buffer >> r;
	p = 1;

	int A[r + 1];
	for (int i = 0; i < r + 1; i++){
		buffer >> A[i];
	}
	
	merge_sort(A, p, r); 

	for(int i = 0; i < r; i++){
        cout << A[i] << endl;
	}

	return 0;
}

void merge_sort(int A[], int p, int r){

    if (p < r){
        int q = ((p + r) / 2);
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void merge(int A[], int p, int q, int r){

	int L[q - p + 2];
	int R[r - q + 1];

	for(int i = 0; i < q - p + 1; i++){
		L[i] = A[p + i - 1];
	}
	for(int i = 0; i < r - q; i++ ){
        R[i] = A[q + i];
	}

	L[q - p + 1] = 100;
	R[r - q] = 100;

	int i, j, k;
	i = 0;
	j = 0;
	k = p - 1;

	while(k < r){
		if (L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
		k++;
	}
}
