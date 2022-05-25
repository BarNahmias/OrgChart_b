/*
sources:
https://github.com/mission-peace/interview/blob/master/src/com/interview/tree/TreeTraversals.java
https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html
https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
*/
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "Node.hpp"
#include "Iterators.hpp"
namespace ariel
{

    template <class T>
    class OrgChart
    {

//    private:
    public:
        Node<T> * root;


    public:
        OrgChart() : root(nullptr) {
        }

        OrgChart(T data) : root(  new Node<T>(data)) {
        }
        OrgChart(const OrgChart &oc) //copy constructor
        {

            if (oc.root != nullptr)
            {

                root = nullptr;
                add_root(oc.root->data);
                copy_nodes(oc.root);
            }
        }
        ~OrgChart()
        {
            delete_tree(root);
        }

        OrgChart &operator=(const OrgChart &oc) //= operator
        {
            if (this != &oc && root != oc.root)
            {
                if (oc.root != nullptr)
                {
                    delete_tree(root);
                    add_root(oc.root->data);
                    copy_nodes(oc.root);
                }
                else
                {
                    root = nullptr;
                }
            }
            return *this;
        }

        OrgChart(OrgChart &&other) noexcept // move constructor
        {
            this->root = other.root;
            other.root = nullptr;
        }

        OrgChart &operator=(OrgChart &&other) noexcept // move assignment
        {
            if (&this->root != &other.root)
            {
                delete_tree(root);
                this->root = other.root;
                other.root = nullptr;
            }
            return *this;
        }

        /*add root to the tree*/
        OrgChart<T> &add_root(T data)
        {

            if (root == nullptr)
            {
                root = new Node<T>(data);
                std::cout<<"new root "<<std::endl;
                return *this;
            }
            change_data(root, data);
            return *this;
        }

        /*add left son to the parent*/
        OrgChart<T> &add_sub(T parent, T data)
        {
            Node<T> *p = find_node(root, parent);
            if (p == nullptr)
            {
                throw std::invalid_argument{"the node doesn't exist"};
            }

            if (p->child== nullptr){
                p->child = new Node<T>(data);
                return *this;
            }
            Node<T> *t=p->child;
            while (t){
                if(t->next== nullptr) {
                    t->next = new Node<T>(data);
                    return *this;
                }
                t=t->next;

            }
            return *this;
        }




//

//    private:
        /*helper functions*/

        /*copy all nodes from the given node*/
        void copy_nodes(Node<T> *node)
        {
            if (node != nullptr)
            {
                if (node->child != nullptr)
                {
                    add_sub(node->data, node->child->data);
                    copy_nodes(node->child);
                }
                if (node->next != nullptr)
                {
                    add_sub(node->data, node->next->data);
                    copy_nodes(node->next);
                }
            }
        }

        /*delete all the tree that rooted from the given node and reset the root*/
        void delete_tree(Node<T> *node)
        {
            delete_nodes(node);
            root = nullptr;

        }

        /*delete all the tree that rooted from the given node*/
        void delete_nodes(Node<T> *node)
        {
            if (node != nullptr)
            {
                while (node->next!= nullptr || node->child != nullptr)
                {
                    if (node->next != nullptr)
                    {
                        delete_nodes(node->next);
                        node->next = nullptr;
                    }
                    if (node->next != nullptr)
                    {
                        delete_nodes(node->next);
                        node->next = nullptr;
                    }
                }

                if (node->next == nullptr && node->child == nullptr)
                {
                    delete (node);
                }
            }
        }

        Node<T> * get_root(){
            return this->root;
        }


        /*find node in the tree*/
        Node<T> *find_node(Node<T> *node, T data)
        {
            if (node != nullptr)
            {
                if (node->data == data)
                {
                    return node;
                }
                if (node->next != nullptr && node->child == nullptr)
                {
                    return find_node(node->next, data);
                }
                if (node->child != nullptr && node->next != nullptr)
                {
                    Node<T> *temp = find_node(node->next, data);
                    if (temp == nullptr)
                    {
                        return find_node(node->child, data);
                    }
                    return temp;
                }

                if (node->child != nullptr && node->next == nullptr)
                {
                    return find_node(node->child, data);
                }

            }
            return nullptr;
        }


        /*change the data of the given node*/
        void change_data(Node<T> *node, T new_data)
        {
            node->data = new_data;
        }



    public:
        iterator<T> begin_preorder()
        {
            return iterator<T>{order::pre, root};
        }
        iterator<T> end_preorder()
        {
            return iterator<T>{order::pre};
        }

        iterator<T> begin_level_order()
        {
            return iterator<T>{order::level, root};
        }
        iterator<T> end_level_order()
        {
            return iterator<T>{order::level};
        }

        iterator<T> begin_reverse_order()
        {
            return iterator<T>{order::revers, root};
        }
        iterator<T> end_reverse_order()
        {
            return iterator<T>{order::revers};
        }

        iterator<T> begin()
        {
            return begin_level_order();
        }
        iterator<T> end()
        {
            return end_level_order();
        }
    };
}