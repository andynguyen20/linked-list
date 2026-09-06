#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
public:
	friend class LinkedList;
	Node(const int& val);
	int val;
private:
	Node* next = nullptr;
};

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	Node* insert_before(Node* position, const int& val);
	Node* insert_after(Node* position, const int& val);
	Node* push_front(const int& val);
	Node* push_back(const int& val);
	Node* find(Node* position);
	Node* erase(Node* position);
	Node* front();
	Node* back();
	int size();
	bool empty();
	void clear();
	void reverse();
	void print();
private:
	Node* head;
	Node* tail;
};

#endif