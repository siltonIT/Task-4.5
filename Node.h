#pragma once

template<typename T>
struct Node {
	Node();

	Node(T);

	Node<T>* _left;
	Node<T>* _right;
	T _data;
};
