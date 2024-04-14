#pragma once
#include <iostream>
using namespace std;


//Nodes
template <typename T>
struct Node {
	T data;
	Node<T>* next;
	Node(T data, Node<T>* next);
};


template <typename T>
struct dNode {
	T data;
	dNode<T>* next;
	dNode<T>* prev;
	dNode(T data, dNode<T>* next, dNode<T>* prev);
};


template <typename T>
struct pNode {
	T data;
	int priority;
	pNode<T>* next;
	pNode(T data, int priority, pNode<T>* next);
};


template <typename T>
class Stack{
private:
	Node<T>* top;
	void print(Node<T>* node);
public:
	Stack();
	bool push(T& Data);
	bool pop(T& topEntry);
	void print();
	bool peek(T& topEntry);
	bool isEmpty();
};

template <typename T>
class Queue{
private:
	Node<T>* head;
	Node<T>* rear;
	void print(Node<T>* node);
public:
	Queue();
	bool enqueue(T& Data);
	bool dequeue(T& topEntry);
	void print();
	bool peek(T& topEntry);
	bool isEmpty();
};


template <typename T>
class pQueue {
private:
	pNode<T>* head;
	void print(pNode<T>* node);
public:
	pQueue();
	bool enqueue(T& Data, int Priority);
	bool dequeue(T& topEntry);
	void print();
	bool peek(T& topEntry);
	bool isEmpty();
};

template <typename T>
class dQueue {
private:
	dNode<T>* head;
	dNode<T>* rear;
	void print(Node<T>* node);
public:
	dQueue();
	bool pushHead(T& Data);
	bool pushRear(T& Data);

	bool popHead(T& headEntry);
	bool popRear(T& rearEntry);

	bool peekHead(T& headEntry);
	bool peekRear(T& rearEntry);

	bool isEmpty();
	void print();

};


//Node code
template <typename T>
Node<T>::Node(T data, Node<T>* next) :data(data), next(next) {};


//Doubly Linked Node code
template <typename T>
dNode<T>::dNode(T data, dNode<T>* next, dNode<T>* prev) :data(data), next(next), prev(prev) {};


//Priority Node code
template <typename T>
pNode<T>::pNode(T data, int priority, pNode<T>* next) :data(data), priority(priority), next(next) {};


//Stack code
template <typename T>
Stack<T>::Stack() {
	top = nullptr;
};

template <typename T>
bool Stack<T>::isEmpty() {
	return !top;
}

template<typename T>
bool Stack<T>::push(T& Data) {
	top = new Node<T>(Data, top);
	return true;
}

template<typename T>
bool Stack<T>::pop(T& Data) {
	if (isEmpty()) { return false; };
	Data = top->data;
	Node<T>* temp;
	temp = top;
	top = top->next;
	delete temp;
	return true;
}

template<typename T>
bool Stack<T>::peek(T& Data) {
	if (isEmpty()) { return false; };
	Data = top->data;
	return true;
}

template<typename T>
void Stack<T>::print(Node<T>* node) {
	if (!node) { return; };
	cout << node->data << endl;
	return print(node->next);
}

template<typename T>
void Stack<T>::print() {
	print(top);
}


//Queue code
template<typename T>
Queue<T>::Queue() { 
	rear = nullptr;
	head = nullptr;
}

template<typename T>
bool Queue<T>::isEmpty() {
	return !head;
}

template<typename T>
bool Queue<T>::enqueue(T& Data) {
	if (isEmpty()) {
		head = new Node<T>(Data, nullptr);
		rear = head;
	}
	else {
		rear->next = new Node<T>(Data, nullptr);
		rear = rear->next;
	};
	return true;
}

template<typename T>
bool Queue<T>::dequeue(T& topEntry) {
	if (isEmpty()) {
		return false;
	};

	topEntry = head->data;
	head = head->next;
	return true;
}

template<typename T>
bool Queue<T>::peek(T& topEntry) {
	if (isEmpty()) {
		return false;
	};
	topEntry = head->data;
	return true;
}

template<typename T>
void Queue<T>::print(Node<T> *node) {
	if (!node) return;
	cout << node->data << endl;
	return print(node->next);
}

template<typename T>
void Queue<T>::print() {
	print(head);
}


//Priority Queue code
template<typename T>
pQueue<T>::pQueue() {
	head = nullptr;
}

template<typename T>
bool pQueue<T>::enqueue(T& Data,int Priority) {
	if (isEmpty() || Priority > head->priority) {
		head = new pNode<T>(Data, Priority, head);
		return true;
	};
	pNode<T>* temp = head;
	while (temp->next && temp->next->priority >= Priority) {
		temp = temp->next;
	};
	temp->next = new pNode<T>(Data, Priority, temp->next);
	return true;
}

template<typename T>
bool pQueue<T>::dequeue(T& topEntry) {
	if(isEmpty()) return false;
	topEntry = head->data;
	pNode<T>* temp = head;
	head = head->next;
	delete temp;
	return true;
}

template<typename T>
void pQueue<T>::print(pNode<T>* node) {
	if (!node) return;
	cout << node->data<<endl;
	return print(node->next);
}

template<typename T>
void pQueue<T>::print() {
	print(head);
}

template<typename T>
bool pQueue<T>::peek(T& topEntry) {
	if (isEmpty()) return false;
	topEntry = head->data;
	return true;
}

template<typename T>
bool pQueue<T>::isEmpty() {
	return !head;
}

