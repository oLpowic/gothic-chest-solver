#pragma once

#include "block.hpp"
#include <memory>

class DependentBlock {
public:    
    bool dependency;
    std::shared_ptr<Block> block;

    DependentBlock(std::shared_ptr<Block> block, bool dependency);
};