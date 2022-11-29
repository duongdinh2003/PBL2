#ifndef Linked_List_h
#define Linked_List_h
#include "ThucPham.h"

class Node : public Food {
public:
	Food data;
	Node* link;
	Node();
	Node(Food f);
	~Node();
};

class List {
public:
	Node* head;
	Node* tail;
	List();
	List(string file);
	~List();
	void insert_tail(Food f);
	void Display();
};
#endif