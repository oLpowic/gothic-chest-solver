#include "dependent_block.hpp"
#include "block.hpp"

DependentBlock::DependentBlock(std::shared_ptr<Block> block, bool dependency) 
                : block(block), dependency(dependency) {}