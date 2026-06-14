#include "solver.hpp"
#include <utility>

Solver::Solver(std::vector<std::unique_ptr<Block>> allBlocks) : allBlocks(std::move(allBlocks)) {
        std::sort(this->allBlocks.begin(), 
        this->allBlocks.end(), 
        [](const std::unique_ptr<Block>& a, const std::unique_ptr<Block>& b) {
            return a->getBlockPosition() < b->getBlockPosition();
        });

        if(std::unique(this->allBlocks.begin(),
        this->allBlocks.end(), 
        [](const std::unique_ptr<Block>& a, const std::unique_ptr<Block>& b) {
            return a->getBlockPosition() == b->getBlockPosition();
        }) != this->allBlocks.end()) {
            throw std::invalid_argument("Duplicate block positions are not allowed.");
        }
    };

Solver::~Solver() = default;

bool Solver::isSolved() const{ 
    if(allBlocks.empty()) return false;

    for(const auto& block : allBlocks){
        if(!block->isAtMiddle()) return false;
    }
    return true;
}
