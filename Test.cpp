//
// Created by בר נחמיאס on 25/05/2022.
//

#include "doctest.h"
#include <iostream>
#include <string>
#include <vector>
#include "sources/Node.hpp"
#include "sources/OrgChart.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>



using namespace ariel ;
using namespace std ;


TEST_CASE("orgchart") {

////   check "add && root"

//oc is tree <int>
    OrgChart<int> *oc = new OrgChart<int>(1);

//co is tree <string>
    OrgChart <string> *co = new OrgChart<string>("ELI");
//    empty tree
    OrgChart <string> *empty_tree = new OrgChart<string>();
    OrgChart <int> *empty_int = new OrgChart<int>();

////add sub before add root
//            CHECK_THROWS(empty_int->add_sub(1, 2));


    CHECK_NOTHROW(oc->add_root(1));
    CHECK_NOTHROW(oc->add_sub(1, 2));
    CHECK_NOTHROW(oc->add_sub(1, 3));
    CHECK_NOTHROW(oc->add_sub(2, 4));
    CHECK_NOTHROW(oc->add_sub(2, 5));
    CHECK_NOTHROW(oc->add_sub(2, 6));
    CHECK_NOTHROW(oc->add_sub(3, 7));
    CHECK_NOTHROW(oc->add_sub(3, 8));

    CHECK_NOTHROW(co->add_sub("ELI", "LINOY"));
    CHECK_NOTHROW(co->add_sub("ELI", "BAR"));
    CHECK_NOTHROW(co->add_sub("ELI", "ORIYA"));
    CHECK_NOTHROW(co->add_sub("BAR", "AVIGAIL"));
    CHECK_NOTHROW(co->add_sub("BAR", "ARIEL"));
    CHECK_NOTHROW(co->add_sub("ORIYA", "YONATAN"));
    CHECK_NOTHROW(co->add_sub("ARIEL", "DALIYA"));



///   check find function

        CHECK_EQ(co->find_node(co->root, "BAR")->data, "BAR");
        CHECK_EQ(oc->find_node(oc->root, 6)->data, 6);


///   check pre order for string
        std::vector<std::string> v = {"ELI", "LINOY", "BAR", "AVIGAIL", "ARIEL", "DALIYA", "ORIYA", "YONATAN"};
        size_t i = 0;
        for (auto it = co->begin_preorder(); it != co->end_preorder(); ++it) {
                    CHECK_EQ(*it, v.at(i++));
        }


///   check pre order for int
 std::vector<int> v1 = {1,2,4,5,6,3,7,8};
    size_t i1 = 0;
    for (auto it = oc->begin_preorder(); it != oc->end_preorder(); ++it) {
    CHECK_EQ(*it, v1.at(i1++));}



///   check "level order for stirng"
std::vector<std::string> v2 = {"ELI", "LINOY", "BAR", "ORIYA", "AVIGAIL", "ARIEL", "YONATAN", "DALIYA"};
size_t i2 = 0;
for (auto it = co->begin_level_order(); it != co->end_level_order(); ++it) {
CHECK_EQ(*it, v2.at(i2++));}



//// check "level order for int")
std::vector<int> v3 = {1,2,3,4,5,6,7,8};
size_t i3 = 0;
for (auto it = oc->begin_level_order(); it != oc->end_level_order(); ++it) {
CHECK_EQ(*it, v3.at(i3++));}


//// check "level order for string
std::vector<std::string> v4 = {"ELI", "LINOY", "BAR", "ORIYA", "AVIGAIL", "ARIEL", "YONATAN", "DALIYA"};
unsigned i4 = 0;
for (auto it = co->begin_level_order(); it != co->end_level_order(); ++it) {
CHECK_EQ(*it, v4.at(i4++));}

//// check "level revers for int

std::vector<int> v5 = {13,12,11,10,9,8,7,6,5,4,3,2,1};
size_t i5 = 0;
for (auto it = oc->begin_preorder(); it != oc->end_preorder(); ++it) {
CHECK_EQ(*it, v5.at(i5++));}
//}

/// check "level order for string empty tree") {

//           CHECK_THROWS( empty_tree->begin_level_order());

}
