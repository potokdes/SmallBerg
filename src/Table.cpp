#include "../include/Table.h"

Table::Table(const std::string &name){
    this->name = name;
    this->rows = std::vector<std::vector<std::string>>();
    this->schema = nullptr;

}

std::string Table::get_name()
{
    return name;
}

void Table::append_row(const std::vector<std::string>& row){
    rows.push_back(row);
}

std::vector<std::string> Table::get_last_row(){
    auto r = this->rows.back();
    return (r);
}

void Table::add_schema(const Schema &table_schema){
    this->schema = std::make_unique<Schema>(table_schema);

}

Schema Table::get_schema() const{
    return *schema;
}
