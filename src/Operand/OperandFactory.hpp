#include <string>
#include <array> 
#include <memory>
#include "IOperand.hpp"
#include "eOperandType.hpp"
#include "ePrecision.hpp"


#pragma once


class OperandFactory : public IOperand {

    private:

        /* Methods */
        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;

        /* Array of operand created function */
        std::array<IOperand const *(OperandFactory::*)(std::string const &) const, 5> _createOperand 
        {
            &OperandFactory::createInt8,
            &OperandFactory::createInt16,
            &OperandFactory::createInt32,
            &OperandFactory::createFloat,
            &OperandFactory::createDouble
        };

    public:

        /* Coplien */
        OperandFactory();//Default constructor
        OperandFactory(const OperandFactory &rhs) = delete;//copy constructor
        OperandFactory &operator=(const OperandFactory &rhs) = delete;//copy assignment
        ~OperandFactory();//Destructor


        /* Override*/
        int getPrecision( void ) const = 0; // Precision of the type of the instance
        eOperandType getType( void ) const = 0; // Type of the instance

        IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
        IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
        IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
        IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
        IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo

        std::string const &toString( void ) const = 0; // String representation of the instance

        /* Factory */
        IOperand const *createOperand( eOperandType type, std::string const & value ) const;
};