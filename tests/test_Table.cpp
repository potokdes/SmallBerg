#include <catch2/catch_test_macros.hpp>
#include "Table.h"
#include <vector>



TEST_CASE("Adding rows to table") {
    auto v = std::vector<std::string>();
    v.push_back("A");
    v.push_back("B");
    v.push_back("C");
    v.push_back("D");
    std::string s =  v.back();
    Table t("test_table");
    t.append_row(v);

    REQUIRE(v == t.get_last_row()); // basic sanity check, expand this!
}


