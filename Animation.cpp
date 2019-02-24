//
//  Animation.cpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-09.
//  Copyright © 2018 Oliver. All rights reserved.
//

#include "Animation.hpp"

//I have absolutely no idea why I keep adding useless comments 

Animation::Animation(sf::Vector2u dimensions, std::string& filename, int playerNumA):clock()
{
    
    this->playerNumA = playerNumA;
   
    texture.loadFromFile(filename);
    
    this->dimensions = dimensions;
    
    
    
    sf::Vector2u dummyCounter(0,0);
    counter=dummyCounter;
    
}




void Animation::Update()
{
    picSect.width = texture.getSize().x/static_cast<float>(dimensions.x);
    picSect.height = texture.getSize().y/static_cast<float>(dimensions.y);
    picSect.left = counter.x*picSect.width;
    picSect.top = counter.y*picSect.height;
   
    if(playerNumA == 1)
    {
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            counter.y = 1;
            
            if(clock.getElapsedTime(   ).asSeconds ()>= 0.1f)
            {
                clock.restart();
                
                if(counter.x!=8)
                    counter.x++;
                else
                    counter.x=0;
            }
        }
        
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            counter.y = 3;
            
            if(clock.getElapsedTime(   ).asSeconds ()>= 0.1f)
            {
                clock.restart();
                
                if(counter.x!=8)
                    counter.x++;
                else
                    counter.x=0;
            }
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            counter.y = 2;
            
            if(clock.getElapsedTime(   ).asSeconds ()>= 0.1f)
            {
                clock.restart();
                
                if(counter.x!=8)
                    counter.x++;
                else
                    counter.x=0;
            }
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            counter.y = 0;
            
            if(clock.getElapsedTime(   ).asSeconds ()>= 0.1f)
            {
                clock.restart();
                
                if(counter.x!=8)
                    counter.x++;
                else
                    counter.x=0;
            }
        }
        
    }
    
    
    if(playerNumA == 2)
    {
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            counter.y = 1;
            
            if(clock.getElapsedTime(   ).asSeconds ()>= 0.1f)
            {
                clock.restart();
                
                if(counter.x!=8)
                    counter.x++;
                else
                    counter.x=0;
            }
        }
        
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            counter.y = 3;
            
            if(clock.getElapsedTime(   ).asSeconds ()>= 0.1f)
            {
                clock.restart();
                
                if(counter.x!=8)
                    counter.x++;
                else
                    counter.x=0;
            }
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            counter.y = 2;
            
            if(clock.getElapsedTime(   ).asSeconds ()>= 0.1f)
            {
                clock.restart();
                
                if(counter.x!=8)
                    counter.x++;
                else
                    counter.x=0;
            }
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            counter.y = 0;
            
            if(clock.getElapsedTime(   ).asSeconds ()>= 0.1f)
            {
                clock.restart();
                
                if(counter.x!=8)
                    counter.x++;
                else
                    counter.x=0;
            }
        }
        
        
    }
    
    
    
    
};



Animation::~Animation()
{
    
};
