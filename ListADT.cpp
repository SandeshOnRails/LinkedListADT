//
//  ListADT.cpp
//  
//
//  Created by Sandesh Basnet on 11/28/17.
//
//

#include "ListADT.h"
#include <iostream>

using namespace std;

ListADT::ListADT():head(nullptr), size(0){}

// Counstructor whith head initialization

// Copy Constructor
ListADT::ListADT(const ListADT& rhs){
    
    if(rhs.head == nullptr){
        head = nullptr;
        size = 0;
    }
    else {
        
        head = new Node();
        Node* rhsHead = rhs.head;
        Node* link = head;
        link->value = rhsHead->value;
        rhsHead = rhsHead->next;
        size = 1;
        while(rhsHead != nullptr){
            Node* newNode = new Node();
            newNode->value = rhsHead->value;
            link->next = newNode;
            link = link->next;
            rhsHead = rhsHead->next;
            size++;
        }
        link->next = nullptr;
    }
    
}

// Destructor
ListADT::~ListADT()	{
    // clear all elements
    deletelist();
}


// Assignment operator overloading
ListADT& ListADT::operator=(const ListADT& rhs){
    
    if(head == rhs.head){
        return *this;
    }
    
    if(rhs.head == nullptr){
        deletelist();
        return *this;
    }
    
    deletelist();
    head = new Node();
    Node* rhsHead = rhs.head;
    Node* link = head;
    link->value = rhsHead->value;
    rhsHead = rhsHead->next;
    size = 1;
    while(rhsHead != nullptr){
        Node* newNode = new Node();
        newNode->value = rhsHead->value;
        link->next = newNode;
        link = link->next;
        rhsHead = rhsHead->next;
        size++;
    }
    link->next = nullptr;
    return *this;
}


// return size of the list
int ListADT::length() const{
    return size;
}

    // insert node at the front of the list
void ListADT::insert_front(const int newItem){
    Node* newNode = new Node();
    newNode->item = newItem;
    newNode->next = head;
    head = newNode;
    size++;
}


// insert node at the back of the list
void ListADT::push_back(int value){
    
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;
    size++;
    
    if(head == nullptr){
        head = newNode;
        return;
    }
    
    // looking for last node
    Node* last_node = head;
    while(last_node->next != NULL)
        last_node = last_node->next;
    // link newNode after last node
    last_node->next = newNode;
}


// remove first element from the list
void ListADT::pop_front() {
    if(head == NULL)
        return;
    Node* node_to_delete = head;
    head = head->next;
    delete node_to_delete;
    size--;
}


// remove last element from the list
void ListADT::pop_back() {
    if(head == NULL)
        return;
    
    if (head->next == NULL) { // list contains one element
        delete head;
        head = NULL;
        size = 0;
        return;
    }
    
    // looking for prelast element
    Node* prev_element = head;
    Node* last_node = prev_element->next;
    while (last_node->next != nullptr) {
        prev_element = last_node;
        last_node = last_node->next;
    }
    prev_element->next = nullptr;
    delete last_node;
    size--;
}

// removes element and all its copies from the list

// returns M to last element in the list


// return true if list is empty
bool ListADT::isEmpty() {
    return (head == NULL);
}

// looking for value in the list	(return true if found)



// delete all elements from the list
void ListADT::deletelist(){
    if(head == NULL)
        return;
    Node* current = head;
    while(current != NULL){
        Node* node_to_delete = current;
        current = current->next;
        delete node_to_delete;
    }
    head = NULL;
    size = 0;
}

// reverse list


// overload operator << to print out all data items
ostream& operator<< (ostream & ofs, ListADT const & list) {
    
    if(list.head == NULL) {
    } else {
        ListADT::Node* current = list.head;
        while (current->next != NULL){
            ofs << current->value << ", ";
            current = current->next;
        }
        ofs << current->value;
    }
    return ofs;
}


int ListADT::operator[](int i){
    if(this->head != nullptr){
        ListADT::Node* temp = head;
        int j =0;
        while(temp!= nullptr){
            if(i == j)
                return temp->value;
            j++;
            temp=temp->next;
            
        }
    }
    return 0;
}













