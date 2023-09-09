/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:42:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/09 00:16:18 by cado-car         ###   ########.fr       */
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
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (_isOperand(token))
            _operands.push(std::strtod(token.c_str(), NULL));
        else if (_isOperator(token))
            try {
                _doOperation(token.begin()[0]);
            } catch (std::exception &e) {
                throw EvaluateErrorException(e.what());
            }
        else
            throw EvaluateErrorException("Error");       
    }
    if (_operands.size() != 1)
        throw EvaluateErrorException("Error");
    return (_operands.top());
}

/*
** _isOperator()
** -------------
** Checks if the character passed as parameter is an operator.
*/
bool RPNEvaluator::_isOperator(std::string token) {
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return (true);
    return (false);
}

/*
** _isOperand()
** ------------
** Checks if the character passed as parameter is an operand.
*/
bool RPNEvaluator::_isOperand(std::string token) {
    int nb;

    for (std::string::iterator it = token.begin(); it != token.end(); it++) {
        if (!std::isdigit(*it))
            return (false);
    }
    nb = std::atoi(token.c_str());
    if (nb < 0 || nb > 9)
        return (false);
    return (true);        
}

/*
** _doOperation()
** --------------
** Performs the operation passed as parameter on the two previous operands in the stack.
*/
void RPNEvaluator::_doOperation(char op) {
    double result = 0;
    double op1 = 0;
    double op2 = 0;

    if (_operands.size() < 2)
        throw EvaluateErrorException("Error");
    op2 = _operands.top();
    _operands.pop();
    op1 = _operands.top();
    _operands.pop();
    switch (op)
    {
    case '+':
        result = op1 + op2;
        break;
    case '-':
        result = op1 - op2;
        break;
    case '*':
        result = op1 * op2;
        break;
    case '/':
        if (op2 == 0){
            throw EvaluateErrorException("Division by zero.");
            return ;
        }
        result = op1 / op2;
        break;
    default:
        throw EvaluateErrorException("Error");
        return ;
    }
    _operands.push(result);
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