#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "dependent_block.hpp"

class Block {
public:
    uint16_t blockPosition;
    uint16_t position;
    std::vector<DependentBlock*> blocks;

    Block(uint16_t blockPosition, uint16_t position);
    ~Block();

    std::string to_string() const;
    std::string visualizeBlock() const;
};
