//
// Logan Mashchak
// Data Structures
// Project 3: Hash Table with Quadratic probing
// 04/23/21
//
/*  Hash Table: 
 *
 * Functionality:
 * 1. insert a number
 * 2. Print hash table
 *
 */
#include "QP.hpp"

#include <iostream>

QashTable::QashTable(int num)
{
    this->size = num;
    hashTable = static_cast<Data<std::string>*>(::operator new[](num*sizeof(Data<std::string>)));
    for(int i = 0; i < size; i++){
        ::new (hashTable+i) Data(-1, static_cast<std::string>("null"));
    }
}

void QashTable::insert(Data<std::string> data){
    int key = data.key % size;

    if (hashTable[key].key == -1) {
        hashTable[key].key = data.key;
        hashTable[key].value = data.value;
        
    }
    else
    {
        int i = 0;
        while (hashTable[key].key != -1){
            ++i;
            key = key + (i*i) + 2*i + 1;
            key = key % size;

        }
        hashTable[key].key = data.key;
        hashTable[key].value = data.value;
    }
    

}

std::string QashTable::search(int num){
    int key = num % size;

    if (hashTable[key].key == num) {
        return hashTable[key].value;
        
    }
    else
    {
        int i = 0;
        while (hashTable[key].key != num){
            ++i;
            key = key + (i*i) + 2*i + 1;
            key = key % size;

        }
        return hashTable[key].value;
    }
    

}

void QashTable::print()
{
    for(int i = 0; i < size; i++){
        if (hashTable[i].key == -1)
        {
            std::cout << i << ": " << hashTable[i].value << '\n';
        }
        else
        {
            std::cout << i << ": " << hashTable[i].value << "   key: " << hashTable[i].key << '\n';
        }
    }
}

void QashTable::clear()
{
    for(int i = 0; i < size; i++){
        //hashTable[i].key = -1;
    }
}

// destructor
QashTable::~QashTable(){
    clear();
    //delete hashTable;
}