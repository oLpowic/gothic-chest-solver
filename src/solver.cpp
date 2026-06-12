#include "solver.hpp"

Solver::Solver(std::vector<std::shared_ptr<Block>> allBlocks) : allBlocks(allBlocks) {
        // Sort blocks by blockPosition
        std::sort(allBlocks.begin(), 
        allBlocks.end(), 
        [](const std::shared_ptr<Block>& a, const std::shared_ptr<Block>& b) {
            return a->getBlockPosition() < b->getBlockPosition();
        });

        // Check for duplicates
        if(std::unique(allBlocks.begin(),
        allBlocks.end(), 
        [](const std::shared_ptr<Block>& a, const std::shared_ptr<Block>& b) {
            return a->getBlockPosition() == b->getBlockPosition();
        }) != allBlocks.end()) {
            throw std::invalid_argument("Duplicate block positions are not allowed.");
        }
    };

Solver::~Solver() {
    allBlocks.clear();
}


bool Solver::is_solved() const{ 
    if(allBlocks.empty()) return false;

    for(const auto& block : allBlocks){
        if(!block->isAtMiddle()) return false;
    }
    return true;
}

