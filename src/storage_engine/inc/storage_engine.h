#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <string>
#include "shared_table.h"
#include "data_block.h"
#include "table_chunk.h"

namespace st_e {

class StorageEngine {
public:
    StorageEngine( const StorageEngine&) = delete;
    StorageEngine& operator=(StorageEngine&) = delete;

    static StorageEngine& get_instance();

    void add_table(const Table& table);
//    bool delete_table(std::string table_name);

    const Table& get_table_by_name(const std::string& table_name);

    void insert(const std::string& table_name, const std::vector<TableRow>& rows);

//    SelectAnswer select(std::string table_name, std::vector<std::string> columns_names) override;
//    SelectAnswer select_all(std::string table_name) override;
//

private:
    StorageEngine() = default;

    SharedTable& tables_ = SharedTable::get_instance();
    DataBlock last_data_block;

    void load_last_block(const std::string& table_name);
//    void create_block

};

}//namespace st_e
