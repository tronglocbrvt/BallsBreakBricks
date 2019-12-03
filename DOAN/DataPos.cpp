#include "DataPos.hpp"

Pos copyPos(float x, float y, float endX, float endY){      // tạo một bản copy dạng struct lưu dữ liệu
    Pos p;
    p.x = x - endX;
    p.y = y;
    p.endX = endX;
    p.endY = endY;
    return p;
}
