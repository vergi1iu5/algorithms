// partition into ceil(n/5) groups
// sort all elements in each group
// get median of each group
// recursive call on group of medians
// return meadian of medians
// partition around median of medians
// if q - p == i, then return median of medians
// else if i < q - p, recurse select partition on array A[p...q]
// else if i > p - q, recurse select and partiotion on A[q+1...r] and (q - p - i)

#include <iostream>
#include <sstream>

using namespace std;

void insertion_sort(int A[], int p, int r){

	int i = p + 1;
	int temp;

	while(i <= r){
		
		for(int j = i - 1; j >= 0; j--){
			if (A[j] > A[i]){
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}else{
				break;
			}
		}
		i++;
	}
}

int partition(int A[], int p, int r, int pivot){

	int i = p - 1;
	int temp;

	for(int j = p; j < r; j++){
		if(A[j] == pivot){
			temp = A[r];
			A[r] = A[j];
			A[j] = temp; 
		}
	}

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

int select(int A[], int p, int r){
	
	if((r - p + 1) <= 2){
		return A[p];
	}

	int n = (r - p + 1)/5;
	if( (r - p + 1 )%5 != 0 ){n++;}
	int S[n];

	//cout << n << endl;

	int i = 0;
	int j = 0;
	int k = 0;

	while(true){

		i = i + 5;
		if(i <= r + 1){
			insertion_sort(A, p + j, i - 1);
			//cout << A[p + j + 2] << endl;
			S[k] = A[p + j + 2];
		}else{
			insertion_sort(A, p + j, r);
			//cout << A[p + j + (r - (p + j))/2] << endl;
			S[k] = A[p + j + (r - (p + j))/2];
		}

		k++;
		j = j + 5;

		if(k >= n){
			return select(S, 0, n - 1);
		}
	}
}

int select_partion(int A[], int p, int r, int i){
	
	int x = select(A, p, r);
	int q = partition(A, p, r, x);
	int k = q - p + 1;

	if(i == k){
		return x;
	}
	if(i < k){
		return select_partion(A, p, q - 1, i);
	}
	if(i > k){
		return select_partion(A, q + 1, r, i - k);
	}

}

int main(){

	int n;
	int i;
	string buffer_str;
	stringstream buffer;

	getline(cin, buffer_str);
	n = stoi(buffer_str);

	buffer_str = "";

	getline(cin, buffer_str);
	i = stoi(buffer_str);

	buffer_str = "";

	getline(cin, buffer_str);
	buffer.str(buffer_str);

	int A[n];

	for(int j = 0; j < n; j++){
		buffer >> A[j];
	}

	int x = select_partion(A, 0, n-1, i);

	cout << x << endl;

	return 0;
}

