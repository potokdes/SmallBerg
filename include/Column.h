#pragma once

#include <string>
#include "Column.h"

/// @brief Represents a single column definition within a schema.
/// 
/// A Column holds a name and a type. It defines the data contract
/// for a field in a row and can be extended in the future with
/// metadata like nullability or default values.
class Column
{
public:
    Column(const std::string &name, const std::string &type);
    std::string get_name();
    std::string get_type();
    std::string to_string() const;

private:
    std::string name;
    std::string type;
};