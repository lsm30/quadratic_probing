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

#include <string>

template<class T>
struct Data
{
    int key;
    T value;
    Data(int key, T value)
    {
        this->key = key;
        this->value = value;
    }
};

class QashTable
{
public:
    QashTable(int);
    void insert(Data<std::string>);
    std::string search(int);
    void print();
    void clear();
    virtual ~QashTable();
private:
    int size;
    Data<std::string>* hashTable;

};

template class Data<int>;
template class Data<unsigned int>;
template class Data<char>;
template class Data<double>;
template class Data<float>;
template class Data<std::string>;

#endif
