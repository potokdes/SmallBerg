#include <catch2/catch_test_macros.hpp>
#include "Table.h"
#include "Schema.h"
#include <vector>

TEST_CASE("Table should take allow to have schema assosiated with it")
{
    auto s = Schema(1);
    s.add_column(Column("test_col1", "test_col2"));
    auto t = Table("test_table");
    t.add_schema(s);
}

TEST_CASE("Table should return the copy of the schema for viewing if requested")
{
    /**
     * The idea here is that schema should be notmutable. Any changes to schema should be done
     * troug Table object and generate new metadata file.
     */
    auto s = Schema(1);
    s.add_column(Column("test_col1", "test_col2"));
    auto t = Table("test_table");
    t.add_schema(s);
    // This should return the copy of the schema so mofiding it
    // should not have any effect on the schema acctalu referenced by the table
    auto s1 =  t.get_schema();
    s1.add_column(Column("test_col2", "int"));

    // The schema on the table should not be modified
    auto s2 = t.get_schema();
    REQUIRE_THROWS(s.get_column("test_col2"));
   
}
