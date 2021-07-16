#include "Func.hpp"
#include <iostream>

namespace basics
{

int mull(int i, int j) {
    return i * j;
}

int divid(int i, int j) {
    return i / j;
}

void printEven(int num) {
    if(isEven(num)) std::cout << "even\n";
    else std::cout << "odd\n";
}

bool isEven(int num)
{
    return num / 2 == 0 ? true : false;
}

std::vector<int> multiplyList(std::vector<int> input, int multiplier)
{
    for(auto& item : input) item = basics::mull(item, multiplier);
    return input;
}

}
