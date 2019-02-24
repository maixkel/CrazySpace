//
//  Player.hpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-09.
//  Copyright © 2018 Oliver. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <string>
#include "Animation.hpp"
#include "Explosion.hpp"



class Player
{
public:
   // Player(sf::v)
    Player(sf::Vector2f position, sf::Vector2f size, std::string &texturename, sf::Vector2u dimensions, int playerNum, int playerNumA);
    
    
    void Draw(sf::RenderWindow& window);
    
    void Update();
    
    ~Player();
    void Animate();
    
    bool isAlive() const {return alive;}
    
    void died();
    
    void setSpeed();
    
    float getSpeed(){return speed;}
    
    sf::Vector2f getPosition() const {return position;}
    sf::Vector2f getSize() const {return size;}
    
    sf::RectangleShape& getBody() {return body;}
    
    void dropBombUpdate(sf::RenderWindow& window);
    
    
    Animation animation;
    
   
    
private:
    
    sf::Vector2f position;
    sf::Vector2f size;
    int playerNum;
    
    float speed;
    
   
    sf::RectangleShape body;
    sf::Texture playerTexture;
    
    Explosion* explosion;
    
    bool alive;
    
    
   
    
    
    
};


#endif /* Player_hpp */
