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

	int lenght;
	int (*hashFucntion) (int);
	node_hash * array;
	int * keys;

public:

	Hashtable(){
		int lenght = 0;
		hashFucntion = nullptr;
	}

	Hashtable(int size, int (*h) (int), int node_keys[]){
		
		lenght = size;
		hashFucntion = h;

		node_hash A[size];
		array = A;

		for(int i = 0; i < size; i++){
			(array + i)->chain = nullptr;
			(array + i)->node_key = node_keys[i];
		}
	}

	void Insert(int key, int data){
		int k = hashFucntion(key);
		node_hash * temp_node = (array + k);

		if (temp_node->chain == nullptr){
			LinkedList * tempList = new LinkedList;
			temp_node->chain = tempList;
		}

		temp_node->chain->insert_node(data, key);
	}

	int get_data(int key_data){

		int k = hashFucntion(key_data);
		node * temp = (array + k)->chain->head;
		
		while(temp->next != nullptr && temp->key != key_data){
			temp = temp->next;
		}

		return temp->data;
	}
};
////////////////////////////////////////////////////////////////
int basic_hash(int key){
	return key;
}
////////////////////////////////////////////////////////////////
int main(){

	int (*foo)(int k);

	foo = &basic_hash;

	int keys[] = {1,2,3,4,5};

	Hashtable test(5, foo, keys);

	test.Insert(2, 7);

	cout << test.get_data(2) << endl;

	return 0;
}