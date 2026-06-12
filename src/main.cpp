
#include <cstdio>
#include <iostream>
#include <vector>
#include "block.hpp"
#include "dependent_block.hpp"

int main() {
    std::printf("Hello, World!\n");
    std::vector<Block> blocks;

    Block block(1, 2);
    Block block2(1, 3);
    Block block3(1, 4);

    blocks.push_back(block);
    blocks.push_back(block2);
    blocks.push_back(block3);

    for (Block b : blocks) {
        std::cout << b.to_string() << std::endl;
    }

    
    return 0;
}