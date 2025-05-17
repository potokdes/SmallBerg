#include <catch2/catch_test_macros.hpp>
#include "Column.h"
#include "data_type.h"
#include <sstream>

TEST_CASE("Should create and return correct informations from object")
{
    auto c = Column("col1", DataType::INTEGER);
    REQUIRE( "col1" == c.get_name());
    REQUIRE( DataType::INTEGER == c.get_type());
}

TEST_CASE("Should return correct json representation of object when called to_string")
{
    auto stream = std::ostringstream();
    auto c = Column("col1", DataType::INTEGER);
    stream << "{\n";
    stream << "\"name\": \"col1\",\n";
    stream << "\"type\": \"INTEGER\"\n";
    stream << "}";
    auto expoected = stream.str();

    REQUIRE(c.to_string() == expoected);

}
