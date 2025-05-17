#include <catch2/catch_test_macros.hpp>
#include "Schema.h"
#include "Column.h"
#include "sstream"

TEST_CASE("Should allow adding and retriving columns")
{
    auto s = Schema(1);
    auto c = Column("col1", DataType::INTEGER);
    s.add_column(c);
    auto col = s.get_column("col1");
    REQUIRE(col.get_name() == "col1");
    REQUIRE(col.get_type() == DataType::INTEGER);

    auto c2 = Column("col2", DataType::INTEGER);
    s.add_column(c2);
    auto col2 = s.get_column("col2");

    REQUIRE(col2.get_name() == "col2");
    REQUIRE(col2.get_type() == DataType::INTEGER);

}


TEST_CASE("Should throw exception when column is not present")
{
    auto s = Schema(1);
    REQUIRE_THROWS(s.get_column("a"));
}

TEST_CASE("Should return correct json representation of object")
{
    auto stream = std::ostringstream();
    auto s = Schema(1);
    auto c1 = Column("col1", DataType::INTEGER);
    auto c2 = Column("col2", DataType::INTEGER);
    s.add_column(c1);
    s.add_column(c2);
    stream << "{\n";
    stream << "\"schema_id\": 1,\n";
    stream << "\"columns\" : \n";
    stream << "[\n";
    stream << "{\n";
    stream << "\"name\": \"col1\",\n";
    stream << "\"type\": \"INTEGER\"\n";
    stream << "},\n";
    stream << "{\n";
    stream << "\"name\": \"col2\",\n";
    stream << "\"type\": \"INTEGER\"\n";
    stream << "}\n";
    stream << "]\n";
    stream << "}\n";
    auto expected = stream.str();

    REQUIRE(s.to_string() == expected);
}
