//
//  Block.hpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-09.
//  Copyright © 2018 Oliver. All rights reserved.
//

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>

#include <SFML/Graphics.hpp>
//#include "Collision.hpp"


class Block
{
public:
    Block(sf::Vector2f size, sf::Vector2f position, sf::Color color);
    void Draw(sf::RenderWindow& window);
    
     sf::RectangleShape getBody() const {return body;}
    
    sf::Vector2f getPosition()const {return position;}
     sf::Vector2f getSize() const {return size;}
    
    
    ~Block(); 
    
  //  friend class Collision;
    
protected:
    
   sf::RectangleShape body;
    
    sf::Vector2f size;
    
    sf::Vector2f position;
    
};









#endif /* Block_hpp */
