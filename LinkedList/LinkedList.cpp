#include "LinkedList.hpp"
template <typename T> LinkedList<T>::node::node() : payload((T)0), next(0) {}
template <typename T> LinkedList<T>::node::node(T payload) : next(0) {
    this->payload = payload;
}
template <typename T> LinkedList<T>::node::node(T payload, node* next) {
    this->payload = payload;
    this->next = next;
}
template <typename T> LinkedList<T>::node::node(const node& node) : next(0) {
    payload = node.payload;
}
template <typename T> LinkedList<T>::node::~node() {
    delete next;
}
template <typename T> T LinkedList<T>::node::getPayload() const {
    return payload;
}
template <typename T> void LinkedList<T>::node::setPayload(T payload) {
    this->payload = payload;
}
template <typename T> typename LinkedList<T>::node* LinkedList<T>::node::getNext() const {
    return next;
}
template <typename T> void LinkedList<T>::node::setNext(typename LinkedList<T>::node* next) {
    this->next = next;
}
template <typename T> LinkedList<T>::LinkedList() : size(0), head(new node) {}
template <typename T> LinkedList<T>::LinkedList(int size) : head(new node) {
    node* tmp = head;
    this->size = size;
    for(int i = 1; i < size; i++){
        tmp->setNext() = new node;
        tmp = tmp->getNext();
    }
}
template <typename T> LinkedList<T>::LinkedList(int size, T payloads[]) : head(new node) {
    node* tmp = head;
    this->size = size;
    for(int i = 1; i < size; i++){
        tmp->setNext() = new node;
        tmp = tmp->getNext();
    }
}
template <typename T> LinkedList<T>::LinkedList(const LinkedList& LinkedList) : head(new node) {
    node* tmp = LinkedList.getHead();
    head->setPayload(tmp->getPayload());

    this->size = LinkedList.getSize();

    for(int i = 1; i <= size; i++){
        addNode(tmp->getNext()->getPayload());
    }

}
template <typename T> LinkedList<T>::~LinkedList() {
    delete head;
}
template <typename T> int LinkedList<T>::getSize() const {
    return size;
}
template <typename T> void LinkedList<T>::setSize(int size) {
    if (this->size < size) {
        for (int i = 0; i <= this->size; i=i) {
            addNode((T)0);
        }
    } else {
        for (int i = 0; i <= size; i=i) {
            deleteNode(this->size);
            this->size--;
        }
    }
}
template <typename T> typename LinkedList<T>::node* LinkedList<T>::getHead() const {
    return head;
}
template <typename T> void LinkedList<T>::addNode(T payload) {
    node* tmp = head;

    for(int i = 0; i <= size; i++){
        if (i==size) {
            tmp->setNext(new node(payload));
        }
        else {
            tmp = tmp->getNext();
        }
    }
    size++;
}
template <typename T> void LinkedList<T>::deleteNode(int index) {
    node* tmp = head;

    for(int i = 0; i < size - 1; i++){
        if (i == size - 1) {
            delete tmp->getNext();
            tmp->setNext(0);
        }
        else {
            tmp = tmp->getNext();
        }
    }
    size--;
}