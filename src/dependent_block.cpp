#include "dependent_block.hpp"
#include "block.hpp"
#include <utility>

DependentBlock::DependentBlock(std::shared_ptr<Block> block, MoveDirection moveDirection) 
                : block(std::move(block)), moveDirection(moveDirection) {}