//
//  Collision.cpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-18.
//  Copyright © 2018 Oliver. All rights reserved.
//

#include "Collision.hpp"


Collision::Collision()
{
    
}

void Collision::Update(Player& player, BlocksGenerator& blockGenerator)
{
   // if(player.getPosition().x>300)
   // player.getBody().move(-0.5f, 0.0f);
    
    for( Block& i: blockGenerator.vBlock )
    {
        int diffX =  abs(i.getBody().getPosition().x-player.getPosition().x)-0.5*(i.getSize().x+player.getSize().x);
    int diffY =  abs(i.getBody().getPosition().y-player.getPosition().y)-0.5*(i.getSize().y+player.getSize().y);
        
        if(diffX<=-10&&diffY<=-10)
        {
            if(diffX>diffY)
            {  if(i.getBody().getPosition().x>player.getPosition().x)
                player.getBody().move(-player.getSpeed(), 0.0f);
                else
                    player.getBody().move(player.getSpeed(), 0.0f);
                
            }
            else
            {
                if(i.getBody().getPosition().y>player.getPosition().y)
                    player.getBody().move(0.0f, -player.getSpeed());
                else
                    player.getBody().move(0.0f, player.getSpeed());
                
                
                
            }
                
        }
        
        
        
    }
    
    
    for( SBlock& i: blockGenerator.vSBlock )
    {
        i.Update();
        
        int diffX =  abs(i.getBody().getPosition().x-player.getPosition().x)-0.5*(i.getSize().x+player.getSize().x);
        int diffY =  abs(i.getBody().getPosition().y-player.getPosition().y)-0.5*(i.getSize().y+player.getSize().y);
        
        if(diffX<=-10&&diffY<=-10&& !(i.isUsed()))
        {
            if(diffX>diffY)
            {  if(i.getBody().getPosition().x>player.getPosition().x)
                player.getBody().move(-player.getSpeed(), 0.0f);
            else
                player.getBody().move(player.getSpeed(), 0.0f);
                
            }
            else
            {
                if(i.getBody().getPosition().y>player.getPosition().y)
                    player.getBody().move(0.0f, -player.getSpeed());
                else
                    player.getBody().move(0.0f, player.getSpeed());
                
                
                
            }
            
        }
        
        
        
    }

    
    
}


Collision::~Collision()
{
    
}

