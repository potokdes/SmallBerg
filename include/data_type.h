#pragma once

#include <string>
#include <stdexcept>

enum class DataType
{
    STRING,
    INTEGER,
    BOOLEAN,
    FLOAT,
    DOUBLE,
    // Add more types as needed
};

inline std::string data_type_to_string(const DataType &type)
{
    switch (type)
    {
    case DataType::INTEGER:
        return "INTEGER";
    case DataType::STRING:
        return "STRING";
    default:
        throw std::invalid_argument("Data type not supported by to string function");
    }
}
