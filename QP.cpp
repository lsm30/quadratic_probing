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
// NOTE: due to templating methods, this program must be run at a standard of c++17 or newer
// If it must be run on c++11, you have to manually declare the type of each Data struct.

#include "QP.hpp"
#include <iostream>

// constructor
QashTable::QashTable(int num)
{
    this->size = num;
    hashTable = static_cast<Data<std::string>*>(::operator new[](num*sizeof(Data<std::string>)));
    for(int i = 0; i < size; i++){
        ::new (hashTable+i) Data<std::string>(-1, static_cast<std::string>("null"));
    }
}

// insert string
void QashTable::insert(Data<std::string> data){
    // key and i are set to long long and uint to avoid seg faults with large arrays
    long long key = data.key % size;

    if (hashTable[key].key == -1) {
        hashTable[key].key = data.key;
        hashTable[key].value = data.value;
        
    }
    else
    {
        uint i = 0;
        while (hashTable[key].key != -1){
            ++i;
            key = key + 2*(i*i) + 2*i + 1;
            key = key % size;

        }
        if (input_length < i) {
            input_length = i;
        }
        hashTable[key].key = data.key;
        hashTable[key].value = data.value;
    }
    

}

// insert char*
void QashTable::insert(Data<char const*> data){
    long long key = data.key % size;

    if (hashTable[key].key == -1) {
        hashTable[key].key = data.key;
        hashTable[key].value = static_cast<std::string>(data.value);
        
    }
    else
    {
        uint i = 0;
        while (hashTable[key].key != -1){
            ++i;
            key = key + 2*(i*i) + 2*i + 1;
            key = key % size;

        }
        if (input_length < i) {
            input_length = i;
        }
        hashTable[key].key = data.key;
        hashTable[key].value = static_cast<std::string>(data.value);
    }
    

}

// insert used to test most efficient quadratic function
void QashTable::insertTest(Data<std::string> data, int a, int b, int c){
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
            key = key + a*(i*i) + b*i + c;
            key = key % size;
            if (i > 100000)
            {
                std::cout << "stuck in loop" << '\n';
                return;
            }
        }
        std::cout << "probes: " << i << '\n';
        if (input_length < i) {
            input_length = i;
        }
        hashTable[key].key = data.key;
        hashTable[key].value = data.value;
    }
    

}

// search
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
            key = key + 2*(i*i) + 2*i + 1;
            key = key % size;
            if (i > input_length) {
                return static_cast<std::string>("not found");
            }

        }
        return hashTable[key].value;
    }
}

// print
void QashTable::print()
{
    for(int i = 0; i < size; i++){
        if (hashTable[i].key == -1)
        {
            std::cout << i << ": " << '\n';
        }
        else
        {
            std::cout << i << ": " << "key: " << hashTable[i].key << "\tvalue: " << hashTable[i].value << '\n';
        }
    }
}

// clear
void QashTable::clear()
{
    for(int i = 0; i < size; i++){
        hashTable[i].key = -1;
    }
}

// destructor
QashTable::~QashTable(){
    clear();
}