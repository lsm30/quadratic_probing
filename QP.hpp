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
#ifndef PROJECT3_QP_H
#define PROJECT3_QP_H

#include <iostream>
#include <string>

class QashTable
{
public:
    QashTable(int);
    void insert(int);
    void print();
    void clear();
private:
    int size;
    int* hashTable;

};



#endif
