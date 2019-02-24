//
//  SBlock.hpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-09.
//  Copyright © 2018 Oliver. All rights reserved.
//

#ifndef SBlock_hpp
#define SBlock_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <random>
#include "Block.hpp"
//#include "Collision.hpp"


#include <string>

class SBlock : public Block
{
public:
    SBlock(sf::Vector2f size, sf::Vector2f position, sf::Color color, std::string& powerTexture, std::string& speedTexture, std::string& multipleTexture);
    
    ~SBlock();
    
    void Update();
    
    bool isUsed() const { return used;}
    
    void Using();
    
    bool isDestroyed()const { return destroyed;}
    
    void destroy();
    
    
    std::string getItem()const { return Item;}
    
    void Draw(sf::RenderWindow& window);  //Do I make it virtual? check notes
    
    
   
    
    
  //  sf::RectangleShape getBody() ;
    
   // friend class Collision;
    
protected:
    bool destroyed;
    bool used;
    std::string Item;
    std::string itemTexture;
    std::string speedTexture;
    
    bool gotTexture;
    
   
    
    
   // sf::RectangleShape body;
   
    sf::Texture texture;
    
    
};







#endif /* SBlock_hpp */
