#ifndef QUEUE_h
#define QUEUE_h

#include <iostream>

struct ClientInfo {
    char* surname;
    int time;
    ClientInfo(const char* _surname, int _time = 0);
    ClientInfo(const ClientInfo& _client);
    ~ClientInfo();
    friend std::ostream& operator <<(std::ostream& out, const ClientInfo& arg);
};

template <typename Type>
class Queue : protected List<Type> {
private:
    const int MaxSize;
    int CurrentSize;
public:
    static int TotalSize;
    Queue();
    explicit Queue(const Type& _data);
    Queue(const Queue& _queue);
    ~Queue();
    void Back(const Type& _data);
    const Type& Front() const;
    void Pop();
    bool Empty() const;
    int Size() const;
    bool Full() const;
    void Print() const;
};

#endif
