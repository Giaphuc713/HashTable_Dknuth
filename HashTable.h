#pragma once
#include <iostream>
#include <fstream>
#include<cmath>
#define warning (disable:4996)
using namespace std;
template<class T>
class HashTable {
private:
    struct Node {
        T key;
        Node* next;
        Node(T k) {
            key = k;
            next = nullptr;
        }
    };
    int size;                      //size HashTable (m)
    Node** table;                 //HashTable
    const char* outputFile;      // output filepath
    int indexInsert = 0;        //Used to enter insert index in file
    int indexSearch = 0;       //Used to enter search index in file
   
        
       

public:
   
    HashTable(int m, const char* outputFileName);
    
    // Hash function using Knuth's method
    T hashFunction(T key);
      
    // Helper function to add a new node to the tail of a linked list
    void addTail(Node*& head, T key);
 
    ~HashTable();
   
    void Insert(T key);

    void Search(T key);
};


