#include <iostream>
#include <sstream>

using namespace std;
////////////////////////////////////////////////////////////////////////////
struct node{
	node * next, * prev;
	int data;
	int key;
};
/////////////////////////////////////////////////////////////////////////////
class linked_list{
	
private:
	node * head, * tail;
	int length;
public:
	
	linked_list(){
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	void insert_node(int d, int k){
		node * temp = new node;

		temp->next = head;
		temp->prev = nullptr;
		temp->data = d;
		temp->key = k;

		if(head != nullptr){
			head->prev = temp;
		}

		head = temp;
		length++;
	}

	int delete_node(int k){

		node * temp = head;

		while(true){
			if (temp != nullptr && temp->key == k){
				
				if(temp->prev != nullptr){
					temp->prev->next = temp->next;
				}else{
					head = temp->next;
				}

				if(temp->next != nullptr){
					temp->next->prev = temp->prev;
				}

				return 0;

			}else if(temp->next != nullptr){
				temp = temp->next;
			}else{
				return 1;
			}
		}
	}

	int pop(int k){

		node * temp = head;

		while(true){
			if (temp != nullptr && temp->key == k){
				int save = temp->data;
				delete_node(temp->key);
				return save;
			}else if(temp->next != nullptr){
				temp = temp->next;
			}else{
				return 0;
			}
		}
	}
};
////////////////////////////////////////////////////////////////////////////////
int main(){

	linked_list L;

	L.insert_node(1, 22);
	L.insert_node(2, 33);

	cout << L.delete_node(22) << endl;
	cout << L.pop(22) << endl;


}