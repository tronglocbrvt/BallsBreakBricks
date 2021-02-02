#include "mathfunction.hpp"


int myMath::absInt(int number){                     // trả về giá trị tuyệt đối của số nguyên
    if (number < 0) {
        return (-number);
    }
    return number;
}
float myMath::absFloat(float number){               // trả về giá trị tuyệt đối của số thực
    if (number < 0) {
        return (-number);
    }
    return number;
}
short myMath::CountIntNumberRadix(int number){      // đếm số lượng chữ số của số nguyên
    int newNumber = myMath::absInt(number);
    short countRadix = 0;
    while (newNumber > 0) {
        newNumber /= 10;
        countRadix++;
    }
    return countRadix;
}
short myMath::squareOf(float number){               // bình phương của một số
    return number*number;
}
short myMath::squarerootOf(float number){           // căn bậc 2 của một số
    return std::sqrt(number);
}

