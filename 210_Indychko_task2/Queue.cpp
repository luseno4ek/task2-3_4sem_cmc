#include "List.h"
#include "Queue.h"
#include <iostream>

template <typename Type>
Queue<Type>::Queue()
    : CurrentSize(0), MaxSize(4) {
        this->ListHead = nullptr;
}

template <typename Type>
Queue<Type>::Queue(const Type& _data)
    : CurrentSize(1), MaxSize(4)
{
    this->ListHead = new ListNode<Type>(_data);
    TotalSize++;
}

template <typename Type>
Queue<Type>::Queue(const Queue& _queue)
    : CurrentSize(_queue.CurrentSize), MaxSize(4)
{
    ListNode<Type>* temp = _queue.ListHead;
    ListNode<Type>* head = new ListNode<Type>(*temp);
    temp = temp->next;
    ListNode<Type>* current = head;
    while(temp != nullptr) {
        current->next = new ListNode<Type>(*temp);
        current = current->next;
        temp = temp->next;
    }
    current->next = nullptr;
    this->ListHead = head;
    TotalSize += CurrentSize;
}

template <typename Type>
Queue<Type>::~Queue() { TotalSize -= CurrentSize; }

template <typename Type>
int Queue<Type>::Size() const { return CurrentSize; }

template <typename Type>
void Queue<Type>::Back(const Type &_data) {
    if(Full()) {
        std::cout << "///ERROR/// : The queue is full!" << std::endl;
        return;
    }
    List<Type>::PushBack(_data);
    CurrentSize++;
    TotalSize++;
}

template <typename Type>
void Queue<Type>::Print() const { List<Type>::Print(); }

template <typename Type>
const Type& Queue<Type>::Front() const { return List<Type>::Front(); }

template <typename Type>
void Queue<Type>::Pop() {
    List<Type>::PopFront();
    CurrentSize--;
    TotalSize--;
}

template <typename Type>
bool Queue<Type>::Empty() const { return List<Type>::Empty(); }

template <typename Type>
bool Queue<Type>::Full() const { return CurrentSize == MaxSize; }
