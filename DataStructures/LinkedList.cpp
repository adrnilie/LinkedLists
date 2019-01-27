#include "pch.h"
#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

class list
{
	private: node *head, *tail;

	public: list()
	{
		head = NULL;
		tail = NULL;
	}

	void createNode(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		} else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	void display()
	{
		node *temp = new node;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}

	// Insertion
	void insert_start(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}

	void insert_tail(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}

	void insert_at_position(int position, int value)
	{
		node *previous = new node;
		node *current = new node;
		node *temp = new node;
		current = head;

		for (int i = 1; i < position; ++i)
		{
			previous = current;
			current = current->next;
		}

		temp->data = value;
		previous->next = temp;
		temp->next = current;
	}

	// Deletion
	void delete_start()
	{
		node *temp = new node;
		temp = head;
		head = head->next;
		delete temp;
	}

	void delete_end()
	{
		node *current = new node;
		node *previous = new node;
		current = head;

		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}

		tail = previous;
		previous->next = NULL;
		delete current;
	}

	void delete_at_position(int position)
	{
		node *current = new node;
		node *previous = new node;
		current = head;

		for (int i = 1; i < position; ++i)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}
};

int main()
{
	list obj;
	obj.createNode(20);
	obj.createNode(102);
	obj.createNode(1);
	obj.createNode(111);
	obj.createNode(222);
	//obj.insert_start(5);
	//obj.insert_tail(10);
	//obj.insert_at_position(2, 200);
	//obj.delete_start();
	//obj.delete_end();
	obj.delete_at_position(2);
	obj.display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
