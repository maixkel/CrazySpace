//
//  SBlock.cpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-09.
//  Copyright © 2018 Oliver. All rights reserved.
//

#include "SBlock.hpp"


SBlock::SBlock(sf::Vector2f size, sf::Vector2f position, sf::Color color, std::string& powerTexture, std::string& speedTexture, std::string& multipleTexture):Block( size, position, color)
{
    destroyed = false;
    used = false;
    
    gotTexture = false;
    
    
    
    
    
    body.setFillColor(sf::Color::Green);
    
    
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 3);
    
    int numRandom;
    
    numRandom = dis(gen);
    
    if(numRandom == 1)
    {
        Item = "power";
        this->itemTexture = powerTexture;
    }
    else if(numRandom == 2)
    {
        Item = "speed";
        this->itemTexture = speedTexture;
    }
    else
    {
        Item = "multiple";
        this->itemTexture = multipleTexture;
    }
    
    
    
    

}

SBlock::~SBlock()
{
    
}


void SBlock::Using()
{
    used = true;
}

void SBlock::Update()
{
    if((!used&&destroyed)&&!gotTexture/*||sf::Keyboard::isKeyPressed(sf::Keyboard:: A)*/) // The code between /* */ is intended for debbugging purposes
    {
        //sf::Texture texture;
        texture.loadFromFile(itemTexture);
        
        // sf::Texture& textureRef = texture;
        
        body.setFillColor(sf::Color::White);
        
        body.setTexture(&texture);
        
        gotTexture = true;
       
        
    }
}

 void SBlock::Draw(sf::RenderWindow& window)
{
    if(!used)
     window.draw(body);
}


void SBlock::destroy()
{
    destroyed = true;
}


/*
sf::RectangleShape SBlock:: getBody() 
{
   // sf::RectangleShape recsh;
   
    
   // this->size = size;
    //this->position = position;
    
  //  body.setSize(sf::Vector2f(60.0f, 60.0f));
    //body.setPosition(position);
    
   // body.setFillColor(sf::Color (44,44,44));
    
    return body;
    
    
    
}
*/







