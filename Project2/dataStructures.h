#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct node {
	node* next;
	T data;
};


template <typename T>
class Stack{
private:
	node* top;
public:
	void insert(T Data);
	T remove();
	void print();
	T peek();
	bool isEmptyj();
};

template <typename T>
class Queue{
private:
	node* head;
	node* rear;
public:
	void insert(T Data);
	T remove();
	void print();
	T peek();
	bool isEmptyj();
};

