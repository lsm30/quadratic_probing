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
#include <bitset>

QashTable::QashTable(int num)
{
    this->size = num;
    //int table[size];
    //this->hashTable = table;
    hashTable = new int[size];
    for(int i = 0; i < size; i++){
        hashTable[i] = 0;
    }
}

void QashTable::insert(int num){
    int key = num % size;

    if (hashTable[key] == 0) {
        hashTable[key] = num;
        
    }
    else
    {
        int i = 0;
        while (hashTable[key] != 0){
            ++i;
            key = key + (i*i) + 2*i + 1;
            key = key % size;

        }
        hashTable[key] = num;
    }
    

}

void QashTable::print()
{
    for(int i = 0; i < size; i++){
        std::cout << i << ": " << hashTable[i] << '\n';
    }
}

int main(){

    // just for testing purposes. Main will be a separate program for my final submission.
    QashTable table(10);
    table.insert(9);
    table.insert(3);
    table.insert(4);
    table.print();

    return 0;
}