/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:43:33 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/31 09:46:52 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include <iostream>
# include <string>

// function template for swap
template <typename T>
void	swap(T &a, T &b) {
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

// function template for min
template <typename T>
T		min(T a, T b) {
    if (a < b)
        return (a);
    return (b);
}

// function template for max
template <typename T>
T		max(T a, T b) {
    if (a > b)
        return (a);
    return (b);
}

#endif