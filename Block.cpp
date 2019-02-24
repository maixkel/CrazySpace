//
//  Block.cpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-09.
//  Copyright © 2018 Oliver. All rights reserved.
//

#include "Block.hpp"


Block::Block(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
    this->size = size;
    this->position = position;
    
    body.setSize(size);
    body.setPosition(position);
    
    body.setFillColor(color);

    
    
}


Block::~Block()
{
    
}




void Block::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

/*
sf::RectangleShape Block:: getBody() const
{
    sf::RectangleShape& bodyRef;
    
     bodyRef = body;
    
    sf::RectangleShape* body_ptr = bodyRef;
 
    return body;
    
}
*/
