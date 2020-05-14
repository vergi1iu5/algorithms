#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){

	int n, i, j, key;
	stringstream buffer;
	string buffer_str;

	getline(cin, buffer_str);
	buffer.str(buffer_str);

	buffer >> n;
	int A[n];
	i = 0;

	while(i < n){
		buffer >> key;
		A[i] = key;
		for(int j = i - 1; j >= 0; j--){
			if (A[j] > key){
				A[j + 1] = A[j];
				A[j] = key;
			}else{
				break;
			}
		}
		i++;
	}

	for(int i = 0; i < n; i++){
		cout << A[i] << ' ';
	}

	return 0;
}