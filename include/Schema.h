#pragma once

#include <map>
#include <memory>
#include "Column.h"

/// @brief Describes the structure of a table.
/// 
/// Schema contains the definition of all columns in a table. Each schema
/// has a unique identifier and stores its columns by ID. It is responsible
/// for validating column uniqueness and enabling structural introspection.
class Schema
{
public:
    Schema(int schema_id);
    void add_column(const Column &col);
    Column get_column(const std::string &name);
    std::string to_string() const;

private:
    std::map<int, std::shared_ptr<Column>> columns;
    int schema_id;
};