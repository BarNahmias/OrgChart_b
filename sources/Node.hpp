#pragma once
#include <iostream>

namespace ariel
{
    template <class T>
    struct Node
    {
    public:

        T data;
        Node <T> * parent ;
        Node <T> * next;
        Node <T> * child;
        Node <T> * perv;
        Node <T> * last_node;

//constructor
        Node() : data(nullptr), parent(nullptr),next(nullptr),child(nullptr),perv(nullptr),last_node(nullptr) {}
        Node(T data) : data(data), parent(nullptr),next(nullptr),child(nullptr),perv(nullptr),last_node(nullptr) {}

//node print
        void printNode(){
            std:: cout<< (this->data);}
    };
}