/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:53:59 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/30 19:10:02 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	std::cout << std::endl;
    std::cout << "TESTING ZOMBIE CLASS USING STACK ALLOCATION" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
    std::cout << "Calling randomChump()..." << std::endl;

    randomChump("StackZombie");
	
    std::cout << "randomChump() finished." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
    std::cout << "TESTING ZOMBIE CLASS USING HEAP ALLOCATION" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::endl;
    std::cout << "Calling newZombie()..." << std::endl;
	
    Zombie* zombie1 = newZombie("HeapZombie");
	
    std::cout << "newZombie() finished." << std::endl;
	std::cout << std::endl;
    std::cout << "Calling announce() on heap-allocated zombie..." << std::endl;
	
    zombie1->announce();
	
    std::cout << "announce() finished." << std::endl;
	std::cout << std::endl;
    std::cout << "Deleting the heap-allocated zombie..." << std::endl;

    delete zombie1;
	
    std::cout << "Heap-allocated zombie deleted." << std::endl;
	std::cout << std::endl;
    return (0);
}
