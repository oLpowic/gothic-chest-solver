#include "block.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>

Block::Block(uint16_t blockPosition, uint16_t position)
    : blockPosition(blockPosition) {
    if (position > MAX_POSITION) throw std::invalid_argument("position must be between 0 and " + std::to_string(MAX_POSITION));
    this->position = position;
}

Block::~Block() = default;

// Getters
uint16_t Block::getBlockPosition() const {
    return blockPosition;
}
uint16_t Block::getPosition() const {
    return position;
}

// Functions
bool Block::isAtMiddle() const {
    return position == MIDDLE_POSITION;
}

void Block::moveBlock(MoveDirection move){
    if(move == MoveDirection::LEFT) {
        if(position == 0) throw std::out_of_range("Cannot move left from position 0");
        --position;
    } else if(move == MoveDirection::RIGHT) {
        if(position == MAX_POSITION) throw std::out_of_range("Cannot move right from position " + std::to_string(MAX_POSITION));
        ++position;
    }
}


// Printing
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

