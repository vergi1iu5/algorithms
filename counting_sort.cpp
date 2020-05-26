// create C with k elements. 
// include into C[i] all the elements equal to i in A
// turn C[i] into num of elemts <= i in A
// place A[i] into the corresponding place in B (C[A[i]])
// decrement C[i] by one in case there are values equal to i in A

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void counting_sort(int A[], int B[], int k, int n){
	// create temporary working array
	int C[k + 1];
	// clear C to make sure correct initial working conditions
	for(int i = 0; i <= k; i++){
		C[i] = 0;
	}
	// include into C[i] all the elements equal to i in A
	for(int i = 0; i < n; i++){
		C[A[i]]++;
	}
	// running sum of C
	for(int i = 1; i <= k; i++){
		C[i] = C[i] + C[i - 1];
	}

	// place A[i] into correct place in B[i]
	for(int i = n - 1; i >= 0; i--){
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}

int main(){

	int n, k;
	string buffer_str;
	stringstream buffer;

	getline(cin, buffer_str);
	n = stoi(buffer_str);

	buffer_str = "";

	getline(cin, buffer_str);
	k = stoi(buffer_str);

	buffer_str = "";

	getline(cin, buffer_str);
	buffer.str(buffer_str);

	int A[n];
	int B[n];

	for(int i = 0; i < n; i++){
		buffer >> A[i];
	}

	counting_sort(A, B, k, n);

	for (int i = 0; i < n; i++)
	{
		cout << B[i] << endl;
	}
}