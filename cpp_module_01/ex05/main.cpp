/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:29 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/04 16:53:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void dialogue(void)
{
    Harl harl;

    // Test different complaint levels
    std::cout << "[CLERK]" << std::endl;
    std::cout << "Oh! Yes, sir. How can I help you now?" << std::endl;
    std::cout << std::endl;

    std::cout << "[HARL]" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    std::cout << "[CLERK]" << std::endl;
    std::cout << "Certainly, sir! We offer additional toppings for an extra charge. I'll make sure to add more bacon to your order." << std::endl;
    std::cout << std::endl;

    std::cout << "[HARL]" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "[CLERK]" << std::endl;
    std::cout << "I apologize for the inconvenience, sir, but all our burguers come with the exact same amount of bacon." << std::endl;
    std::cout << std::endl;
    
    std::cout << "[HARL]" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    
    std::cout << "[CLERK]" << std::endl;
    std::cout << "I'm sorry, sir, but I'm afraid I can't do that." << std::endl;
    std::cout << std::endl;

    std::cout << "[HARL]" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    
    std::cout << "[CLERK]" << std::endl;
    std::cout << "I'll call them for y..." << std::endl;
    std::cout << std::endl;

    std::cout << "[HARL]" << std::endl;
    harl.complain("INVALID");
    std::cout << std::endl;

    return ;
}

int main(void) {
    dialogue();
    std::cout << "[CLERK] (to another Clerk)" << std::endl;
    std::cout << "Thank God" << std::endl;
    std::cout << std::endl;
    return (0);
}