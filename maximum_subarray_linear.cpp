// while true
// 		low = 0
//		high = 0
// 		moving_sum = -100;
// 		for k from low to right
//			sum = sum + A[i]
//      	if sum > moving_sum:
//				moving_sum = sum
//				high = k;
// 		find max array of A[0..high + 1]
// 			moving_sum = -100;
// 			sum = 0;
// 			low = 0;
// 			for every i in j + 1 downto 0
//				sum = sum + A[i]
//      		if sum > moving_sum:
//					moving_sum = sum
//					low = i;
//			return low, moving_sum
//		if low did not change: break

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

std::vector<int> max_low_right(int A[], int low, int right){
	
	int moving_sum = -100;
	int high = 0;
	int sum = 0;

	for(int i = low; i <= right; i++){
		sum = A[i] + sum;
		if (sum > moving_sum){
			moving_sum = sum;
			high = i;
		}
	}

	return {high, moving_sum};
}

std::vector<int> max_high_left(int A[], int left, int high, int right){
	
	int moving_sum = -100;
	int low = 0;
	int sum = 0;
	int lim;

	if (high + 1 > right){
		lim = high;
	}else{
		lim = high + 1;
	}
	
	for(int i = lim; i >= left; i--){
		sum = A[i] + sum;
		if (sum > moving_sum){
			moving_sum = sum;
			low = i;
		}
	}

	return {low, moving_sum};
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
	int moving_sum = -100;
	int high

	for(int j = 0; j <= right; j++){
		std::vector <int> result1 = max_low_right(A, left, j);
		std::vector <int> result2 = max_high_left(A, left, j, right);

		if (result2[1] >= result1[1]){
			if (result2[1] > moving_sum){
				moving_sum = result2[1];
				high = j + 1;
				left = result2[0];
			}
		}
	}

	cout << left << endl;
	cout << high << endl;
	cout << moving_sum << endl;
	return 0;
}