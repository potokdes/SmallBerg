#include "../include/Table.h"

Table::Table(const std::string &name){
    this->name = name;
    this->schema = nullptr;

}

std::string Table::get_name()
{
    return name;
}

void Table::add_schema(const Schema &table_schema){
    this->schema = std::make_unique<Schema>(table_schema);

}

Schema Table::get_schema() const{
    return *schema;
}
