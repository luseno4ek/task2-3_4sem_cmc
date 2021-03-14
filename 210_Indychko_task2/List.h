#ifndef LIST_h
#define LIST_h

#include <iostream>


template <typename Type>
struct ListNode {
    Type data;
    ListNode* next;
    ListNode* previous;
    ListNode(const Type& _data, ListNode* _next = nullptr,
                                        ListNode* _previous = nullptr);
    ListNode(const ListNode& _node);
    ~ListNode();
};

template <typename Type>
class List {
protected:
    ListNode<Type>* ListHead;
    ListNode<Type>* ListTail;
    int CurrentSize;
public:
    List();
    List(const List& _list);
    ~List();
    void PushFront(const Type& _data);
    void PushBack(const Type& _data);
    const Type& Front() const;
    const Type& Back() const;
    void PopFront();
    void PopBack();
    void Insert(int p, const Type& _data);
    void Erase(int p);
    bool Empty() const;
    int Size() const;
    void Print() const;
};

#endif
