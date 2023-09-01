/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:27:04 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/01 11:09:39 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void) {
    // Try to iterate through a stack
    std::cout << std::endl << YELLOW "Trying to iterate through a stack:" RESET << std::endl;
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);   
    std::cout << "\tStack: ";
    for (std::stack<int> dump = s; !dump.empty(); dump.pop())
        std::cout << dump.top() << " ";
    std::cout << std::endl;
    std::cout << RED "\t\tThe numbers are backwards 'cause that's the way a stack works." RESET << std::endl;
    std::cout << RED "\t\tYou can only ´push´ and ´pop´ elements from the top of the stack." RESET << std::endl;

    // Try to iterate through a MutantStack
    std::cout << std::endl << YELLOW "Trying to iterate through a MutantStack:" RESET << std::endl;
    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    std::cout << "\tMutantStack: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << GREEN "\t\tThe numbers are in the right order 'cause that's the way a MutantStack works." RESET << std::endl;
    std::cout << GREEN "\t\tYou can iterate through it using the underlying container iterator." RESET << std::endl;
    
    // Subject tests
    std::cout << std::endl << YELLOW "Subject tests #1 - Using MutantStack" RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> stack(mstack);
    
    std::cout << std::endl << YELLOW "Subject tests #2 - Using std::list" RESET << std::endl;
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    std::cout << lstack.back() << std::endl;
    lstack.pop_back();
    std::cout << lstack.size() << std::endl;
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    //[...]
    lstack.push_back(0);
    std::list<int>::iterator itl = lstack.begin();
    std::list<int>::iterator itle = lstack.end();
    ++itl;
    --itl;
    while (itl != itle) {
        std::cout << *itl << std::endl;
        ++itl;
    }
    std::list<int> list(lstack);

    std::cout << GREEN "\t\tThe results from the two previous tests must be the same." RESET << std::endl;
    std::cout << GREEN "\t\tIt means that we can use the underlying iterator for the MutantStack class." RESET << std::endl;
    
    return (0);
}
