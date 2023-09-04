/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:42:37 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/04 17:28:53 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <sstream>
# include <iomanip>
# include <cmath>
# include <stack>

class RPNEvaluator
{
private:
    // Attributes
    std::stack<double> _operands;
    // Member functions
    bool _isOperator(std::string token);
    bool _isOperand(std::string token);
    void _doOperation(char op);
public:
    // Constructors and destructor
    RPNEvaluator();
    RPNEvaluator(RPNEvaluator const &src);
    ~RPNEvaluator();
    // Operator overloads
    RPNEvaluator &operator=(RPNEvaluator const &src);
    // Member functions
    double evaluate(std::string expression);

    // Exceptions
    class EvaluateErrorException : public std::exception {
        public:
            EvaluateErrorException(const std::string& message);
            virtual ~EvaluateErrorException() throw() {};
            virtual const char *what() const throw();
        private:
            std::string _message;
    };
};

#endif