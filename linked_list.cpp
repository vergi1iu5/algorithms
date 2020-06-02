#include <iostream>
#include <sstream>

using namespace std;
////////////////////////////////////////////////////////////////////////////
class node{

	public:

		int key;
		node * next, * prev;

		void * p;

		node();
		node(int, void*, int);
		void operator= (const node);

		//node Next(){return next;}
		//node Prev(){return prev;}
		int Key(){return key;}
};

node::node(){
	next = nullptr;
	prev = nullptr;
	key = 0;
	p = nullptr;
}

node::node(int k, void* data, int psize){

	next = nullptr;
	prev = nullptr;
	
	if(psize == sizeof(char)){
		p = (char*) data;
	}else if(psize == sizeof(int)){
		p = (int*) data;
	}else{
		p = nullptr;
	}

	key = k;

}
/////////////////////////////////////////////////////////////////////////////
class linked_list{

public:

	node * head, * tail;

	linked_list();
	linked_list(node h);
};

linked_list::linked_list(){
	
	head = nullptr;
	tail = nullptr;

}

linked_list::linked_list(node h){

	h.prev = nullptr;
	h.next = nullptr;

	head = &h;
	tail = &h;

}
//////////////////////////////////////////////////////////////////////////////

void List_Insert(linked_list L, node x){

	x.next = L.head;

	if(L.head != nullptr){
		(*(L.head)).prev = &x;
	}

	L.head = &x;
	x.prev = nullptr;
}

void List_Delete(linked_list L, node x){

	if (x.prev != nullptr){
		(*(x.prev)).next = x.next;
	}else{
		L.head = x.next;
	}

	if (x.next != nullptr){
		(*(x.next)).prev = x.prev;
	}

}
////////////////////////////////////////////////////////////////////////////////
int main(){

	char a = 'a';
	char b = 'b';

	char * ap = &a;
	char * bp = &b;

	int psize = sizeof(a);

	node node_1(1, ap, psize);
	node node_2(2, bp, psize);

	linked_list L;

	List_Insert(L, node_1);
	List_Insert(L, node_2);

	List_Delete(L, node_2);

	cout << *((*(L.head)).p) << endl;

}