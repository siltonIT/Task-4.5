#include "Tree.h"

template<typename T>
Tree<T>::Tree() : _root(nullptr) {}

template<typename T>
Tree<T>::Tree(T data) : _root(new Node<T>(data)) {}

template<typename T>
Tree<T>::Tree(Tree<T>& other) {
	copy(_root, other._root);
}

template<typename T>
Tree<T>& Tree<T>::operator=(Tree<T> other) {
	Tree<T> res(other);
	swap(res);

	return *this;
}

template<typename T>
Tree<T>::Tree(Tree<T>&& other) noexcept : _root(other._root) {
	other._root = nullptr;
}

template<typename T>
Tree<T>& Tree<T>::operator=(Tree<T>&& other) noexcept {
	Tree<T> res(std::move(other));
	swap(res);

	return *this;
}
template<typename T>
void Tree<T>::swap(const Tree<T>& other) noexcept {
	std::swap(_root, other._root);
}

template<typename T>
Tree<T>::~Tree() {
	clear(_root);
}

template<typename T>
void Tree<T>::add_first(T data) {
	if (_root != nullptr)
		return;

	_root = new Node<T>(data);
}

template<typename T>
void Tree<T>::insert(Node<T>*& node, T data) {
	if (node == nullptr) {
		node = new Node<T>(data);
		return;
	}

	if (node->_data < data)
		insert(node->_right, data);
	else if (node->_data > data)
		insert(node->_left, data);
}

template<typename T>
void Tree<T>::erase(const T& key) {
	Node<T>* parent = _root;
	Node<T>* current = _root;

	while (current != nullptr && current->_data != key) {
		parent = current;

		if (current->_data < key)
			current = current->_right;
		else if (current->_data > key)
			current = current->_left;
	}

	if (current == nullptr || current->_right != nullptr || current->_left != nullptr)
		return;

	if (current == _root)
		_root = nullptr;
	else if (parent->_left == current)
		parent->_left = nullptr;
	else
		parent->_right = nullptr;

	delete current;
}

template<typename T>
Node<T>* Tree<T>::get_at(Node<T>* node, const T& key) {
	if (node == nullptr)
		return nullptr;

	if (node->_data < key)
		get_at(node->_right, key);
	else if (node->_data > key)
		get_at(node->_left, key);

	return node;
}

template<typename T>
void Tree<T>::print(Node<T>* node) {
	if (node == nullptr)
		return;

	print(node->_left);
	std::cout << node->_data << ' ';
	print(node->_right);
}


template<typename T>
void Tree<T>::clear(Node<T>*& node) {
	if (node == nullptr)
		return;
	
	clear(node->_left); 
	clear(node->_right);

	delete node;           
	node = nullptr;
}

template<typename T>
Node<T>*& Tree<T>::root() {
	return _root;
}

template<typename T>
void Tree<T>::copy(Node<T>*& node, Node<T>*& other ) {
	if (other == nullptr)
		return;

	insert(node, other->_data);
	copy(node, other->_left);
	copy(node, other->_right);
}
