#include "TOperand.hpp"


class Int8 : public TOperand<int>{
    public:
        Int8(int value, eOperandType type, ePrecision precision) : TOperand<int>(value, type, precision)  {
            if (value > std::numeric_limits<int8_t>::max()) {
                throw OverflowException();
            } else if (value < std::numeric_limits<int8_t>::min()) {
                throw UnderflowException();
            }
        };
};

class Int16: public TOperand<int>{

    public:
        Int16(int value, eOperandType type, ePrecision precision) : TOperand<int>(value, type, precision) {
            if (value > std::numeric_limits<int16_t>::max()) {
                throw OverflowException();
            } else if (value < std::numeric_limits<int16_t>::min()) {
                throw UnderflowException();
            }
        };
};

class Int32 : public TOperand<int>{

	public:
		Int32(int value, eOperandType type, ePrecision precision) : TOperand<int>(value, type, precision) {
            if (value > std::numeric_limits<int32_t>::max()) {
                throw OverflowException();
            } else if (value < std::numeric_limits<int32_t>::min()) {
                throw UnderflowException();
            }
        };
};

class Float : public TOperand<float>{
    public:
        Float(float value, eOperandType type, ePrecision precision) : TOperand<float>(value, type, precision) {
            if (value > std::numeric_limits<float>::max()) {
                throw OverflowException();
            } else if (value < std::numeric_limits<float>::min()) {
                throw UnderflowException();
            }
        };
};

class Double : public TOperand<double>{
    public:
        Double(double value, eOperandType type, ePrecision precision) : TOperand<double>(value, type, precision) {
            if (value > std::numeric_limits<double>::max()) {
                throw OverflowException();
            } else if (value < std::numeric_limits<double>::min()) {
                throw UnderflowException();
            }
        };
};
