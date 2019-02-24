//
//  Collision.hpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-18.
//  Copyright © 2018 Oliver. All rights reserved.
//

#ifndef Collision_hpp
#define Collision_hpp

#include <stdio.h>
#include "Player.hpp"
#include "BlocksGenerator.hpp"
//#include "SBlock.hpp"


class Collision
{
public:
    
    Collision();
    
    
    
    void  Update(Player& player, BlocksGenerator& blockGenerator);
    
    
    ~Collision();
    
private:
    
    
    
    
    
};





#endif /* Collision_hpp */


