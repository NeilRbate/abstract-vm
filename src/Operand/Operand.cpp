#include "TOperand.hpp"

class Int8 : public TOperand<int>{
    public:
        Int8(int value, eOperandType type, ePrecision precision) : TOperand<int>(value, type, precision) {};
        ~Int8() {};
        //using TOperand<int>::TOperand;



};
class Int16: public TOperand<int>{

    public:
        Int16(int value, eOperandType type, ePrecision precision) : TOperand<int>(value, type, precision) {};
        ~Int16() {};
        //using TOperand<int>::TOperand;
};

class Int32 : public TOperand<int>{};

class Float : public TOperand<float>{};

class Double : public TOperand<double>{};