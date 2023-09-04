/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:42:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/03 22:55:27 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
** Default constructor
*/
RPNEvaluator::RPNEvaluator(void) {
    return ;
}

/*
** Copy constructor
*/
RPNEvaluator::RPNEvaluator(RPNEvaluator const &src) {
    *this = src;
    return ;
}

/*
** Destructor
*/
RPNEvaluator::~RPNEvaluator(void) {
    return ;
}

/*
** Operator overload
*/
RPNEvaluator &RPNEvaluator::operator=(RPNEvaluator const &src) {
    if (this != &src)
        *this = src;
    return (*this);
}

/*
** evaluate()
** ----------
** Evaluates the expression passed as parameter and gives back the result.
*/
double RPNEvaluator::evaluate(std::string expression) {
    _tokenize(expression);
    while (!_expression.empty()) {
        if (_isOperand(_expression.top()[0]))
            _operands.push(std::strtod(this->_expression.top().c_str(), NULL));
        else if (_isOperator(this->_expression.top()[0])) {
            char op = this->_expression.top()[0];
            if (this->_operands.size() < 2)
                throw EvaluateErrorException("Invalid expression.");
            double op1 = _operands.top();
            _operands.pop();
            double op2 = _operands.top();
            _operands.pop();
            switch (op) {
                case '+':
                    _operands.push(op1 + op2);
                    break;
                case '-':
                    _operands.push(op1 - op2);
                    break;
                case '*':
                    _operands.push(op1 * op2);
                    break;
                case '/':
                    _operands.push(op1 / op2);
                    break;
                case '%':
                    _operands.push(fmod(op1, op2));
                    break;
                default:
                    throw EvaluateErrorException("Invalid expression.");
            } 
        }
        else
            throw EvaluateErrorException("Invalid expression.");
        this->_expression.pop();
    }
    return (0);

}

/*
** _isOperator()
** -------------
** Checks if the character passed as parameter is an operator.
*/
bool RPNEvaluator::_isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

/*
** _isOperand()
** ------------
** Checks if the character passed as parameter is an operand.
*/
bool RPNEvaluator::_isOperand(char c) {
    return (c >= '0' && c <= '9');
}

/*
** _tokenize()
** -----------
** Tokenizes the expression passed as parameter and saves the tokens in the rpn stack.
** The tokens will be split by any whitespace character.
*/
void RPNEvaluator::_tokenize(std::string expression) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
        _expression.push(token);
    return ;
}

/*
** EvaluateErrorException()
** ------------------------
** Exception class constructor.
*/
RPNEvaluator::EvaluateErrorException::EvaluateErrorException(const std::string& message) : _message(message) {
    return ;
}
const char *RPNEvaluator::EvaluateErrorException::what() const throw() {
    return (_message.c_str());
}