#include "dependent_block.hpp"
#include "block.hpp"
#include <stdexcept>

DependentBlock::DependentBlock(Block* block, MoveDirection moveDirection)
                : block(block), moveDirection(moveDirection) {
    if (block == nullptr) {
        throw std::invalid_argument("Dependent block pointer cannot be null.");
    }
}

Block* DependentBlock::getBlock() const { return block; }
const MoveDirection& DependentBlock::getMoveDirection() const { return moveDirection; }
