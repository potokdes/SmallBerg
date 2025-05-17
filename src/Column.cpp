#include "../include/Column.h"
#include <sstream>

Column::Column(const std::string &name, const DataType &type)
{
    this->name = name;
    this->type = type;
}

std::string Column::get_name()
{
    return name;
}
DataType Column::get_type()
{
    return type;
}
std::string Column::to_string() const
{
    auto stream = std::ostringstream();

    stream << "{\n";
    stream << "\"name\": \"" << name << "\",\n";
    stream << "\"type\": \"" << data_type_to_string(type) << "\"\n";
    stream << "}";
    return stream.str();
}
