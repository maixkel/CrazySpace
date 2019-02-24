
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>//for debugging

#include "Player.hpp"
#include "Animation.hpp"
#include "Block.hpp"
#include "SBlock.hpp"
#include "BlocksGenerator.hpp"
#include "Collision.hpp"
#include "Explosion.hpp"

//Useless comment to be ingnored

int main(int, char const**)
{
    sf::Clock BombClock1;
    int clock1Temporary = 0;
    sf::Vector2f positionBomb1;
    bool explode = false;
    sf::CircleShape* detonator = nullptr;
    
    int force = 10;
    float timer = 2;
    
    
    
    
    
   
    
    sf::Clock BombClock2;
    int clock2Temporary = 0;
    sf::Vector2f positionBomb2;
    bool explode2 = false;
    sf::CircleShape* detonator2 = nullptr;
    
    int force2 = 10;
    float timer2 = 2;
    
    
    
    
  
  
   
    
    

 
    
    sf::Font font;
    // Load it from a file
    if (!font.loadFromFile("/Library/Fonts/Bodoni 72.ttc"))
    {
        std::cout<<"There is no font \n";
    }
    else
    {
        std::cout<<"There is a font \n";
    }
    
    
    
    sf::Text text;
    
    // select the font
    text.setFont(font); // font is a sf::Font
    
    //text.setPosition(30.0f, 40.0f);
    
    // set the string to display
    text.setString("Player 1 won");
    
    // set the character size
    text.setCharacterSize(300); // in pixels, not points!
    
    // set the color
    text.setFillColor(sf::Color::Red);
    
    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    
    
  
    
    sf::Text text2;
    
    // select the font
    text2.setFont(font); // font is a sf::Font
    
    //text2.setPosition(30.0f, 40.0f);
    
    // set the string to display
    text2.setString("Player 2 won");
    
    // set the character size
    text2.setCharacterSize(300); // in pixels, not points!
    
    // set the color
    text2.setFillColor(sf::Color::Blue);
    
    // set the text style
    text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    
    
    
    
    
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1440, 900), "SFML window");
    
    
    std::string filename = "/Users/Oliver/Downloads/professor_walk_cycle_no_hat.png";
    
    
  //  std::string& filenameRef = filename;   // I did this because for sojme reason I can't just add the "   "
    
    
    std::string filenamePower = "/Users/Oliver/Downloads/power.png";
    
 //   std::string& filenamePowerRef = filenamePower;   // I did this because for sojme reason I can't just add the "   "
    
    std::string filenameSpeed = "/Users/Oliver/Downloads/speed.png";
    
  //  std::string& filenameSpeedRef = filenameSpeed;   // I did this because for sojme reason I can't just add the "   "
    
    std::string filenameMultiples = "/Users/Oliver/Downloads/multiples.png";
    
  //  std::string& filenameMultiplesRef = filenameMultiples;   // I did this because for sojme reason I can't just add the "   "
    
    
    
    
    
    std::string filename2 = "/Users/Oliver/Downloads/FBI_walk_cycle.png";
    
    
    
    
    
    
    Player player1(sf::Vector2f(300.0f,300.0f), sf::Vector2f(60.0f,60.0f), filename, sf::Vector2u(9,4), 1,1);
    
    
    Player player2(sf::Vector2f(1300.0f,800.0f), sf::Vector2f(60.0f,60.0f), filename2, sf::Vector2u(9,4), 2,2);
    
    
    
    
    
    
    
    //Player player2(sf::Vector2f(700.0f,700.0f), sf::Vector2f(50.0f,80.0f), filename, sf::Vector2u(9,4));
    
    Block block1(sf::Vector2f (60.0f,60.0f), sf::Vector2f (340.0f,350.0f), sf::Color (123,111,39));
    
    SBlock sblcok1( sf::Vector2f(60.0f,60.0f), sf::Vector2f(0.5*1440.0f, 0.5*900.0f), sf::Color (67,7,88), filenamePower, filenameSpeed, filenameMultiples);
    
    BlocksGenerator blockGenerator1(90, 60);     // 90 and 60 seem like fair numbers
    
    
    
    
    
    //Explosion explosion( sf::Vector2f (300.0f, 300.0f), 20);
    
    
    Explosion* explosion = nullptr;
    
   //For player2
     Explosion* explosion2 = nullptr;
    ////
    Collision collision;
   
   
    
    
    
 
    


    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
    
        
        
        
        
        
        
        
       // for(int i = 0; i< 2; ++i)
         //   std::cout<<blockGenerator1.vSBlock[i].getUselessNum()<<std::endl;;
        
        // std::cout<<sblcok1.getUselessNum()<<std::endl;
        
        player1.Update();
        
        //player2
        player2.Update();
        
        
        
        if( (sf::Keyboard::isKeyPressed(sf::Keyboard:: Space) )&& ( detonator == nullptr))
        { clock1Temporary= BombClock1.getElapsedTime().asSeconds();
            explode = true;
            positionBomb1 =player1.getPosition();
            
             detonator= new sf::CircleShape(20, 3);
            
            detonator->setFillColor(sf::Color::Red);
            
            detonator->setPosition(positionBomb1);
            
            
        }
        
        if((clock1Temporary+timer< BombClock1.getElapsedTime().asSeconds())&&explode)
           explosion = new Explosion( positionBomb1, 5);
        
        if(explosion != nullptr)
            explosion->setPower(force);
        
        
        if(detonator !=nullptr)
        detonator->rotate(10);
         
        
            if(explosion != nullptr)
            { explode = false;
                delete detonator;
                detonator = nullptr;
                
            explosion->Update();
                BombClock1.restart();
               
            }
        
        
        
        
        
        
        
        //For player2
        
        if( (sf::Keyboard::isKeyPressed(sf::Keyboard:: LShift) )&& ( detonator2 == nullptr))
        { clock2Temporary= BombClock2.getElapsedTime().asSeconds();
            explode2 = true;
            positionBomb2 =player2.getPosition();
            
            detonator2= new sf::CircleShape(20, 3);
            
            detonator2->setFillColor(sf::Color::Red);
            
            detonator2->setPosition(positionBomb2);
            
            
        }
        
        if((clock2Temporary+timer< BombClock2.getElapsedTime().asSeconds())&&explode2)
            explosion2 = new Explosion( positionBomb2, 5);
        
        if(explosion2 != nullptr)
            explosion2->setPower(force2);
        
        
        if(detonator2 !=nullptr)
            detonator2->rotate(10);
        
        
        if(explosion2 != nullptr)
        { explode2 = false;
            delete detonator2;
            detonator2 = nullptr;
            
            explosion2->Update();
            BombClock2.restart();
            
        }
        /////
        
        
        
        
        
        
        
        
      
         if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
             std::cout<<sf::Mouse::getPosition(window).x<<" "<<sf::Mouse::getPosition(window).y<<std::endl;
        
        
        
       // sblcok1.Update();
        
        
        //player1.dropBombUpdate(window);
        
         collision.Update(player1, blockGenerator1);
        
        
        collision.Update(player2, blockGenerator1);
        
        //blockGenerator1.vSBlock[2].destroy();
    
     
        
        if(explosion != nullptr)
        {   std::cout<<"We are here"<<explosion->getPower()/10<<std::endl;
            std::cout<<"We Now"<<explosion->getPower()<<std::endl;
            for(auto&& i: blockGenerator1.vSBlock)
            {  //i.destroy();
            if(abs(explosion->getPosition().x-i.getPosition().x)<=192*(explosion->getPower()/10)+50&&abs(explosion->getPosition().y-i.getPosition().y)<=192*(explosion->getPower()/10)+50)
            {
               // if(abs(explosion->getPosition().x-i.getPosition().x)>192)
             //   {
                    if(abs(explosion->getPosition().y-i.getPosition().y)>=abs(explosion->getPosition().x-i.getPosition().x))
                  {
                       if((i.getPosition().x-20*(explosion->getPower()/10)<explosion->getPosition().x)&&abs(i.getPosition().x-explosion->getPosition().x)<=60)
                        i.destroy();
                   }
                
                    else
                    {
                        if((i.getPosition().y-20*(explosion->getPower()/10)<explosion->getPosition().y)&&abs(i.getPosition().y-explosion->getPosition().y)<=60)
                        i.destroy();
                    }
             
            }
            }
        }
        
        
        
        
        
        //player2
        
        if(explosion2 != nullptr)
        {   std::cout<<"We are here"<<explosion2->getPower()/10<<std::endl;
            std::cout<<"We Now"<<explosion2->getPower()<<std::endl;
            for(auto&& i: blockGenerator1.vSBlock)
            {  //i.destroy();
                if(abs(explosion2->getPosition().x-i.getPosition().x)<=192*(explosion2->getPower()/10)+50&&abs(explosion2->getPosition().y-i.getPosition().y)<=192*(explosion2->getPower()/10)+50)
                {
                    // if(abs(explosion->getPosition().x-i.getPosition().x)>192)
                    //   {
                    if(abs(explosion2->getPosition().y-i.getPosition().y)>=abs(explosion2->getPosition().x-i.getPosition().x))
                    {
                        if((i.getPosition().x-20*(explosion2->getPower()/10)<explosion2->getPosition().x)&&abs(i.getPosition().x-explosion2->getPosition().x)<=60)
                            i.destroy();
                    }
                    
                    else
                    {
                        if((i.getPosition().y-20*(explosion2->getPower()/10)<explosion2->getPosition().y)&&abs(i.getPosition().y-explosion2->getPosition().y)<=60)
                            i.destroy();
                    }
                    
                }
            }
        }
        
        
        /////
        
        
        
        
        
        
        
        
        
        
        if(explosion != nullptr)
        {   std::cout<<"We are here"<<explosion->getPower()/10<<std::endl;
            std::cout<<"We Now"<<explosion->getPower()<<std::endl;
           // for(auto&& i: blockGenerator1.vSBlock)
            {  //i.destroy();
                if(abs(explosion->getPosition().x-player1.getPosition().x)<=192*(explosion->getPower()/10)+50&&abs(explosion->getPosition().y-player1.getPosition().y)<=192*(explosion->getPower()/10)+50)
                {
                    // if(abs(explosion->getPosition().x-i.getPosition().x)>192)
                    //   {
                    if(abs(explosion->getPosition().y-player1.getPosition().y)>=abs(explosion->getPosition().x-player1.getPosition().x))
                    {
                        if((player1.getPosition().x-20*(explosion->getPower()/10)<explosion->getPosition().x)&&abs(player1.getPosition().x-explosion->getPosition().x)<=60)
                            player1.died();
                    }
                    
                    else
                    {
                        if((player1.getPosition().y-20*(explosion->getPower()/10)<explosion->getPosition().y)&&abs(player1.getPosition().y-explosion->getPosition().y)<=60)
                            player1.died();
                    }
                    
                }
            }
        }
        
        
        
        if(explosion2 != nullptr)
        {   std::cout<<"We are here"<<explosion2->getPower()/10<<std::endl;
            std::cout<<"We Now"<<explosion2->getPower()<<std::endl;
            // for(auto&& i: blockGenerator1.vSBlock)
            {  //i.destroy();
                if(abs(explosion2->getPosition().x-player1.getPosition().x)<=192*(explosion2->getPower()/10)+50&&abs(explosion2->getPosition().y-player1.getPosition().y)<=192*(explosion2->getPower()/10)+50)
                {
                    // if(abs(explosion->getPosition().x-i.getPosition().x)>192)
                    //   {
                    if(abs(explosion2->getPosition().y-player1.getPosition().y)>=abs(explosion2->getPosition().x-player1.getPosition().x))
                    {
                        if((player1.getPosition().x-20*(explosion2->getPower()/10)<explosion2->getPosition().x)&&abs(player1.getPosition().x-explosion2->getPosition().x)<=60)
                            player1.died();
                    }
                    
                    else
                    {
                        if((player1.getPosition().y-20*(explosion2->getPower()/10)<explosion2->getPosition().y)&&abs(player1.getPosition().y-explosion2->getPosition().y)<=60)
                            player1.died();
                    }
                    
                }
            }
        }
        
        
        
        
        
        
        
        
       //player2
        if(explosion2 != nullptr)
        {   std::cout<<"We are here"<<explosion2->getPower()/10<<std::endl;
            std::cout<<"We Now"<<explosion2->getPower()<<std::endl;
            // for(auto&& i: blockGenerator1.vSBlock)
            {  //i.destroy();
                if(abs(explosion2->getPosition().x-player2.getPosition().x)<=192*(explosion2->getPower()/10)+50&&abs(explosion2->getPosition().y-player2.getPosition().y)<=192*(explosion2->getPower()/10)+50)
                {
                    // if(abs(explosion->getPosition().x-i.getPosition().x)>192)
                    //   {
                    if(abs(explosion2->getPosition().y-player2.getPosition().y)>=abs(explosion2->getPosition().x-player2.getPosition().x))
                    {
                        if((player2.getPosition().x-20*(explosion2->getPower()/10)<explosion2->getPosition().x)&&abs(player2.getPosition().x-explosion2->getPosition().x)<=60)
                            player2.died();
                    }
                    
                    else
                    {
                        if((player2.getPosition().y-20*(explosion2->getPower()/10)<explosion2->getPosition().y)&&abs(player2.getPosition().y-explosion2->getPosition().y)<=60)
                            player2.died();
                    }
                    
                }
            }
        }
        
        
        
        if(explosion != nullptr)
        {   std::cout<<"We are here"<<explosion->getPower()/10<<std::endl;
            std::cout<<"We Now"<<explosion->getPower()<<std::endl;
            // for(auto&& i: blockGenerator1.vSBlock)
            {  //i.destroy();
                if(abs(explosion->getPosition().x-player2.getPosition().x)<=192*(explosion->getPower()/10)+50&&abs(explosion->getPosition().y-player2.getPosition().y)<=192*(explosion->getPower()/10)+50)
                {
                    // if(abs(explosion->getPosition().x-i.getPosition().x)>192)
                    //   {
                    if(abs(explosion->getPosition().y-player2.getPosition().y)>=abs(explosion->getPosition().x-player2.getPosition().x))
                    {
                        if((player2.getPosition().x-20*(explosion->getPower()/10)<explosion->getPosition().x)&&abs(player2.getPosition().x-explosion->getPosition().x)<=60)
                            player2.died();
                    }
                    
                    else
                    {
                        if((player2.getPosition().y-20*(explosion->getPower()/10)<explosion->getPosition().y)&&abs(player2.getPosition().y-explosion->getPosition().y)<=60)
                            player2.died();
                    }
                    
                }
            }
        }
        
        ///////
        
        
        
                
        
        
        for(auto&& i: blockGenerator1.vSBlock)
        {
            i.Update();
        }
        
        for(auto&& i: blockGenerator1.vSBlock)
        {
            if(i.isDestroyed()&&!(i.isUsed()))
                if(abs(player1.getPosition().x-i.getPosition().x)<=40 /*&& abs(player1.getPosition().y-i.getPosition().y)<=40*/)
                { i.Using();
                 
                    if(i.getItem() == "speed")
                        player1.setSpeed();
                    else if(i.getItem() == "power")
                        force +=5;
                    else if(i.getItem() == "multiple")
                    {
                        if(timer>1)
                        timer -=0.1;
                    }
                }
        }
        
        
        //player2
        for(auto&& i: blockGenerator1.vSBlock)
        {
            if(i.isDestroyed()&&!(i.isUsed()))
                if(abs(player2.getPosition().x-i.getPosition().x)<=40 /*&& abs(player1.getPosition().y-i.getPosition().y)<=40*/)
                { i.Using();
                    
                    if(i.getItem() == "speed")
                        player2.setSpeed();
                    else if(i.getItem() == "power")
                        force2 +=5;
                    else if(i.getItem() == "multiple")
                    {
                        if(timer>1)
                            timer2 -=0.1;
                    }
                }
        }
        
        
        std::cout<<"Time "<<timer<<std::endl;
        
        
        
        
        
       // explosion.Update();
        
        
        
        player1.Animate();
        
        //player2
        player2.Animate();
       // std::cout<<player1.animation.picSect.height<<std::endl;
        
      
        
        
        
        
        
    //    while(player1.getBody().getPosition() > 100 )
      //      pla
        
        
        
        
        
        
        
        
        
        
        
        // Clear screen
        window.clear(sf::Color::Yellow);
        
        
        //window.draw(background);
       
        // Draw the sprite
        player1.Draw(window);
        
        //player2
        player2.Draw(window);
        
        
        if(detonator != nullptr)
            window.draw(*detonator);
        
         if(explosion != nullptr)
        explosion->Draw(window);
        
        if(explosion != nullptr)
        if(!explosion->isActivated())
        {delete explosion;
         
            explosion = nullptr;
        }
       
        
        //player2
        
        if(detonator2 != nullptr)
            window.draw(*detonator2);
        
        if(explosion2 != nullptr)
            explosion2->Draw(window);
        
        if(explosion2 != nullptr)
            if(!explosion2->isActivated())
            {delete explosion2;
                
                explosion2 = nullptr;
            }
        
        
        
        //Draw block1
        
       // if(!explosion->isActivated())
        {
           // delete explosion;
        }
        
        
        
       //explosion.Draw(window);
        
       // block1.Draw(window);
        
        //Draw sblock1
        
        

        
       // sblcok1.Draw(window);
        
        
        //Draw bunch of blocks
        
          blockGenerator1.Draw(window);
        
         if(!player2.isAlive())
           window.draw(text);
        
        if(!player1.isAlive())
            window.draw(text2);
        
        
        
        //std::cout<<player1.getPosition().x<<std::endl;

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
