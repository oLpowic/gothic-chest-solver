#pragma once

#include <memory>

class Block;
enum class MoveDirection;

class DependentBlock {
    MoveDirection moveDirection;
    std::shared_ptr<Block> block;
    
public:
    DependentBlock(std::shared_ptr<Block> block, MoveDirection moveDirection);
    std::shared_ptr<Block> getBlock() const;
    const MoveDirection& getMoveDirection() const;
};