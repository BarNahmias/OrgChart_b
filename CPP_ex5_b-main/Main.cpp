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


        co->add_sub("ELI","LINOY");
        co->add_sub("ELI","BAR");
        co->add_sub("ELI","ORIYA");
        co->add_sub("BAR","AVIGAIL");
        co->add_sub("BAR","ARIEL");
        co->add_sub("ORIYA","YONATAN");
        co->add_sub("ARIEL","DALIYA");


//        for (auto it = oc->begin_level_order(); it != oc->end_level_order(); it++) {
//            cout<< (*it)<<endl;
//        }
//
//            for (auto it = co->begin_level_order(); it != co->end_level_order(); ++it){
//                cout<< (*it)<<endl;}
//
////            for (auto it = oc->begin_preorder(); it != oc->end_preorder(); ++it){
////                cout<< (*it)<<endl;
////
                for (auto it = oc->begin_reverse_order(); it != oc->end_reverse_order(); ++it){
                    cout<< (*it)<<endl;}





        return 0;

    }
