
#include <cstdio>
#include <iostream>
#include <vector>
#include <memory>
#include <print>


#include "block.hpp"
#include "dependent_block.hpp"
#include "solver.hpp"

void main1();

int main(int argc, char* argv[])
{
    if(argc > 1 && std::string(argv[1]) == "test") {
        std::println("Running tests...");
        // Here you would call your test functions
        return 0;
    }

    main1();
    return 0;
}


void main1() {
    std::println("Hello, World!\n");
    std::vector<std::shared_ptr<Block>> blocks;

    auto block = std::make_shared<Block>(0, 0);
    auto block1 = std::make_shared<Block>(1, 1);
    auto block2 = std::make_shared<Block>(2, 2);
    auto block3 = std::make_shared<Block>(3, 3);
    auto block4 = std::make_shared<Block>(4, 4);
    auto block5 = std::make_shared<Block>(5, 5);
    auto block6 = std::make_shared<Block>(6, 6);

    blocks.push_back(block);
    blocks.push_back(block1);
    blocks.push_back(block2);
    blocks.push_back(block3);
    blocks.push_back(block4);
    blocks.push_back(block5);
    blocks.push_back(block6);

    for (size_t i = 0; i < blocks.size(); ++i) {
        const auto& b = blocks[i];
        
       std::println("{}. {}\n", i, b->to_string().c_str());
    }
    
    for(size_t i = 0; i < blocks.size(); ++i) {
        const auto& b = blocks[i];
        
       std::println("{}. {}", i, b->visualizeBlock().c_str());
    }

    Solver solver(blocks);

    std::println("Is the puzzle solved? {}", solver.is_solved());

    std::println("Moving block 0 to the right...");
    block->moveBlock(MoveDirection::RIGHT);
    std::println("{}", block->visualizeBlock().c_str());
    block->moveBlock(MoveDirection::LEFT);
    std::println("{}", block->visualizeBlock().c_str());
}