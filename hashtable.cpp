#include <iostream>
#include "linked_list.h"

using namespace std;

/////////////////////////////////////////////////////////////
struct node_hash{
 	LinkedList * chain;
 	int node_key;
};
/////////////////////////////////////////////////////////////
class Hashtable{
private:

	int BUCKETS;
	int (*hashFucntion) (int, int);
	LinkedList * table;

public:

	Hashtable(){
		this->BUCKETS = 0;
		hashFucntion = nullptr;
		table = nullptr;
	}

	Hashtable(int size, int (*h) (int, int)){
		
		this->BUCKETS = size;
		hashFucntion = h;

		table = new LinkedList[size];
	}

	void Insert(int key, int data){

		int k = hashFucntion(key, BUCKETS);
		table[k].insert_node(data, key);
	}

	int get_data(int key_data){

		int k = hashFucntion(key_data, BUCKETS);
		node * chain_node = table[k].head;
		
		while(chain_node->next != nullptr && chain_node->key != key_data){
			chain_node = chain_node->next;
		}

		return chain_node->data;
	}
};
////////////////////////////////////////////////////////////////
int basic_hash(int key, int num_buckets){
	return key % num_buckets;
}
////////////////////////////////////////////////////////////////
int main(){

	int (*foo)(int k, int b);

	foo = &basic_hash;

	Hashtable test(5, foo);

	test.Insert(2, 9);
	test.Insert(3, 12);
	//test.Insert(3, 10);
	//test.Insert(3, 12);

	cout << test.get_data(2) << endl;
	cout << test.get_data(3) << endl;

	return 0;
}