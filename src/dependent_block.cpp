#include "dependent_block.hpp"
#include "block.hpp"
#include <stdexcept>
#include <utility>

DependentBlock::DependentBlock(std::shared_ptr<Block> block, MoveDirection moveDirection) 
                : block(std::move(block)), moveDirection(moveDirection) {}

std::shared_ptr<Block> DependentBlock::getBlock() const {
    auto lockedBlock = block.lock();
    if (!lockedBlock) {
        throw std::runtime_error("Dependent block reference has expired.");
    }
    return lockedBlock;
}
const MoveDirection& DependentBlock::getMoveDirection() const { return moveDirection; }