#pragma once

#include <algorithm>
#include <memory>
#include <span>
#include <stdexcept>
#include <vector>
#include "block.hpp"

class Solver{
    std::vector<std::unique_ptr<Block>> allBlocks;

public:
    
Solver(std::vector<std::unique_ptr<Block>> allBlocks);
~Solver();

std::span<const std::unique_ptr<Block>> getAllBlocks() const { return allBlocks; }
bool isSolved() const;

};
