#include "../include/Table.h"
#include <iostream>
// cmake .. -DCMAKE_CXX_COMPILER=clang++
int main()
{
    Table t("Table");
    std::cout << t.get_name() << std::endl;
}