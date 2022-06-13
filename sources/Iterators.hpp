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



    public:
        iterator(order o, Node<T> *node = nullptr) : last_node(node), curr(nullptr), o(o)
        {
            if (node != nullptr) {

                if (o == order::pre) {
                    temp_nodes.push(node);
                }
                if (o == order::level) {
                    this->curr = node;
                    if (node->child != nullptr) {
                        queue_nodes.push(node);

                    }
                }
                    order_by();

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



    };
}
