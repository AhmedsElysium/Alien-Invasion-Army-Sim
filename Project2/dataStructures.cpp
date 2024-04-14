#include "dataStructures.h"

//Stack code
template <typename T>
Stack<T>::Stack() { top = nullptr; };

template <typename T>
bool Stack<T>::isEmpty() {
	return top;
}

template<typename T>
bool Stack<T>::push (T& Data) {
	top = new Node<T>(Data, top);
	return true;
}

template<typename T>
bool Stack<T>::pop(T& Data) {
	if (isEmpty()) { return false; };
	Data = top->data;
	*Node<T> temp = top;
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
void Stack<T>::print(Node<T> node) {
	if (!node) { return; };
	cout << node->data << endl;
	return print(node->next);
}

template<typename T>
void Stack<T>::print() {
	print(top);
}


//

