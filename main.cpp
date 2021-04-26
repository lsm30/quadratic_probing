

#include "QP.hpp"
// #include "QP.cpp"
#include "Nick.cpp"
#include "doubleHash.cpp"
#include <ctime>
#include <iostream>
#include <string>

// Linear probing code provided by Nicklaus Walsh
// Double hashing code provided by Daniel Dorazio
void testSize() {
    for (int j = 1000; j <= 10000; j=j+1000)
    {
        int size = j*1;

        Map *testmap = new Map;

        std::string test = "test";
        Data data(1,test);
        QashTable table(size);

        doubleHash h;

        clock_t start, start1, start2;
        start = clock();
        for (int i = 0; i < size; i++)
        {
            testmap->Insert(1, 10000);
        }
        double t1 = (double)(clock() - start) / CLOCKS_PER_SEC;

        start2 = clock();
        for (int i = 0; i < size; i++)
        {
            table.insert(data);
        }
        double t2 = (double)(clock() - start2) / CLOCKS_PER_SEC;

        start1 = clock();
        for (int i = 0; i < size; i++)
        {
            h.insert(10000);
        }
        double t3 = (double)(clock() - start1) / CLOCKS_PER_SEC;

        std::cout << "Size:\t\t" << size << '\n';

        std::cout << "linear:\t\t" << t1 << '\n';

        std::cout << "quadratic:\t" << t2 << '\n';

        std::cout << "double hash:\t" << t3 << "\n\n";

    }
}

void testLoad() {
    for (int j = 9; j < 10; j++)
    {
        int size = 1000000;
        double preload = .1 * j;

        Map *testmap = new Map;

        std::string test = "test";
        Data data(1,test);
        QashTable table(size);

        doubleHash h;

        clock_t start, start1, start2;
        for (int i = 0; i < size*preload; i++)
        {
            testmap->Insert(1, 10000);
        }
        start = clock();
        for (int i = 0; i < 1000; i++)
        {
            testmap->Insert(1, 10000);
        }
        double t1 = (double)(clock() - start) / CLOCKS_PER_SEC;

        for (int i = 0; i < size*preload; i++)
        {
            table.insert(data);
        }
        start2 = clock();
        for (int i = 0; i < 1000; i++)
        {
            table.insert(data);
        }
        double t2 = (double)(clock() - start2) / CLOCKS_PER_SEC;

        for (int i = 0; i < size*preload; i++)
        {
            h.insert(10000);
        }
        start1 = clock();
        for (int i = 0; i < 1000; i++)
        {
            h.insert(10000);
        }
        double t3 = (double)(clock() - start1) / CLOCKS_PER_SEC;

        std::cout << "Preload:\t" << j*10 << "% \n";

        std::cout << "linear:\t\t" << t1 << '\n';

        std::cout << "quadratic:\t" << t2 << '\n';

        std::cout << "double hash:\t" << t3 << "\n\n";

    }
}

void testDoubleHash()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(a) / sizeof(a[0]);
    doubleHash h;
    for (int i = 0; i < n; i++) {
        h.insert(a[i]);
    }
    h.search(11);
    h.search(50);
    h.display();
}

void testLinear()
{
    clock_t timer1 = 0;
    
    Map *testmap = new Map;

    for (int i = 0; i < testmap->MaxSize; i++)
    {
        testmap->Insert(i, i);
    }
    testmap->PrintMap();
    
    for (int i = 0; i < testmap->MaxSize; i++)
    {
        cout << testmap->DeleteNode(i) << endl;
    }
    testmap->PrintMap();

}

int main(){
    testLoad();
    // testLinear();
    // testDoubleHash();
    // std::string hey = "hey";
    // Node noder(11, 11);
    // Map* map = new Map;
    // map->Insert(11, 11);
    // Data data(11,hey);
    // Data data(1,"can you believe it?");
    // QashTable table(10);
    // table.insert(data);
    // table.insert(data);
    // table.insert(data);
    // table.insert(data);
    // table.insert(data);
    // table.insert(data);
    // table.insert(data);
    // table.insert(data);
    // table.insert(data);
    // table.insert(data1);
    // table.print();
    // std::cout << table.search(1);

    return 0;
}