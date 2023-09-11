/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:29:00 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/11 12:25:38 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data {
    Data(void);
    Data(std::string publicData, std::string privateData, int privateNumber);
    ~Data(void);
    Data(Data const &source);
    Data &operator=(Data const &source);
    
    std::string publicData;
    
    // Getters
    std::string getPrivateData(void) const;
    int         getPrivateNumber(void) const;
private:
    std::string _privateData;
    int         _privateNumber;
};

#endif