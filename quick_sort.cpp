
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

void partition(int A[], int p, int r, int results[]){
	int pivot = A[r];

	int i = p - 1;
	int t = i;
	int temp;

	for(int j = p; j < r; j++){
		
		if (A[j] < pivot){
			i++;
			t++;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}

		if(A[j] == pivot){
			t++;
			temp = A[j];
			A[j] = A[t];
			A[t] = temp;
		}
	}

	A[r] = A[i + 1];
	A[i + 1] = pivot;

	results[0] = i + 1;
	results[1] = t;
	
}

void quick_sort(int A[], int p, int r){
	
	int indx[2];

	if (p < r){
		partition(A, p, r, indx);
		quick_sort(A, p, indx[0] - 1);
		quick_sort(A, indx[1] + 1, r);
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