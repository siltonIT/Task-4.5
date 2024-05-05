#include "Node.h"

template<typename T>
Node<T>::Node(): _left(nullptr), _right(nullptr) {}

template<typename T>
Node<T>::Node(T data): _left(nullptr), _right(nullptr), _data(data) {}
