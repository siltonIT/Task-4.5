#pragma once

#include <iostream>
#include "Node.h"
#include "Node.cpp"


template<typename T>
class Tree {
public:
	Tree();

  	Tree(T);

	Tree(Tree<T>&);

	Tree<T>& operator=(Tree<T>);

  	Tree(Tree<T>&&) noexcept;

  	Tree<T>& operator=(Tree<T>&&) noexcept;

  	void swap(const Tree<T>&) noexcept;

  	~Tree();

  	void add_first(T);

  	void insert(Node<T>*&, T);

  	void erase(const T&);

  	Node<T>* get_at(Node<T>*, const T&);

  	void print(Node<T>*);

  	void clear(Node<T>*&);

  	Node<T>*& root();

private:
  	void copy(Node<T>*&, Node<T>*&);

  	Node<T>* _root;
};
