//
//  SpecialLevel.hpp
//  PongGame
//
//  Created by Thanh Phong Nguyen Dien on 12/11/19.
//  Copyright © 2019 Thanh Phong Nguyen Dien. All rights reserved.
//

#ifndef SpecialLevel_hpp
#define SpecialLevel_hpp

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include "PvsP.hpp"


class SpecialLevel {
protected:
    std::string nameFile;
public:
    SpecialLevel();
    SpecialLevel(std::string nameStage);
    virtual ~SpecialLevel();
    
    virtual void loadStage(std::string nameStage);
    
    virtual void showLoading();
    
    virtual void runGame(sf::RenderWindow &window);
    
};

#endif /* SpecialLevel_hpp */
