#include "List.h"
#include "Queue.h"
#include <iostream>

template <typename Type>
ListNode<Type>::ListNode(const Type& _data, ListNode<Type>* _next,
                                                    ListNode<Type>* _previous)
    : data(_data), next(_next), previous(_previous) {}

template <typename Type>
ListNode<Type>::ListNode(const ListNode& _node)
    : data(_node.data), next(_node.next), previous(_node.previous) {}

template <typename Type>
ListNode<Type>::~ListNode() {
    next = nullptr;
    previous = nullptr;
}

//////////////////////////////////////////////////////////////////////////

template <typename Type>
List<Type>::List()
    : ListHead(nullptr), ListTail(nullptr), CurrentSize(0) {}

template <typename Type>
List<Type>::List(const List& _list) {
    ListNode<Type>* temp = _list.ListHead;
    ListNode<Type>* head = new ListNode<Type>(*temp);
    temp = temp->next;
    ListNode<Type>* current = head;
    ListNode<Type>* previous = head;
    while(temp != nullptr) {
        current->next = new ListNode<Type>(*temp);
        current = current->next;
        current->previous = previous;
        previous = previous -> next;
        temp = temp->next;
    }
    ListHead = head;
    ListTail = current;
    CurrentSize = _list.CurrentSize;
}


template <typename Type>
List<Type>::~List() {
    ListNode<Type>* current = ListHead;
    while(current != nullptr) {
        ListNode<Type>* temp = current;
        current = temp->next;
        delete temp;
    }
}

template <typename Type>
void List<Type>::PushFront(const Type& _data) {
    ListHead = new ListNode<Type>(_data, ListHead);
    if(ListHead->next != nullptr) {
        ListHead->next->previous = ListHead;
    } else {
        ListTail = ListHead; // we have one elem in list => Head == Tail;
    }
    CurrentSize++;
}

template <typename Type>
void List<Type>::PushBack(const Type& _data) {
    ListTail = new ListNode<Type>(_data, nullptr, ListTail);
}

template <typename Type>
void List<Type>::Print() const {
    ListNode<Type>* current = ListHead;
    for(int i = 0; i < CurrentSize; i++) {
        ListNode<Type> temp = *current;
        std::cout << i << ": " << temp.data << std::endl;
        current = temp.next;
    }
}

template <typename Type>
const Type& List<Type>::Front() const { return ListHead->data; }

template <typename Type>
const Type& List<Type>::Back() const {
    ListNode<Type>* current = ListHead;
    while(current->next != nullptr) {
        current = current->next;
    }
    return current->data;
}

template <typename Type>
void List<Type>::PopFront() {
    ListNode<Type>* current = ListHead;
    ListHead = current->next;
    delete current;
}

template <typename Type>
void List<Type>::PopBack() {
    ListNode<Type>* current = ListHead;
    //what if ListHead == nullptr?
    while(current->next != nullptr) {
        current = current->next;
    }
    ListNode<Type>* last = current->previous;
    last->next = nullptr;
    delete current;
}

template <typename Type>
void List<Type>::Insert(int p, const Type& _data) {
    if(p == 0) {
        PushFront(_data);
        return;
    }
    int pos = 0;
    //TODO:fix p > size
    ListNode<Type>* current = ListHead;
    while(pos != p) {
        current = current->next;
        pos++;
    }
    if(current == nullptr) {
        PushBack(_data);
        return;
    }
    ListNode<Type>* previous = current->previous;
    previous->next = new ListNode<Type>(_data, current, previous);
    current->previous = previous->next;
}

template <typename Type>
void List<Type>::Erase(int p) {
    if(p == 0) {
        PopFront();
        return;
    }
    int pos = 0;
    ListNode<Type>* current = ListHead;
    while(pos != p) {
        current = current->next;
        pos++;
    }
    if(current->next == nullptr) {
        PopBack();
        return;
    }
    ListNode<Type>* previous = current->previous;
    previous->next = current->next;
    //TODO: Angry noises
    free(current);
}

template <typename Type>
bool List<Type>::Empty() const {
    if(ListHead == nullptr) {
        return true;
    }
    return false;
}

template <typename Type>
int List<Type>::Size() const {
    if(Empty()) {
        return 0;
    }
    int size = 1;
    ListNode<Type>* current = ListHead;
    while(current->next != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}

