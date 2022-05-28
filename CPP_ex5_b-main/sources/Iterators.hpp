#pragma once
#include <iostream>
#include <stack>
#include <queue>

#include <string>
#include <algorithm>
#include <sstream>
#include "Node.hpp"
#include "OrgChart.hpp"
namespace ariel
{
    enum class order
    {
        pre,
        level,
        revers
    };

    template <typename T>
    class iterator
    {
    private:
        order o;
        Node<T> *curr;
        Node<T> *last_node;
        Node<T> *t_node;
        std::stack<Node<T> *> temp_nodes;
        std::queue<Node<T> *> queue_nodes;
        std::vector<Node<T> *> visit;
        std::vector<Node<T> *>  is_vis;



    public:
        iterator(order o, Node<T> *node = nullptr) : last_node(node), curr(nullptr), o(o)
        {
            if (node != nullptr)
            {
                if (o == order::pre )
                {
                    temp_nodes.push(node);
                }
                if (o == order::level )
                {
                    this->curr=node;
                    if(node->child!= nullptr){
                    queue_nodes.push(node->child);}

                }
                if (o == order::revers )
                {
                    curr=node;
                }
                else{
                    order_by();
                }

            }

        }

        iterator<T> &operator++()
        {
            order_by();
            return *this;
        }
        iterator<T> operator++(int)
        {
            iterator temp = *this;
            order_by();
            return temp;
        }

        T &operator*() const
        {
            return curr->data;
        }

        const T *operator->() const
        {
            return &(curr->data);
        }

        bool operator==(const iterator &other) const
        {
            return curr == (other.curr);
        }

        bool operator!=(const iterator &other) const
        {
            return curr != (other.curr);
        }

    private:
        void order_by()
        {
            switch (o)
            {
            case order::pre:
                pre_order();
                break;
            case order::level:
                level_order();
                break;
            case order::revers:

//                revers_level_order();
                level_order();

                break;
            }
        }
        void pre_order()
        {
            if (!temp_nodes.empty())
            {
                last_node = temp_nodes.top();
                temp_nodes.pop();
                curr = last_node;
                if (last_node->next != nullptr)
                {
                    temp_nodes.push(last_node->next);
                }
                if (last_node->child != nullptr)
                {
                    temp_nodes.push(last_node->child);
                }
            }
            else
            {
                curr = nullptr;
            }
        }

        void level_order() {
            if(curr!= nullptr){
                if (curr->next!= nullptr)
                {
                    curr=curr->next;
                }
                else if (!queue_nodes.empty())
                {
                    curr = queue_nodes.front();
                    queue_nodes.pop();
                }
                else {
                        curr= nullptr;
                    }
                if(curr!= nullptr&&curr->child!= nullptr)
                  {
                      queue_nodes.push(curr->child);
                  }
                }

        }



        void revers_level_order()
        {

        }


        bool is_visit(std::vector<Node<T> *> visit, Node<T> *node){
            return (find(visit.begin(), visit.end(), node) != visit.end());}

//            void  revers( std::vector<Node<T>*> ans , Node<T>* node){
//                while (node!= nullptr){
//                    if (node->next!= nullptr)
//                    {
//                        node=node->next;
//                        ans.push_back(node);
//                    }
//                    else if (!queue_nodes.empty())
//                    {
//                        node = queue_nodes.front();
//                        ans.push_back(node);
//                        queue_nodes.pop();
//                    }
//                    else {
//                        node= nullptr;
//                    }
//                    if(node!= nullptr&&node->child!= nullptr)
//                    {
//                        queue_nodes.push(node->child);
//                    }
//                }
//        }

            std::vector<Node<T>*> revers(Node<T>* node){
            std::vector<Node<T>*> ans;
            std::queue<Node<T>*> queue_node;
            queue_node.push(node);
            while (node!= nullptr){
                if (node->next!= nullptr)
                {
                    node=node->next;
                    ans.push_back(node);
                }
                else if (!queue_node.empty())
                {
                    node = queue_node.front();
                    ans.push_back(node);
                    queue_node.pop();
                }
                else {
                    node= nullptr;
                }
                if(node!= nullptr&&node->child!= nullptr)
                {
                    queue_node.push(node->child);
                }

            }return ans;}

    };
}
