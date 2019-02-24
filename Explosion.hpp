//
//  Explosion.hpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-18.
//  Copyright © 2018 Oliver. All rights reserved.
//

#ifndef Explosion_hpp
#define Explosion_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <cmath>

class Explosion
{
public:
    Explosion( sf::Vector2f position, int power);
    
    sf::CircleShape getBody(){return centerBody;}
    
    sf::Vector2f getPosition(){return position;}
    
    bool isActivated() const {return activated;}
    
    void setPower(int force);
    
    float getPower()const{return leftBody.getRadius();}
    
    void Update();  
    
    void Draw(sf::RenderWindow& window);
    
private:
    sf::CircleShape centerBody;
    sf::CircleShape leftBody;
    sf::CircleShape upBody;
    sf::CircleShape rightBody;
    sf::CircleShape downBody;
    sf::Vector2f position;
    float power;
    
    sf::Clock clock;
    
    float k;
    bool activated;
    
    
    
};









#endif /* Explosion_hpp */
