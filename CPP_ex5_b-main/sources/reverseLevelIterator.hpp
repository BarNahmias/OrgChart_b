//
// Created by בר נחמיאס on 28/05/2022.
//

#pragma once
#include <iostream>
#include <stack>
#include <queue>

#include <string>
#include <algorithm>
#include <sstream>
#include "Node.hpp"
#include "OrgChart.hpp"


namespace ariel {
    template<typename T>
    class reverseLevelIterator {

    private:
        Node<T> *curr;
        Node<T> *last_node;
        std::stack<Node<T> *>
                temp_nodes;
        std::queue<Node<T> *>
                queue_nodes;
        std::vector<Node<T> *>
                visit;
        typename std::vector<Node <T>*>::iterator it ;

        unsigned size=0;

    public:
        reverseLevelIterator(Node<T> *node = nullptr) : curr(nullptr) {
            this->curr = node;
            if (node->child != nullptr) {
                queue_nodes.push(node->child);
               visit= revers(curr);
               it=visit.at(size);
               std::cout<<"const"<<std::endl;
            }
        }

        reverseLevelIterator<T> &operator++() {
            size++;
            return *this;
        }

        reverseLevelIterator<T> operator++(int) {
            reverseLevelIterator temp = *this;
            size++;
            return temp;
        }

        T &operator*() const {
            return (*it)->data;
        }

        const T *operator->() const {
            return &((*it)->data);
        }

        bool operator==(const reverseLevelIterator &other) const {
            return (it) == (other.it);
        }

        bool operator!=(const reverseLevelIterator &other) const {

            std::cout<<(*it) <<std::endl;
            return (*it) != *(other.it);
        }




        std::vector<Node<T> *> revers(Node<T> *node) {
            std::vector < Node<T> * > ans;
            std::queue < Node<T> * > queue_node;
            queue_node.push(node);
            while (node != nullptr) {
                if (node->next != nullptr) {
                    node = node->next;
                    ans.push_back(node);
                } else if (!queue_node.empty()) {
                    node = queue_node.front();
                    ans.push_back(node);
                    queue_node.pop();
                } else {
                    node = nullptr;
                }
                if (node != nullptr && node->child != nullptr) {
                    queue_node.push(node->child);
                }
                reverse(ans.begin(), ans.end());

            }
            return ans;
        }


    };


}