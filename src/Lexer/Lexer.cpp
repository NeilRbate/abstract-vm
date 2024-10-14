#include "Lexer.hpp"
#include <iostream>
#include <sstream>

/* CTOR */
Lexer::Lexer(const std::vector<std::string> &data)
{
    this->_data = data;
    syntaxAnalysis();
}

Lexer::~Lexer() {}

Lexer::Lexer(Lexer const &rhs) { *this = rhs; }

Lexer &Lexer::operator=(Lexer const &rhs) 
{
    this->_data = rhs.getData();
    this->_mdata = rhs.getMdata();
    return *this;
}

/* Get */
std::vector<std::string> Lexer::getData() const { return _data; }
std::vector<std::tuple<Token, std::string>> Lexer::getMdata() const { return _mdata; }

/* Private methods */

bool Lexer::isSemicolon(const char c) const { return c == ';' ? true : false; }

std::tuple<Token, std::string>    isValidType(const std::string &str, Token t)
{
    std::istringstream  stream(str);
    std::vector<std::string>    vec;

    //Split string with (
    for (std::string line; std::getline(stream, line, '(');)
        vec.push_back(line);

    if (vec.size() != 2 || vec[1].back() != ')')
        return std::make_tuple(Invalid, str);

    vec[1].pop_back();

    if (vec[1].find_first_not_of("0123456789.") != std::string::npos)
        return std::make_tuple(Invalid, str);

    int pNb = 0;
    for(auto c : vec[1]) {
        if (c == '.')
            pNb++;
    }

    if (pNb > 1)
        return std::make_tuple(Invalid, str);
        

    std::string ret = vec[0] + "_" + vec[1];

    return std::make_tuple(t, ret);
}

std::tuple<Token, std::string> Lexer::extractToken(const std::string &str) const
{
    if (str.size() < 3)
        return std::make_tuple(Invalid, str);

    //Find simple instruction
    if (str.find("pop") == 0 && str.size() == 3)
        return std::make_tuple(Pop, str);
    if (str.find("dump") == 0 && str.size() == 4)
        return std::make_tuple(Dump, str);
    if (str.find("add") == 0 && str.size() == 3)
        return std::make_tuple(Add, str);
    if (str.find("sub") == 0 && str.size() == 3)
        return std::make_tuple(Sub, str);
    if (str.find("mul") == 0 && str.size() == 3)
        return std::make_tuple(Mul, str);
    if (str.find("div") == 0 && str.size() == 3)
        return std::make_tuple(Div, str);
    if (str.find("mod") == 0 && str.size() == 3)
        return std::make_tuple(Mul, str);
    if (str.find("print") == 0 && str.size() == 5)
        return std::make_tuple(Print, str);
    if (str.find("exit") == 0 && str.size() == 4)
        return std::make_tuple(Exit, str);

    //Find complexe instruction
    if (str.find("push") == 0 && str.size() > 4) {
        return isValidType(str.substr(4, str.size()), Push);
    } else if (str.find("assert") == 0) {
        return isValidType(str.substr(6, str.size()), Assert);
    }

    return std::make_tuple(Invalid, str);

}


void Lexer::syntaxAnalysis()
{
    if (_data.empty())
        throw Emptyexception("Vector data is empty");
    
    for (auto elem : _data) {
        //Trim
        elem.erase(remove_if(elem.begin(), elem.end(), isspace), elem.end());

        //Delete commentary
        auto pos = elem.find(';');
        if (pos != std::string::npos)
            elem.erase(elem.begin() + pos, elem.end());

        //Insert value in map if it's real value
        auto v = extractToken(elem);

        if (std::get<0>(v) != Invalid) {
            _mdata.push_back(v);
        }
        else 
            std::cerr << "Invalid instruction : " << elem << std::endl;
    }
    
}


