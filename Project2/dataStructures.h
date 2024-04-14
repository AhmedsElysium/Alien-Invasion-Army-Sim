#pragma once
#include <iostream>
using namespace std;


//Nodes
template <typename T>
struct Node {
	T data;
	Node<T>* next;
};


template <typename T>
struct dNode {
	T data;
	dNode<T>* next;
	dNode<T>* prev;
};


template <typename T>
struct pNode {
	T data;
	int priority;
	pNode<T>* next;
};


template <typename T>
class Stack{
private:
	Node<T>* top;
	void print(Node<T> node);
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
public:
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
public:
	bool enqueue(T& Data);
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
public:
	bool pushHead(T& Data);
	bool pushRear(T& Data);

	bool popHead(T& headEntry);
	bool popRear(T& rearEntry);

	bool peekHead(T& headEntry);
	bool peekRear(T& rearEntry);

	bool isEmpty();
	void print();

};
