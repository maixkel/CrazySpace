//
//  BlocksGenerator.hpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-09.
//  Copyright © 2018 Oliver. All rights reserved.
//

#ifndef BlocksGenerator_hpp
#define BlocksGenerator_hpp

#include <stdio.h>
#include <vector>
#include "Block.hpp"
#include "SBlock.hpp"
#include <random>

class BlocksGenerator
{
public:
    BlocksGenerator(int numB, int numSB);
    
    
  //  void CleanSBlock();  // started working on it in cpp file, its purpose is to clean the block generator by deleteting the used SBlocks
    
    
    void Draw(sf::RenderWindow& window);
    
    ~BlocksGenerator();
    
    
    std::vector <SBlock> vSBlock;  //Put it back in private
    
    std::vector <Block> vBlock;
    
    
private:
    

    int numB;
    int numSB;
    int seed;
    
    
    
    
};



#endif /* BlocksGenerator_hpp */
