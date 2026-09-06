#include "linked_list.h"
#include <iostream>


Node::Node(const int& val)
	: val(val)
{
}

LinkedList::LinkedList()
	: head(nullptr), tail(nullptr)
{
}

LinkedList::~LinkedList()
{
	clear();
}

Node* LinkedList::insert_before(Node* position, const int& val)
{
	Node* new_node = new Node(val);
	if (!head)
		return new_node;
	Node* curr = head;
	while (curr) {
		if (curr->next == position)
			break;
		curr = curr->next;
	}
	if (!curr) {
		delete new_node;
		return nullptr;
	}
	new_node->next = curr->next;
	curr->next = new_node;
	return new_node;
}


Node* LinkedList::insert_after(Node* position, const int& val) 
{
	Node* new_node = new Node(val);
	if (!head)
		return new_node;
	Node* curr = head;
	while (curr) {
		if (curr == position)
			break;
		curr = curr->next;
	}
	if (!curr) {
		delete new_node;
		return nullptr;
	}
	new_node->next = curr->next;
	curr->next = new_node;
	return new_node;
}

Node* LinkedList::push_front(const int& val)
{
	Node* new_node = new Node(val);
	if (!head) {
		head = new_node;
		tail = new_node;
		return head;
	}
	new_node->next = head;
	head = new_node;
	return head;
}

Node* LinkedList::push_back(const int& val)
{
	Node* new_node = new Node(val);
	if (!head) {
		head = new_node;
		tail = new_node;
		return tail;
	}
	tail->next = new_node;
	tail = new_node;
	return tail;
}

Node* LinkedList::find(Node* position)
{
	if (!head)
		return nullptr;
	Node* curr = head;
	while (curr) {
		if (curr == position)
			break;
		curr = curr->next;
	}
	return curr;
}


Node* LinkedList::erase(Node* position)
{

	Node* intermediate = nullptr;
	if (!head)
		return nullptr;
	if (!position)
		return nullptr;
	if (position == head) {
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
			return nullptr;
		}
		intermediate = head->next;
		delete head;
		head = intermediate;
		return head;
	}
	Node* curr = head;
	while (curr) {
		if (curr->next == position)
			break;
		curr = curr->next;
	}
	if (!curr)
		return nullptr;
	intermediate = curr->next->next;
	if (position == tail) {
		tail = curr;
	}
	delete curr->next;
	curr->next = intermediate;	
	return curr->next;
}

Node* LinkedList::front()
{
	if (!head)
		return nullptr;
	return head;
}

Node* LinkedList::back()
{
	if (!head)
		return nullptr;
	return tail;
}

int LinkedList::size()
{
	int count = 0;
	if (!head)
		return count;
	if (head == tail)
		return 1;
	Node* curr = head;
	while (curr) {
		count++;
		curr = curr->next;
	}
	return count;
}

bool LinkedList::empty()
{
	if (!head)
		return true;
	return false;
}

void LinkedList::clear()
{
	Node* curr = head;
	Node* intermediate = nullptr;
	while (curr) {
		intermediate = curr->next;
		delete curr;
		curr = intermediate;
	}
	head = nullptr;
	tail = nullptr;
}

void LinkedList::reverse()
{
	if (!head)
		return;
	if (head == tail)
		return;
	Node* curr = head;
	Node* next = head->next;
	Node* prev = nullptr;
	Node* intermediate = nullptr;
	while (next) {
		intermediate = next->next;
		next->next = curr;
		curr->next = prev;
		prev = curr;
		curr = next;
		next = intermediate;
	}
	intermediate = tail;
	tail = head;
	head = intermediate;
}

void LinkedList::print()
{
	Node* curr = head;
	std::cout << "[";
	while (curr) {
		std::cout << curr->val;
		if (curr->next)
			std::cout << ", ";
		curr = curr->next;
	}
	std::cout << "]\n";
}