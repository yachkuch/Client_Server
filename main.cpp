#include <iostream>
#include <memory>
#include "Protocol_communication.h"

int main(int, char**){
    std::cout << "Hello, from Client_Server!\n";
    std::unique_ptr<char> ptr(new char [10]);
    return 0;
}
