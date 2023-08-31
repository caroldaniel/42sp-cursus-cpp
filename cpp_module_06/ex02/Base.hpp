/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:55:41 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/30 21:03:10 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <stdint.h>

// Base class
class Base {
    public:
        virtual ~Base(void);
};

// Inherited classes
class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif