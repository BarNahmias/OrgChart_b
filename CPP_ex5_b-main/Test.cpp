//
// Created by בר נחמיאס on 25/05/2022.
//

#include "sources/Node.hpp"
#include "sources/OrgChart.hpp"

using namespace ariel ;
using namespace std ;


TEST_CASE("add && root") {
    OrgChart<int> *oc = new OrgChart<int>(1);
    OrgChart <string> *co = new OrgChart<string>("ELI");


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


    TEST_CASE("find") {
        CHECK_THROW(co->find("ELI", "DANA"));
                CHECK_EQ(co->find("ELI", "BAR")->data, "BAR");
        CHECK_THROW(oc->find(1, 13));
                CHECK_EQ(oc->find(1, 6)->data, 6);
    }

    TEST_CASE("pre order for stirng") {
        std::vector<std::string> v = {"ELI", "LINOY", "BAR", "AVIGAIL", "ARIEL", "DALIYA", "ORIYA", "YONATAN"};
        size_t i = 0;
        for (auto it = co.begin_preorder(); it != co.end_preorder(); ++it) {
                    CHECK_EQ(*it, v.at(i++));
        }
    }
    TEST_CASE("pre order for int") {
    std::vector<std::string> v = {1,2,4,5,6,3,7,8};
    size_t i = 0;
    for (auto it = oc.begin_preorder(); it != oc.end_preorder(); ++it) {
    CHECK_EQ(*it, v.at(i++));
}
    }

TEST_CASE("level order for stirng") {
std::vector<std::string> v = {"ELI", "LINOY", "BAR", "ORIYA", "AVIGAIL", "ARIEL", "YONATAN", "DALIYA"};
size_t i = 0;
for (auto it = co.begin_preorder(); it != co.end_preorder(); ++it) {
CHECK_EQ(*it, v.at(i++));
}
    }
TEST_CASE("level order for int") {
std::vector<std::string> v = {1,2,3,4,5,6,7,8};
size_t i = 0;
for (auto it = oc.begin_preorder(); it != oc.end_preorder(); ++it) {
CHECK_EQ(*it, v.at(i++));
}

    }


TEST_CASE("revers order for stirng") {
std::vector<std::string> v = {"ELI", "LINOY", "BAR", "ORIYA", "AVIGAIL", "ARIEL", "YONATAN", "DALIYA"};
size_t i = 0;
for (auto it = co.begin_preorder(); it != co.end_preorder(); ++it) {
CHECK_EQ(*it, v.at(i++));
}
}
TEST_CASE("revers order for int") {
std::vector<std::string> v = {1,2,3,4,5,6,7,8};
size_t i = 0;
for (auto it = oc.begin_preorder(); it != oc.end_preorder(); ++it) {
CHECK_EQ(*it, v.at(i++));
}

}
}
