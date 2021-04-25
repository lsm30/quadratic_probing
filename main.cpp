

#include "QP.hpp"
#include <iostream>
#include <string>

int main(){
    std::string hey = "hey";
    Data data(11,hey);
    Data data1(1,static_cast<std::string>("can you believe it?"));
    QashTable table(10);
    table.insert(data);
    table.insert(data1);
    // table.insert(10);
    table.print();
    std::cout << table.search(1);

    return 0;
}