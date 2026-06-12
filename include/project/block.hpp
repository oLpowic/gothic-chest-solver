#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "dependent_block.hpp"
#include "moveDirection.hpp"

#define MAX_POSITION 6
#define MIDDLE_POSITION MAX_POSITION/2

class Block {
private:
    uint16_t blockPosition;
    uint16_t position;
    std::vector<DependentBlock*> dependentBlocks;

    void makeMove(MoveDirection move);
    bool canMoveBlocks(MoveDirection move) const; 
    void applyMoveBlocks(MoveDirection move);
    
public:
    Block(uint16_t blockPosition, uint16_t position);
    ~Block();

    uint16_t getBlockPosition() const;
    uint16_t getPosition() const;

    std::string to_string() const;
    std::string visualizeBlock() const;
    const bool isMovePossible(MoveDirection move) const;
    const bool isAtMiddle() const;
    bool moveBlocks(MoveDirection move);

    bool operator==(const Block& other) const {
        return this->blockPosition == other.blockPosition;
    }
};
