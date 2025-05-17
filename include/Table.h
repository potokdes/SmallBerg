#pragma once

#include <string>
#include <vector>
#include <Schema.h>
#include <Row.h>
/// @brief Represents a logical table abstraction.
///
/// The Table class is the primary entry point to interact with data. It supports
/// row-level operations, schema association, and future metadata functions such as
/// snapshotting or partitioning.
///
/// Internally, it holds a reference to a Schema object and a collection of rows.
class Table
{
public:
    Table(const std::string &name);

    std::string get_name();
    void add_schema(const Schema &table_schema);
    Schema get_schema() const;

private:
    std::string name;
    std::unique_ptr<Schema> schema;
};