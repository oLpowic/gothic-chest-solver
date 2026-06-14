
#include <cstdio>
#include <iostream>
#include <memory>
#include <print>
#include <vector>

#include "block.hpp"
#include "dependent_block.hpp"
#include "solver.hpp"

void test();

int main(int argc, char* argv[])
{
    if(argc > 1 && std::string(argv[1]) == "test") {
        std::println("Running tests...");
        test();
        return 0;
    }

    return 0;
}

void test() {
    std::println("Hello, World!\n");
    std::vector<std::unique_ptr<Block>> blocks;

    blocks.push_back(std::make_unique<Block>(0, 0));
    blocks.push_back(std::make_unique<Block>(1, 1));
    blocks.push_back(std::make_unique<Block>(2, 2));
    blocks.push_back(std::make_unique<Block>(3, 3));
    blocks.push_back(std::make_unique<Block>(4, 4));
    blocks.push_back(std::make_unique<Block>(5, 5));
    blocks.push_back(std::make_unique<Block>(6, 6));

    auto* block = blocks[0].get();

    for (size_t i = 0; i < blocks.size(); ++i) {
        const auto& b = blocks[i];
        std::println("{}. {}\n", i, b->to_string().c_str());
    }
    
    for(size_t i = 0; i < blocks.size(); ++i) {
        const auto& b = blocks[i];
        std::println("{}. {}", i, b->visualizeBlock().c_str());
    }

    Solver solver(std::move(blocks));

    std::println("Is the puzzle solved? {}", solver.isSolved());
    
    std::println("Moving block 0 to the right...");
    block->moveBlocks(MoveDirection::RIGHT);
    std::println("{}",block->visualizeBlock().c_str());
    std::println("Moving block 0 to the left...");
    block->moveBlocks(MoveDirection::LEFT);
    std::println("{}",block->visualizeBlock().c_str());
}
