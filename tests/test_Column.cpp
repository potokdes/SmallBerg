#include <catch2/catch_test_macros.hpp>
#include "Column.h"
#include <sstream>

TEST_CASE("Should create")
{
    auto c = Column("co1", "int");
}

TEST_CASE("Should return correct json representation of object when called to_string")
{
    auto stream = std::ostringstream();
    auto c = Column("col1", "int");
    stream << "{\n";
    stream << "\"name\": \"col1\",\n";
    stream << "\"type\": \"int\"\n";
    stream << "}";
    auto expoected = stream.str();

    REQUIRE(c.to_string() == expoected);

}
