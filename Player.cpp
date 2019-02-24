//
//  Player.cpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-09.
//  Copyright © 2018 Oliver. All rights reserved.
//

#include "Player.hpp"



Player::Player(sf::Vector2f position, sf::Vector2f size, std::string &texturename, sf::Vector2u dimensions,int playerNum, int playerNumA): animation(dimensions, texturename, playerNumA)
{
    this->position = position;
    this->size = size;
    this->alive = true;
    this->speed = 0.5f;
    this->playerNum = playerNum;
    
    
    
    Explosion* explosion = nullptr;
    
    body.setSize(size);
    body.setPosition(position);
    
    playerTexture.loadFromFile(texturename);
    
    body.setTexture(&playerTexture);
    

}


void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
   // explosion->Draw(window);
}


void Player::Update()
{
    if(alive&&(playerNum == 1))
    {
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard:: Up))
        {
            body.move(0.0f, -speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard:: Down))
        {
            body.move(0.0f, speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard:: Right))
        {
            body.move(speed, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard:: Left))
        {
            body.move(-speed, 0.0f);
        }
        
        position.x = body.getPosition().x;
        
        position.y = body.getPosition().y;
        
    }
    
    else if(alive&&(playerNum == 2))
    {
        
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard:: W))
        {
            body.move(0.0f, -speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard:: S))
        {
            body.move(0.0f, speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard:: D))
        {
            body.move(speed, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard:: A))
        {
            body.move(-speed, 0.0f);
        }
        
        position.x = body.getPosition().x;
        
        position.y = body.getPosition().y;
        
        
    }
    
    
    
    
}


void Player::setSpeed()
{
    speed +=0.2;
}

void Player::died()
{
    alive = false;
}


void Player::Animate()
{
    animation.Update();
    
    
  //  if(sf::Keyboard::isKeyPressed(sf::Keyboard:: Left)||sf::Keyboard::isKeyPressed(sf::Keyboard:: Right)||sf::Keyboard::isKeyPressed(sf::Keyboard:: Down)||sf::Keyboard::isKeyPressed(sf::Keyboard:: Up))
    
    body.setTextureRect(animation.picSect);
    //else
      //  body.setTextureRect(animation.picSect);
   // body.setTexture(&playerTexture);
   
}

void Player:: dropBombUpdate(sf::RenderWindow& window)   
{
    if(playerNum == 1)
    {
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard:: Space))
    {
        explosion = new Explosion(position, 5);
        
        explosion->Update();
        
        //explosion->Draw(window);
      
       if(!explosion->isActivated())
        {
            delete explosion;    //Do you first point to nullptr before deleting or it's the opposite, and what about if you close the program before the bomb is
            explosion = nullptr;  //deactivated? Do you get a memory leak?
        }
        
    }
        
    }
        
        
        if(playerNum == 2)
        {
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard:: LShift))
            {
                explosion = new Explosion(position, 5);
                
                explosion->Update();
                
                //explosion->Draw(window);
                
                if(!explosion->isActivated())
                {
                    delete explosion;    //Do you first point to nullptr before deleting or it's the opposite, and what about if you close the program before the bomb is
                    explosion = nullptr;  //deactivated? Do you get a memory leak?
                }
                
            }
       /*
        while (window.isOpen())  // This part is to avoid problem mentionned in the comments above
        {
            if(explosion->isActivated())
            {
            // Process events
            sf::Event event;
            while (window.pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed)
                {
                    
                    delete explosion;
                    explosion = nullptr;
                    
                }
                
                
            }
            
            }
        
        
    }
    */
    
}
}


Player::~Player()
{
    
}




