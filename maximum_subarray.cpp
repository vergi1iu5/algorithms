// Take in A, left index and right index
// if left index == right index, just return A[left index]
// calculate mid point
// find max of left array, right array and crossing subarray
// finding max of left and right is what creates reacurrence

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

std::vector<int> mid_max(int A[], int left, int right, int mid){
	
	int left_sum = -100;
	int sum = 0;
	int mid_low, mid_high;

	for(int i = mid; i >= left; i--){
		sum = sum + A[i];
		if (sum > left_sum){
			left_sum = sum;
			mid_low = i;
		}
	}
	
	int right_sum = -100;
	sum = 0;
	
	for(int i = mid + 1; i <= right; i++){
		sum = sum + A[i];
		if (sum > right_sum){
			right_sum = sum;
			mid_high = i;
		}
	}

	return {mid_low, mid_high, left_sum + right_sum};

}

std::vector <int> sub_max(int A[], int left, int right){

	if (left == right){
		return {left, right, A[left]};
	}else{
		
		int mid = (left + right) / 2; 
		std::vector <int> left_out = sub_max(A, left, mid);
		std::vector <int> right_out = sub_max(A, mid + 1, right);
		std::vector <int> mid_out = mid_max(A, left, right, mid);

		if (left_out[2] > right_out[2] &&
			left_out[2] > mid_out[2]){

			return {left_out[0], left_out[1], left_out[2]};

		}else if(right_out[2] > left_out[2] &&
				 right_out[2] > mid_out[2]){

			return {right_out[0], right_out[1], right_out[2]};

		}else{

			return {mid_out[0], mid_out[1], mid_out[2]};

		}
	}
}

int main(){

	int left, right, mid, n;
	string buffer_str;
	stringstream buffer;
	
	// Get number of elements
	getline(cin, buffer_str);
	n = stoi(buffer_str);
	buffer_str = "";
	int A[n];
	
	// Populate array
	getline(cin, buffer_str);
	buffer.str(buffer_str);
	for(int i = 0; i < n; i++){
		buffer >> A[i];
	}
	
	left = 0;
	right = n - 1;
	mid = (left + right) / 2;

	// Initiate reacurrance
	std::vector <int> result = sub_max(A, left, right);

	// Display results
	cout << result[0] << endl;
	cout << result[1] << endl;
	cout << result[2] << endl;

	return 0;
}