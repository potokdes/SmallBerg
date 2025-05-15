#pragma once

#include <string>
#include <vector>

class Table
{
public:
    Table(const std::string &name);
    void append_row(const std::vector<std::string> &row);
    // void save();
    std::string get_name();
    std::vector<std::string> get_last_row();

private:
    std::string name;
    std::vector<std::vector<std::string>> rows;
};