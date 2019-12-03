
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
#define _SPACE_BET_OBJ_ 30

#define sqr(x) x * x

// vận tốc bóng theo x
#define _VELOCITY_X_ 0.3
// vận tốc bóng theo y
#define _VELOCITY_Y_ 0.3
// vận tốc thanh trượt
#define _VELOCITY_X_BAR_ 0.5
// tốc độ thay đổi thay trượt
#define _VELOCITY_Y_BAR_STEP_ 0.1
// vận tốc bóng nhanh nhất
#define _MAX_VELOCITY_ 10
// tốc độ thay đổi vận tốc
#define _ACCELERATION_ 1.1
#define _ACCELERATION_BAR_ 5
// cạnh quả bóng
#define _SIZE_PONG_ 19
#define _SMALL_NUMBER_ 0.001
#define _MAX_CHANGE_VELOC_ 3
#define _ANGLE_BUFF_ 0.3

#define _HEIGH_BAR_ 12
#define _WIDTH_BAR_ _WIDTH_TABLE_GAME_/3.8

// color of brick
const sf::Color PREVENT_BRICK = sf::Color(255, 102, 0);
const sf::Color SPECIAL_BRICK = sf::Color(255, 202, 58);
// FRAME WINDOW
#define MAX_FRAME_LIMIT 300
#define FRAME ((_WIDTH_TABLE_GAME_ * 1.0 / _VELOCITY_X_ < MAX_FRAME_LIMIT) ? (_WIDTH_TABLE_GAME_ * 1.0 / _VELOCITY_X_) : MAX_FRAME_LIMIT)

namespace weapon {
    const std::string fire_ball = "Fire Ball";
    const std::string triple_ball = "Triple Ball";
    const std::string small_ball = "Tiny Ball";
    const std::string big_ball = "Big Ball";
}

#define NumberOfColor 8
#define SpeechChangeColor 3
enum MyColor{
    Silver,
    Asparagus,
    Midnight,
    Purple,
    Red,
    Yellow,
    Blue,
    Green
};

#endif /* Define_Header_h */
