#include "TOperand.hpp"


class Int8 : public TOperand<int>{
    public:
        Int8(int value, eOperandType type, ePrecision precision) : TOperand<int>(value, type, precision) {};
};
class Int16: public TOperand<int>{

    public:
        Int16(int value, eOperandType type, ePrecision precision) : TOperand<int>(value, type, precision) {};
};

class Int32 : public TOperand<int>{

	public:
		Int32(int value, eOperandType type, ePrecision precision) : TOperand<int>(value, type, precision) {};
};

class Float : public TOperand<float>{
    public:
        Float(float value, eOperandType type, ePrecision precision) : TOperand<float>(value, type, precision) {};
};

class Double : public TOperand<double>{
    public:
        Double(double value, eOperandType type, ePrecision precision) : TOperand<double>(value, type, precision) {};
};
