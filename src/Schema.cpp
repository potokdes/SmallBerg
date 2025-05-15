
#include "Schema.h"
#include "sstream"

Schema::Schema(int schema_id)
{
    this->schema_id = schema_id;
    this->columns = std::map<int, std::shared_ptr<Column>>();
}

void Schema::add_column(const Column &col)
{
    int index = columns.size();
    columns[index] = std::make_shared<Column>(col);
}

Column Schema::get_column(const std::string &name)
{

    for (auto &p : columns)
    {
        if ((*p.second).get_name() == name)
        {
            return *p.second;
        }
    }
    throw std::runtime_error("Column not present in schema");
}

std::string Schema::to_string() const
{

    auto stream = std::ostringstream();
    stream << "{\n";
    stream << "\"schema_id\": " << schema_id << ",\n";
    stream << "\"columns\" : \n";
    stream << "[\n";
    // TODO: Schema have to make sure that there are not gaps in the order of columns
    // other wise this approach will not work
    for (int i = 0; i < columns.size(); i++)
    {
        auto col = columns.find(i)->second;
        stream << col->to_string();
        if (i + 1 < columns.size())
        {
            stream << ",";
        }
        stream << "\n";
    }
    stream << "]\n";
    stream << "}\n";
    return stream.str();
}
