#include <iostream>
#include "List.cpp"
#include "Queue.cpp"

template <typename Type>
int Queue<Type>::TotalSize = 0;

int main() {
    List<int> list1;
    list1.PushFront(7);
    std::cout << "List_1:" << std::endl;
    list1.Print();
    list1.PushBack(8);
    list1.PushFront(6);
    std::cout << std::endl << "List_1:" << std::endl;
    list1.Print();
    std::cout << std::endl << "FrontElement = " << list1.Front() << std::endl;
    std::cout << "BackElement = " << list1.Back() << std::endl;
    list1.PopBack();
    list1.PopFront();
    std::cout << std::endl << "List_1:" << std::endl;
    list1.Print();
    list1.Insert(0, 8);
    list1.Insert(2, 6);
    list1.Insert(3,5);
    std::cout << std::endl << "List_1:" << std::endl;
    list1.Print();
    list1.Erase(2);
    std::cout << std::endl << "List_1:" << std::endl;
    list1.Print();
    std::cout << std::endl << "List_1_size = " << list1.Size() << std::endl;
    List<char> list2;
    std::cout << std::endl << "List_1_is_empty = " << list1.Empty() << std::endl;
    std::cout << "List_2_is_empty = " << list2.Empty() << std::endl;
    list2.PushFront('h');
    list2.PushBack('?');
    list2.PushBack('!');
    list2.Insert(1, 'i');
    std::cout << std::endl << "List_2:" << std::endl;
    list2.Print();
    std::cout << std::endl << "List_2_size = " << list2.Size() << std::endl;
    list2.Erase(2);
    std::cout << std::endl << "BackElement = " << list2.Back() << std::endl;
    std::cout << std::endl;
    ///////////////////////////////////////////
    Queue<ClientInfo> queue1;
    queue1.Back("Vasechkin");
    ClientInfo client1("Matroskin", 777);
    queue1.Back(client1);
    std::cout << "INFO ABOUT 1st QUEUE:" << std::endl;
    queue1.Print();
    std::cout << "IsEmpty = " << queue1.Empty() << std::endl;
    std::cout << "IsFull = " << queue1.Full() << std::endl;
    std::cout << "Size = " << queue1.Size() << std::endl << std::endl;
    Queue<ClientInfo> queue2(client1);
    queue2.Back("Petrov");
    queue2.Back("Ivanov");
    queue2.Back("Smirnov");
    std::cout << "INFO ABOUT 2nd QUEUE:" << std::endl;
    queue2.Print();
    std::cout << "IsEmpty = " << queue2.Empty() << std::endl;
    std::cout << "IsFull = " << queue2.Full() << std::endl;
    std::cout << "Size = " << queue2.Size() << std::endl << std::endl;
    Queue<ClientInfo> queue3(queue2);
    queue3.Back("Krickov");
    queue3.Pop();
    queue3.Back("Krickov");
    std::cout << "INFO ABOUT 3rd QUEUE:" << std::endl;
    queue3.Print();
    std::cout << "IsEmpty = " << queue3.Empty() << std::endl;
    std::cout << "IsFull = " << queue3.Full() << std::endl;
    std::cout << "Size = " << queue3.Size() << std::endl << std::endl;
    return 0;
}
