
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int hoare_partition(int A[], int p, int r){

	int pivot = A[p];

	int i = p - 1;
	int j = r + 1;

	int temp;

	while(true){
		do{
			j--;
		}while(A[j] > pivot);

		do{
			i++;
		}while(A[i] < pivot);

		if(i < j){
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}else{
			return j;
		}
	}
}

int partition(int A[], int p, int r){
	int pivot = A[r];

	int i = p - 1;
	int temp;

	for(int j = p; j < r; j++){
		if (A[j] < pivot){
			i++;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}

	A[r] = A[i + 1];
	A[i + 1] = pivot;

	return i + 1;
}

void quick_sort(int A[], int p, int r){
	
	int q;

	if (p < r){
		q = hoare_partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}

int main(){

	int n;
	string buffer_str;
	stringstream buffer;

	getline(cin, buffer_str);
	n = stoi(buffer_str);

	buffer_str = "";

	getline(cin, buffer_str);
	buffer.str(buffer_str);

	int A[n];

	for(int i = 0; i < n; i++){
		buffer >> A[i];
	}

	quick_sort(A, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << endl;
	}


}