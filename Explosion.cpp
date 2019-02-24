//
//  Explosion.cpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-18.
//  Copyright © 2018 Oliver. All rights reserved.
//

#include "Explosion.hpp"



Explosion:: Explosion( sf::Vector2f position, int power)
{
    int j = 0;
    
    this->power = 10;
    
    activated = false;
    
    centerBody.setRadius(20);
    
    //centerBody.setPointCount(6000);
    
    centerBody.setFillColor(sf::Color::Red);
    
    // centerBody.setScale(5,1);
    
    this->position = position;
    centerBody.setPosition(position);
    
    
    leftBody.setRadius(10);
    leftBody.setFillColor(sf::Color(200,12,43));
    
    leftBody.setScale(j, 1);
    
    leftBody.setPosition(position.x-30,position.y+10);
    
    
    upBody.setRadius(10);
    upBody.setFillColor(sf::Color(240,35,23));
    
    upBody.setScale(1, j);
    
    upBody.setPosition(position.x+10,position.y-30);
    
    
    
    rightBody.setRadius(10);
    rightBody.setFillColor(sf::Color(200,12,43));
    
    rightBody.setScale(j, 1);
    
    rightBody.setPosition(position.x-30,position.y+10);
    
    
    downBody.setRadius(10);
    downBody.setFillColor(sf::Color(240,35,23));
    
    downBody.setScale(1, j);
    
    downBody.setPosition(position.x+10,position.y-30);
    
    
    
    
    
    
}


void Explosion::Update()
{
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard:: Space))
    activated = true;
    
    
    if(activated)
        
        if(clock.getElapsedTime().asSeconds()>=0.01&&std::abs(k)<10)
        {
            clock.restart();
            
            leftBody.setScale(k, 1);
            
            leftBody.setPosition(position.x,position.y);
            
            upBody.setScale(1, k);
            
            upBody.setPosition(position.x,position.y);
            
            // centerBody.move(sf::Vector2f(20.0f, 0.0f));
            
            rightBody.setScale(-k, 1);
            
            rightBody.setPosition(position.x,position.y);
            
            downBody.setScale(1, -k);
            
            downBody.setPosition(position.x,position.y);
            
            k+=0.5;
            
        }
    
    if(clock.getElapsedTime().asSeconds()>=0.01&&std::abs(k)>=10)
    {
        activated = false;
        
        clock.restart();
        
        k = 0;
    }
    
    
}


void Explosion::setPower(int force)
{
    //power = leftBody.getRadius()+5;
    
    leftBody.setRadius(force);
    upBody.setRadius(force);
    rightBody.setRadius(force);
    downBody.setRadius(force);
}


void Explosion::Draw(sf::RenderWindow& window)
{
    if(activated)
    {
        //window.draw(centerBody);
        window.draw(leftBody);
        window.draw(upBody);
        
        window.draw(rightBody);
        window.draw(downBody);
    }
    
}











