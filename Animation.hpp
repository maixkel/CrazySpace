//
//  Animation.hpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-09.
//  Copyright © 2018 Oliver. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <string>

class Animation
{
public:
    
    Animation(sf::Vector2u dimensions, std::string& filename, int playerNumA);
        
    void Update();
    
    ~Animation();
    
    
    sf::IntRect picSect;
    
private:
    
    sf::Texture texture;
    sf::Vector2u dimensions;
    sf::Vector2u counter;
    sf::Clock clock;
    int playerNumA;
    
};

#endif /* Animation_hpp */









