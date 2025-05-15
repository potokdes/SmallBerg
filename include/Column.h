#pragma once

#include <string>
#include "Column.h"

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