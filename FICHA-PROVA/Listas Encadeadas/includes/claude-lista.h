#ifndef CLAUDE_LISTA_H
#define CLAUDE_LISTA_H

#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* novo = new Node(val);
        novo->next = head;
        head = novo;
    }

    void insertEnd(int val) {
        Node* novo = new Node(val);
        if (!head) { 
            head = novo; 
            return; 
        }
        Node* curr = head;
        while (curr->next) 
            curr = curr->next;
        curr->next = novo;
    }
    
    void print() {
        Node* curr = head;
        while(curr) {
            std::cout << curr->data << " ->";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }
};

#endif