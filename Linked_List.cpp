#include "Linked_List.h"
#include "ThucPham.h"
#include <string>
#include <iostream>
using namespace std;

Node::Node()
{

}
Node::Node(Food f)
{
	this->data = f;
	this->link = NULL;
}
Node::~Node()
{

}
List::List()
{
	this->head = this->tail = NULL;
}
List::List(string file)
{
	fstream filein;
	filein.open(file, ios_base::in);
	Node* n = this->head;
	while (!filein.eof() && n)
	{
		n->data.Input();
		insert_tail(n->data);
		n = n->link;
	}
/*	for (Node* n = this->head; n; n = n->link)
	{
		n->data.Input();
		List::insert_tail(n->data);
	}*/
	filein.close();
}
List::~List()
{

}
void List::insert_tail(Food f)
{
	Node* n = new Node(f);
	if (!n)
	{
		cout << "\nLoi khong the tao node!" << endl;
		return;
	}
	if (this->head == NULL)
	{
		this->head = this->tail = n;
	}
	else
	{
		this->tail->link = n;
		this->tail = n;
	}
}
void List::Display()
{
	for (Node* n = this->head; n; n = n->link)
	{
		n->data.Display();
	}
}