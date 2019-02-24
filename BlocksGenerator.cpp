//
//  BlocksGenerator.cpp
//  BomberGuy
//
//  Created by Oliver on 2018-02-09.
//  Copyright © 2018 Oliver. All rights reserved.
//

#include "BlocksGenerator.hpp"

#include <iostream>




BlocksGenerator::BlocksGenerator(int numB, int numSB)
{
    seed = 1;
    this->numB = numB;
    this->numSB = numSB;
    
    
    int m = 24;
    
    int n = 15;
    
    
    std::vector <sf::Vector2f> v_coordinates;
    
    int index = 0;
    
    
    int v[360];
    int w[360];
    
    int k = 0;
    
    
    for(int i = 1; i<=24 ; ++i)
    {
        
        
        
        for(int j = 1; j<=15 ; ++j)
        {

            
            v[k] = i;
            w[k] = j;
            ++k;
            
        }
        
        
        
    }
    
    
    
    
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    
    
    int x[359];
    
    
    
    int rx[359];
    
   
    for( int i = 0 ; i < 359 ; ++i ){
        

        
        x[i]=i;
        
        
    }
    
    
    srand(time(NULL));
    
    
    
    std::random_shuffle( x, x+ 359, [](int n) { return rand() % n;}) ;
    for(int i=0;i<359;++i){
       
        
        rx[i]=x[i];
        
    }
    
   
    
    for(int i = 0; i< numB; ++i)
    {
        
        
        
        std::random_device rd;
        std::mt19937 mt(rd());
       // std::uniform_int_distribution<int> dist(0, 255);
        
       // int color1;
        //int color2;
        //int color3;
        
        //color1 = dist(mt);
        
       
        //color2 = dist(mt);
        
     
        //color3 = dist(mt);
        
     
        
        
        

        
        Block block0(sf::Vector2f( 60.0f, 60.0f), sf::Vector2f (v[rx[i]]*60.0f, w[rx[i]]*60.0f), sf::Color::Black);
        
        vBlock.push_back(block0);
    }
    
    
   
    
    
    
    for(int i = numB; i< numB+numSB; ++i)
    {
        
        
        
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, 255);
        
        int color1;
        int color2;
        int color3;
        
        color1 = dist(mt);
        
     
        color2 = dist(mt);
        
     
        
        color3 = dist(mt);
        
    
        
        
        
        std::string filenamePower = "/Users/Oliver/Downloads/power.png";
        
       
        
        std::string filenameSpeed = "/Users/Oliver/Downloads/speed.png";
        
      
        
        std::string filenameMultiples = "/Users/Oliver/Downloads/multiples.png";
        
      
        
        
        
        
        
        SBlock block0(sf::Vector2f( 60.0f, 60.0f), sf::Vector2f (v[rx[i]]*60.0f, w[rx[i]]*60.0f), sf::Color (color1, color2, color3), filenamePower, filenameSpeed, filenameMultiples);
        
        vSBlock.push_back(block0);
    }
  
    
    
    
    
}

/*
 void BlocksGenerator:: CleanSBlock()
{
    for(auto i: vSBlock)
    {
        if(i.isUsed())
            delete i;  // How are you going to delete this????????? This will help with memory issues
    }
}
*/
void BlocksGenerator::Draw(sf::RenderWindow& window)
{
    for(int i = 0; i< numB; ++i)
    {
        
        
        window.draw(vBlock[i].getBody());       // body is protected so used a getBody
    }
   
    for(int i = 0; i< numSB; ++i)
    {
        if(!vSBlock[i].isUsed())
        window.draw(vSBlock[i].getBody());
    }
    
    
}



BlocksGenerator:: ~BlocksGenerator()
{
    
}



