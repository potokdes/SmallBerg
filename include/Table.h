#pragma once

#include <string>
#include <vector>
#include <Schema.h>
/**
 * This will be the most important domain class and entry point to the whole domain
 * model
 */
class Table
{
public:
    Table(const std::string &name);
    void append_row(const std::vector<std::string> &row);
    // void save();
    std::string get_name();
    void add_schema(const Schema &table_schema);
    std::vector<std::string> get_last_row();
    Schema get_schema() const;

private:
    std::string name;
    std::vector<std::vector<std::string>> rows;
    std::unique_ptr<Schema> schema;
};