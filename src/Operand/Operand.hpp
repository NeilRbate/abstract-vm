#pragma once

#include <string>
#include <array> 
#include <memory>
#include "IOperand.hpp"
#include "eOperand.hpp"
#include "ePrecision.hpp"

class Operand : public IOperand {

    private:

        /* Methods */
        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;

        /* Attributes */
        std::string _value;
        eOperandType _type;
        int _precision;

        /* Array of operand created function */
        std::array<IOperand const *(Operand::*)(std::string const &) const, 5> _createOperand 
        {
            &Operand::createInt8,
            &Operand::createInt16,
            &Operand::createInt32,
            &Operand::createFloat,
            &Operand::createDouble
        };

    public:
        /* Coplien */
        Operand() = delete;// No default constructor
        Operand(const Operand &rhs);//copy constructor
        Operand &operator=(const Operand &rhs);//copy assignment
        ~Operand();//destructor

        /* Constructor */
        Operand(eOperandType type, const std::string &value);

        /* Override*/
        int getPrecision( void ) const; // Precision of the type of the instance
        eOperandType getType( void ) const; // Type of the instance

        IOperand const *Operand::compute(std::string const &value1, std::string const &value2, ePrecision type,eOperandType operandType); // Compute operator overload 

        IOperand const * operator+( IOperand const & rhs ) const; // Sum
        IOperand const * operator-( IOperand const & rhs ) const; // Difference
        IOperand const * operator*( IOperand const & rhs ) const; // Product
        IOperand const * operator/( IOperand const & rhs ) const; // Quotient
        IOperand const * operator%( IOperand const & rhs ) const; // Modulo

        std::string const &toString( void ) const; // String representation of the instance

        /* Factory */
        IOperand const *createOperand( eOperandType type, std::string const & value ) const;
};