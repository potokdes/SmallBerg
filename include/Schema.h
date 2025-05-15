#pragma once

#include <map>
#include <memory>
#include "Column.h"

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