#pragma once

// weird interface include
#include "../../storage_engine/inc/i_storage_engine.h"
#include <vector>
#include "SQLStatement.h"

class Command {
public:
    virtual void execute(st_e::IEngineStorage engine_storage) = 0;
private:
    std::vector<std::shared_ptr<SQLStatement>> statements_;
};
