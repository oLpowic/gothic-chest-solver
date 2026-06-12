#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "dependent_block.hpp"
#include "moveDirection.hpp"

#define MAX_POSITION 6
#define MIDDLE_POSITION 3

class Block {
    uint16_t blockPosition;
    uint16_t position;
    std::vector<DependentBlock*> blocks;
    
public:
    Block(uint16_t blockPosition, uint16_t position);
    ~Block();

    uint16_t getBlockPosition() const;
    uint16_t getPosition() const;

    std::string to_string() const;
    std::string visualizeBlock() const;
    void moveBlock(MoveDirection move);
    bool isAtMiddle() const;

    bool operator==(const Block& other) const {
        return this->blockPosition == other.blockPosition;
    }
};
