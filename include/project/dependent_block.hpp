#pragma once

class Block;
enum class MoveDirection;

class DependentBlock {
    MoveDirection moveDirection;
    Block* block;
    
public:
    DependentBlock(Block* block, MoveDirection moveDirection);
    Block* getBlock() const;
    const MoveDirection& getMoveDirection() const;
};
