#include "block.hpp"
#include "dependent_block.hpp"
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

Block::Block(uint16_t blockPosition, uint16_t position)
    : blockPosition(blockPosition) {
    if (position > MAX_POSITION) throw std::invalid_argument("position must be between 0 and " + std::to_string(MAX_POSITION));
    this->position = position;
}

Block::Block(uint16_t blockPosition, uint16_t position, std::vector<DependentBlock> dependentBlocks)
    : blockPosition(blockPosition), dependentBlocks(std::move(dependentBlocks)) {
    if (position > MAX_POSITION) throw std::invalid_argument("position must be between 0 and " + std::to_string(MAX_POSITION));
    this->position = position;
}

Block::~Block() = default;

void Block::addDependentBlocks(const std::vector<DependentBlock>& depBlocks){
    if(!depBlocks.empty()) {
        dependentBlocks = depBlocks;
    }
}

uint16_t Block::getBlockPosition() const {
    return blockPosition;
}

uint16_t Block::getPosition() const {
    return position;
}

const bool Block::isAtMiddle() const {
    return position == MIDDLE_POSITION;
}

const bool Block::isMovePossible(MoveDirection move) const {
    if(move == MoveDirection::LEFT) {
        if(position == 0) return false;
        else return true;
    }
    if(move == MoveDirection::RIGHT) {
        if(position == MAX_POSITION) return false;
        else return true;
    }
    return false;
}

void Block::makeMove(MoveDirection move){
  if (move == MoveDirection::LEFT) {
    --position;
  }
  if (move == MoveDirection::RIGHT) {
    ++position;
  }
}

bool Block::canMoveBlocks(MoveDirection move) const {
    if (!isMovePossible(move))
        return false;

    for (const auto& dependentBlock : dependentBlocks) {
        auto depMove = dependentBlock.getMoveDirection();
        auto* block = dependentBlock.getBlock();

        if (!block->isMovePossible(depMove))
            return false;
    }

    return true;
}

void Block::applyMoveBlocks(MoveDirection move) {
    makeMove(move);

    for (const auto& dependentBlock : dependentBlocks) {
        auto depMove = dependentBlock.getMoveDirection();
        auto* block = dependentBlock.getBlock();

        block->makeMove(depMove);
    }
}

bool Block::moveBlocks(MoveDirection move) {
    if (!canMoveBlocks(move))
        return false;

    applyMoveBlocks(move);
    return true;
}

std::string Block::to_string() const {
    return std::string("Block ") + std::to_string(blockPosition)
        + " at position " + std::to_string(position);
}

std::string Block::visualizeBlock() const {
    std::string visualization;    
    
    for(int i = 0; i < this->position; ++i) {
        visualization += " ";
    }

    for(int i=0; i <= MAX_POSITION; ++i) {
        if (i == this->position) {
            visualization += "X";
        } else {    
            visualization += "O";
        }
    }
    return visualization;
}

std::string Block::visualizeWithDepBlocks() const {
    std::string result = std::to_string(position) + visualizeBlock();
    for(const auto& depBlocks : dependentBlocks) {
        result += std::to_string(depBlocks.getBlock()->getPosition()) + depBlocks.getBlock()->visualizeBlock();
    }
    return result;
}
