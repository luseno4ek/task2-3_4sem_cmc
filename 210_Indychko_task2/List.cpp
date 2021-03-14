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
///Changing ListHead to new ListNode with _data
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
///Changing ListTail to new ListNode with _data
    ListTail = new ListNode<Type>(_data, nullptr, ListTail);
    if(ListHead == nullptr) {
        ListHead = ListTail;
        return;
    }
    ListTail->previous->next = ListTail;
    CurrentSize++;
}

template <typename Type>
void List<Type>::Print() const {
    if(Empty()) {
        std::cout << "///ERROR/// : The list is empty!" << std::endl;
        return;
    }
    ListNode<Type>* current = ListHead;
    for(int i = 0; i < CurrentSize; i++) {
        ListNode<Type> temp = *current;
        std::cout << i << ": " << temp.data << std::endl;
        current = temp.next;
    }
}

template <typename Type>
const Type& List<Type>::Front() const {
///Returning data from ListHead, if empty - ERROR
    if(ListHead == nullptr) {
        std::cout << "///ERROR/// : The list is empty!" << std::endl;
        return -1;
    }
    return ListHead->data;
}

template <typename Type>
const Type& List<Type>::Back() const {
///Returning data from ListTail, if empty - ERROR
    if(ListHead == nullptr) {
        std::cout << "///ERROR/// : The list is empty!" << std::endl;
        return -1;
    }
    return ListTail->data;
}

template <typename Type>
void List<Type>::PopFront() {
///Erasing the first element, if empty - ERROR
    if(ListHead == nullptr) {
        std::cout << "///ERROR/// : The list is empty!" << std::endl;
        return;
    }
    ListNode<Type>* current = ListHead;
    ListHead = current->next; // we had only one elem => ListHead == nullptr
    CurrentSize--;
    delete current;
}

template <typename Type>
void List<Type>::PopBack() {
///Erasing the last element, if empty - ERROR
    if(ListHead == nullptr) {
        std::cout << "///ERROR/// : The list is empty!" << std::endl;
        return;
    }
    ListNode<Type>* temp = ListTail;
    ListNode<Type>* new_last = temp->previous;
    if(new_last != nullptr) {
        new_last->next = nullptr;
        ListTail = new_last;
    } else {
        ListTail = ListHead = nullptr;
    }
    CurrentSize--;
    delete temp;
}

template <typename Type>
void List<Type>::Insert(int p, const Type& _data) {
///Inserting element before p-position if p <= CurrentSize
    if(p > CurrentSize) {
        std::cout << "///ERROR/// : The pos doesn't exist!" << std::endl;
        return;
    }
    if(p == 0) {
        PushFront(_data);
        return;
    }
    if(p == CurrentSize) {
        PushBack(_data);
        return;
    }
    ListNode<Type>* current = ListHead;
    while(p != 0) {
        current = current->next;
        p--;
    }
    ListNode<Type>* previous = current->previous;
    previous->next = new ListNode<Type>(_data, current, previous);
    current->previous = previous->next;
    CurrentSize++;
}

template <typename Type>
void List<Type>::Erase(int p) {
///Deleting element from p-position if p < CurrentSize
    if(p >= CurrentSize) {
        std::cout << "///ERROR/// : The pos doesn't exist!" << std::endl;
        return;
    }
    if(p == 0) {
        PopFront();
        return;
    }
    if(p == CurrentSize - 1) {
        PopBack();
        return;
    }
    ListNode<Type>* current = ListHead;
    while(p != 0) {
        current = current->next;
        p--;
    }
    ListNode<Type>* previous = current->previous;
    previous->next = current->next;
    CurrentSize--;
    delete current;
}

template <typename Type>
bool List<Type>::Empty() const {
    if(ListHead == nullptr) {
        return true;
    }
    return false;
}

template <typename Type>
int List<Type>::Size() const { return CurrentSize; }

