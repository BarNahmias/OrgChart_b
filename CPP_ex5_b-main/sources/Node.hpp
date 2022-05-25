#pragma once
#include <iostream>
#include <string>
#include <vector>

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
        Node <T> * last_child;


        Node() : data(nullptr), parent(nullptr),next(nullptr),child(nullptr),last_child(nullptr) {}
        Node(T data) : data(data), parent(nullptr),next(nullptr),child(nullptr),last_child(nullptr) {}



        void printNode(){
            std:: cout<< (this->data);}
    };
}