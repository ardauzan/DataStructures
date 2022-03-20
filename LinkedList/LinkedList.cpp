#include "LinkedList.hpp"
template <typename T> LinkedList<T>::node::node() : payload((T)0), next(0) { }
template <typename T> LinkedList<T>::node::node(T payload) : next(0) { this->payload = payload; }
template <typename T> LinkedList<T>::node::node(T payload, node* next) {
    this->payload = payload;
    this->next = next;
}
template <typename T> LinkedList<T>::node::node(const node& node) : next(0) { payload = node.payload; }
template <typename T> LinkedList<T>::node::~node() {
    if (next != 0) { delete next; }
}
template <typename T> T LinkedList<T>::node::getPayload() const { return payload; }
template <typename T> void LinkedList<T>::node::setPayload(T payload) { this->payload = payload; }
template <typename T> typename LinkedList<T>::node* LinkedList<T>::node::getNext() const { return next; }
template <typename T> void LinkedList<T>::node::setNext(typename LinkedList<T>::node* next) { this->next = next; }
template <typename T> LinkedList<T>::LinkedList() : size(0), head(new node) { }
template <typename T> LinkedList<T>::LinkedList(int size) : head(new node) {
    node* tmp = head;
    this->size = size;
    for (int i = 1; i < this->size; i++) {
        tmp->setNext() = new node;
        tmp = tmp->getNext();
    }
}
template <typename T> LinkedList<T>::LinkedList(int size, T payloads[]) : head(new node) {
    this->size = size;
    node* tmp = head;
    tmp->setPayload(payloads[0]);
    for (int i = 1; i < this->size; i++) {
        tmp->setNext(new node);
        tmp = tmp->getNext();
        tmp->setPayload(payloads[i]);
    }
}
template <typename T> LinkedList<T>::LinkedList(const LinkedList& LinkedList) : head(new node) {
    setSize(LinkedList.getSize());
    node* tmp1 = head;
    node* tmp2 = LinkedList.getHead();
    tmp1->setPayload(tmp2->getPayload());
    for (int i = 1; i < size; i++) {
        tmp1->setNext(new node);
        tmp1 = tmp1->getNext();
        tmp2 = tmp2->getNext();
        tmp1->setPayload(tmp2->getPayload());
    }
}
template <typename T> LinkedList<T>::~LinkedList() { delete head; }
template <typename T> int LinkedList<T>::getSize() const { return size; }
template <typename T> void LinkedList<T>::setSize(int size) {
    if (this->size < size) {
        for (int i = size - this->size; i > 0; i--) { addNodeToLast((T)0); }
    } else {
        for (int i = this->size - size; i > 0; i--) { deleteNodefromLast(); }
    }
}
template <typename T> typename LinkedList<T>::node* LinkedList<T>::getHead() const { return head; }
template <typename T> typename LinkedList<T>::node* LinkedList<T>::getNode(int index) const {
    if (index >= 0 && index < size) {
        node* tmp = head;
        for (int i = 1; i < index; i++) {
            tmp = tmp->getNext();
        }
        return tmp;
    }
}
template <typename T> void LinkedList<T>::setNode(int index, typename LinkedList<T>::node* node) {
    if (index >= 0 && index < size) {
        node* tmp = head;
        for (int i = 1; i < index; i++) {
            tmp = tmp->getNext();
        }
        tmp = node;
    }
}
template <typename T> void LinkedList<T>::addNodeToLast(T payload) {
    node * tmp = head;
    for (int i = 1; i < size; i++) { tmp = tmp->getNext(); }
    tmp->setNext(new node(payload));
    size++;
}
template <typename T> void LinkedList<T>::addNodeAt(int index, T payload) {
    if (index <= size && index >= 0) {
        node * tmp = head;
        for (int i = 1; i < index; i++) { tmp = tmp->getNext(); }
        tmp->setNext(new node(payload, tmp->getNext()));
        size++;
    }
}
template <typename T> void LinkedList<T>::deleteNodefromLast() {
    if (size > 0) {
        node * tmp = head;
        for (int i = 1; i < size - 1; i++) { tmp = tmp->getNext(); }
        delete tmp->getNext();
        tmp->setNext(0);
        size--;
    } else { head->setPayload((T)0); }
}
template <typename T> void LinkedList<T>::deleteNodeAt(int index) {
    if (index < size && index >= 0) {
        node* tmp1 = head;
        node* tmp2;
        for (int i = 1; i < index - 1; i++) { tmp1 = tmp1->getNext(); }
        tmp2 = tmp1->getNext();
        tmp1->setNext(tmp2->getNext());
        tmp2->setNext(0);
        delete tmp2;
        size--;
    }
}
template <typename T> void LinkedList<T>::swapNodes(int index1, int index2) {
    if (index1 >= 0 && index2 > index1 && index1 < size && index2 < size) {
        node* tmp1 = head;
        node* tmp2;
        node* tmp3;
        node* tmp4;
        for (int i = 1; i < index1 - 1; i++) { tmp1 = tmp1->getNext(); }
        tmp2 = tmp1->getNext();
        tmp3 = tmp2;
        for (int i = index1 ; i < index2 - 1; i++) { tmp3 = tmp3->getNext(); }
        tmp4 = tmp3->getNext()->getNext();
        tmp1->setNext(tmp3->getNext());
        tmp1->getNext()->setNext(tmp2->getNext());
        tmp2->setNext(tmp4);
    }
}