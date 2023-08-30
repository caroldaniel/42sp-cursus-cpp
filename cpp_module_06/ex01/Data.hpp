/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:29:00 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/30 20:33:08 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data {
    Data(void);
    ~Data(void);
    Data(Data const &source);
    Data &operator=(Data const &source);
    
    std::string publicData;
private:
    std::string _privateData;
    int         _privateNumber;
};

#endif