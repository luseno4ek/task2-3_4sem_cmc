#include "List.h"
#include "Queue.h"
#include <iostream>

const int MAXSIZE = 4;

template <typename Type>
Queue<Type>::Queue()
    : MaxSize(MAXSIZE)
{
    this->CurrentSize = 0;
    this->ListHead = this-> ListTail = nullptr;
}

template <typename Type>
Queue<Type>::Queue(const Type& _data)
    : MaxSize(MAXSIZE)
{
    this->CurrentSize = 1;
    this->ListHead = this->ListTail = new ListNode<Type>(_data);
    TotalSize++;
}

template <typename Type>
Queue<Type>::Queue(const Queue& _queue)
    : MaxSize(MAXSIZE)
{
    ListNode<Type>* temp = _queue.ListHead;
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
    this->ListHead = head;
    this->ListTail = current;
    this->CurrentSize = _queue.CurrentSize;
}

template <typename Type>
Queue<Type>::~Queue() { TotalSize -= this->CurrentSize; }

template <typename Type>
int Queue<Type>::Size() const { return this->CurrentSize; }

template <typename Type>
void Queue<Type>::Back(const Type &_data) {
    if(Full()) {
        std::cout << "///ERROR/// : The queue is full!" << std::endl;
        return;
    }
    List<Type>::PushBack(_data);
    TotalSize++;
}

template <typename Type>
void Queue<Type>::Print() const { List<Type>::Print(); }

template <typename Type>
const Type& Queue<Type>::Front() const { return List<Type>::Front(); }

template <typename Type>
void Queue<Type>::Pop() {
    List<Type>::PopFront();
    if(Empty()) {
        return;
    }
    TotalSize--;
}

template <typename Type>
bool Queue<Type>::Empty() const { return List<Type>::Empty(); }

template <typename Type>
bool Queue<Type>::Full() const { return this->CurrentSize == MaxSize; }
