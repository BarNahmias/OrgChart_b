//
// Created by בר נחמיאס on 24/05/2022.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "sources/Node.hpp"
#include "sources/OrgChart.hpp"


using namespace ariel ;
using namespace std ;


std::vector<Node<int>*> revers(Node<int>* node){
    std::vector<Node<int>*> ans;
    std::queue<Node<int>*> queue_node;
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


    }
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout<< (*it)->data<<endl;}
    cout<< "------"<<endl;

    return ans;}


    int main() {

    OrgChart<int>  *oc = new OrgChart<int>(1) ;
    OrgChart<string>  *co = new OrgChart<string>("ELI") ;


    oc->add_root(1);

    oc->add_sub(1,2);
        oc->add_sub(1,3);
        oc->add_sub(2,4);
        oc->add_sub(2,5);
        oc->add_sub(2,6);
        oc->add_sub(3,7);
        oc->add_sub(3,8);
        oc->add_sub(4,9);
        oc->add_sub(4,10);
        oc->add_sub(6,11);
        oc->add_sub(8,12);
        oc->add_sub(8,13);

 //// FIND NODE
//        cout<< "------"<<endl;
//        oc->find_node(oc->root,8)->parent->printNode();
//        cout<< ""<<endl;
//        cout<< "------"<<endl;
//        cout<< "------"<<endl;
//        oc->find_node(oc->root,3)->parent->printNode();
//        cout<< ""<<endl;
//        cout<< "------"<<endl;

        //// ADD ROOT &  NODES

        co->add_sub("ELI","LINOY");
        co->add_sub("ELI","BAR");
        co->add_sub("ELI","ORIYA");
        co->add_sub("BAR","AVIGAIL");
        co->add_sub("BAR","ARIEL");
        co->add_sub("ORIYA","YONATAN");
        co->add_sub("ARIEL","DALIYA");

////RETURN NODE DATA WHEN USE find METHOD

//        cout<< "------"<<endl;
//        cout<< co->find_node(co->root,"BAR")->perv->data<<endl;
//        cout<< "------"<<endl;



////RETURN level_order ITERATOR for int
//        cout<< "------"<<endl;
//        for (auto it = oc->begin_level_order(); it != oc->end_level_order(); it++) {
//            cout<< (*it)<<" ";}
//        cout<< "------"<<endl;

////RETURN level_order ITERATOR AFTER REMOVE NODE

//        oc->delete_nodes(oc->find_node(oc->root,3));
//        cout<< "------"<<endl;
//        for (auto it = oc->begin_level_order(); it != oc->end_level_order(); ++it){
//            cout<< (*it)<<endl;}
//        cout<< "------"<<endl;




////RETURN level_order ITERATOR for string
        cout<< "------"<<endl;
            for (auto it = co->begin_level_order(); it != co->end_level_order(); ++it){
                cout<< (*it)<<" ";}
        cout<< "------"<<endl;
//


////RETURN preorder ITERATOR
        cout<< "------"<<endl;
        for (auto it = co->begin_preorder(); it != co->end_preorder(); ++it){
            cout<< (*it)<<" ";}
        cout<< "------"<<endl;


//////RETURN preorder ITERATOR AFTER REMOVE NODE
//        co->delete_nodes(co->find_node(co->root,"BAR"));
//        cout<< "------"<<endl;
//        for (auto it = co->begin_level_order(); it != co->end_level_order(); ++it){
//            cout<< (*it)<<endl;}
//        cout<< "------"<<endl;



////RETURN preorder ITERATOR AFTER REMOVE NODE

//        cout<< "------"<<endl;
//            for (auto it = co->begin_preorder(); it != co->end_preorder(); ++it){
//                cout<< (*it)<<endl;}
//        cout<< "------"<<endl;
//        co->delete_nodes(co->find_node(co->root,"BAR"));
//        cout<< "------"<<endl;
//
//        for (auto it = co->begin_preorder(); it != co->end_preorder(); ++it){
//            cout<< (*it)<<endl;}
//        cout<< "------"<<endl;




////RETURN reverse_order ITERATOR for int
               cout<< "------"<<endl;
                for (auto  it = co->begin_reverse_order(); it != co->reverse_order(); ++it){
                    cout<< *it <<" ";}
               cout<< "------"<<endl;

        return 0;

    }
