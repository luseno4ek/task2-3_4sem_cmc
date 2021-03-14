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
    void PushFront(const Type& _data);     ///Pushing one element to the front
    void PushBack(const Type& _data);      ///Pushing one element to the back
    const Type& Front() const;             ///Reading one element from the front
    const Type& Back() const;              ///Reading one element from the back
    void PopFront();                       ///Erasing one element from the front
    void PopBack();                        ///Erasing one element from the back
    void Insert(int p, const Type& _data); ///Inserting element before the position p
    void Erase(int p);                     ///Erasing element from the position p
    bool Empty() const;                    ///Checking if List is empty
    int Size() const;                      ///Getting List size
    void Print() const;                    ///Printing the List
};

#endif
