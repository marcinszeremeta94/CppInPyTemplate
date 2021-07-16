#pragma once
#include <vector>

namespace basics {
class DoCalcs 
{
    public:
        DoCalcs(int inputArg = 2);
        int multiplyByArg(int arg);
        std::vector<std::vector<uint8_t>> make_white_image(); 

        void setInnerArg(int arg);
        int  getInnerArg() const;
    
    private:
        int innerArg;
};
}
