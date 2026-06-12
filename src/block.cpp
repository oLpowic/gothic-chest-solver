#include "block.hpp"
#include <stdexcept>

Block::Block(uint16_t blockPosition, uint16_t position)
    : blockPosition(blockPosition), position(0) {
    if (position > 6) throw std::invalid_argument("position must be between 0 and 6");
    this->position = position;
}

Block::~Block() = default;

std::string Block::to_string() const {
    return std::string("Block ") + std::to_string(blockPosition)
        + " at position " + std::to_string(position);
}