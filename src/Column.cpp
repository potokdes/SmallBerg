#include "../include/Column.h"
#include <sstream>

Column::Column(const std::string &name, const std::string &type)
{
    this->name = name;
    this->type = type;
}

std::string Column::get_name()
{
    return name;
}
std::string Column::get_type()
{
    return type;
}
std::string Column::to_string() const
{
    auto stream = std::ostringstream();

    stream << "{\n";
    stream << "\"name\": \"" << name << "\",\n";
    stream << "\"type\": \"" << type << "\"\n";
    stream << "}";
    return stream.str();
}
