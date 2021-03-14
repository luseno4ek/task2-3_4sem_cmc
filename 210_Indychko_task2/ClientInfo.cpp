#include "List.h"
#include "Queue.h"
#include <iostream>

ClientInfo::ClientInfo(const char* _surname, int _time)
    : time(_time) {
    surname = new char[strlen(_surname)];
    strcpy(surname, _surname);
}

ClientInfo::ClientInfo(const ClientInfo& _client)
    : time(_client.time) {
    surname = new char[strlen(_client.surname)];
    strcpy(surname, _client.surname);
}

ClientInfo::~ClientInfo() {
    if(surname != nullptr) {
        delete [] surname;
    }
}

std::ostream& operator <<(std::ostream& out, const ClientInfo& arg) {
    out << "Client: " << arg.surname << std::endl;
    out << "RegisterTime = " << arg.time;
    return out;
}
