#pragma once

#include <algorithm>
#include <memory>
#include <vector>
#include "block.hpp"
#include <stdexcept>

class Solver{
    std::vector<std::shared_ptr<Block>> allBlocks;

public:
    
Solver(std::vector<std::shared_ptr<Block>> allBlocks);
~Solver();

std::vector<std::shared_ptr<Block>> getAllBlocks() const { return allBlocks; }
bool isSolved() const;

};