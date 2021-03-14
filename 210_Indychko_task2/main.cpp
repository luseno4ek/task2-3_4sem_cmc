#include <iostream>
#include "List.cpp"
#include "Queue.cpp"

template <typename Type>
int Queue<Type>::TotalSize = 0;

int main() {
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
