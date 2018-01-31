//
//  ListADT.hpp
//  
//
//  Created by Sandesh Basnet on 11/28/17.
//
//

#ifndef ListADT_h
#define ListADT_h

#include <stdio.h>
#include <iostream>
using namespace std;

class ListADT{
    
class Node {
public:
    Node(){
        this->value = 0;
        this->next = NULL;
    }
    Node(int val){
    this->value = val;
    this->next = NULL;
    }
    int value;
    Node* next;
   };
   

    Node* head;
    int size;
public:
    ListADT();
    ~ListADT();
    ListADT(const ListADT& list);
   ListADT& operator = (const ListADT &list );
    int operator[](int i);
    friend ostream& operator<< (ostream& os, const ListADT& l);
        void push_back(int val);
        void push_front(int val);
        void pop_back();
        void pop_front();
        int length() const;
    bool isEmpty();
    void deletelist();
    
    };
#endif /* ListADT_hpp */
