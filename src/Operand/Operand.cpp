#include "TOperand.hpp"

class Int8 : public TOperand<int>{
    public:
        Int8() = delete;
        using TOperand<int>::TOperand;
};
class Int16: public TOperand<int>{};

class Int32 : public TOperand<int>{};

class Float : public TOperand<float>{};

class Double : public TOperand<double>{};