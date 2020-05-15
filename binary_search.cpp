// Assume array is sorted qith A[0...q]
// p = 0;
//	move_indexes(A, p, q, v)
// 		if A[q/2] > v
//			return p, q/2
//		if A[q/2] < v
//			return q/2, q
//		else
//			return q, q
//		
//	binary_search(A, p, q, v)
//		if p == q
//			if A[p] == v
//				return p
//		 	else
//				return -1
//		else
//			p, q = move_indexes(A, p, q, v)
//			binary_search(A, p, q, v)
//		 
//			
//			

#include <iostream>
#include <vector>

using namespace std;

int binary_search(int A[], int p, int q, int v){
	if (p <= q){
		cout << p << q << endl;
		int mid = (p + q) / 2;
		 if(A[mid] == v){
		 	return mid;
		 }
		 if (A[mid] > v){
		 	return binary_search(A, p, mid - 1, v);
		 }else{
		 	return binary_search(A, mid + 1, q, v);
		 }
	}else{
		return -1;
	}
}

int main(){
	
	int A[] = {0,1,2,3,4,5,6,7,8,9,10,11};
	int p = 0;
	int q = 11;

	int v;

	cin >> v;

	int i = binary_search(A, p, q, v);

	cout << i << endl;

	return	0;
}