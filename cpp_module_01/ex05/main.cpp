/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:29 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/04 19:19:18 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void dialogue(void);
static void clerk_dialogue(std::string& line);
static void harl_dialogue(Harl &harl, std::string& level);

int main(int argc, char *argv[]) {
    argv = (char **)argv;
    if (argc != 1) {
        std::cout << "Usage: ./harl" << std::endl;
        return (1);
    }
    dialogue();
    std::cout << "[CLERK] (to another Clerk)" << std::endl;
    std::cout << "Thank God" << std::endl;
    std::cout << std::endl;
    return (0);
}

static void dialogue(void) {
    Harl harl;

    std::string harl_levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "INVALID"};
    std::string clerk_lines[5] = {
        "Oh! Yes, sir. How can I help you now?",
        "Certainly, sir! We offer additional toppings for an extra charge. I'll make sure to add more bacon to your order.",
        "I apologize for the inconvenience, sir, but all our burguers come with the exact same amount of bacon.",
        "I'm sorry, sir, but I'm afraid I can't do that.",
        "I'll call them for y..."   
    };
    
    // Test different complaint levels
    for (int i = 0; i < 5; i++)
    {
        clerk_dialogue(clerk_lines[i]);
        harl_dialogue(harl, harl_levels[i]);
    }
    return ;
}

static void clerk_dialogue(std::string& line) {
    std::cout << "[CLERK]" << std::endl;
    std::cout << line << std::endl;
    std::cout << std::endl;
    return;
}

static void harl_dialogue(Harl &harl, std::string& level) {
    std::cout << "[HARL]" << std::endl;
    harl.complain(level);
    std::cout << std::endl;
    return;
}
