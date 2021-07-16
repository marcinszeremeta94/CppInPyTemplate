#include "DoCalcs.hpp"

namespace basics {
     
DoCalcs::DoCalcs(int inputArg)
    : innerArg{inputArg}
{
}

int DoCalcs::multiplyByArg(int arg)
{
    return arg * innerArg;
}

void DoCalcs::setInnerArg(int arg)
{
    innerArg = arg;
}
        
int  DoCalcs::getInnerArg() const
{
    return innerArg;
}

std::vector<std::vector<uint8_t>> DoCalcs::make_white_image()
{
    auto out = std::vector<std::vector<uint8_t>>();
    for(auto i = 0; i<128; ++i) out.emplace_back(std::vector<uint8_t>(128));
    for(auto& line : out) for(auto& pixel : line ) pixel = 255;
    return out;
}

}
