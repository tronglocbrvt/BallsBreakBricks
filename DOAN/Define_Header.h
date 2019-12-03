//
//  Define_Header.h
//  PongGame
//
//  Created by Thanh Phong Nguyen Dien on 12/2/19.
//  Copyright © 2019 Thanh Phong Nguyen Dien. All rights reserved.
//

#ifndef Define_Header_h
#define Define_Header_h

#define _WIDTH_SCREEN 980
#define _HEIGH_SCREEN 540

#define _WIDTH_TABLE_GAME_ _WIDTH_SCREEN * 4 / 10
#define _HEIGH_TABLE_GAME_ _HEIGH_SCREEN * 9 / 10

#define _DIS_FROM_TOP_ 25
#define _DIS_FROM_LEFT_ 25

#define _MAX_HEALTH_ 3
#define _THICK_LINE_ 5

#define _HEIGH_ICON_ 20
#define _WIDTH_ICON_ 20
#define _SPACE_BET_OBJ_ 10

namespace weapon {
    const std::string fire_ball = "Fire Ball";
    const std::string triple_ball = "Triple Ball";
    const std::string small_ball = "Tiny Ball";
    const std::string big_ball = "Big Ball";
}

#endif /* Define_Header_h */
