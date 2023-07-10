/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:50:43 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/09 22:35:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
private:
	Fixed _x;
	Fixed _y;
public:
	Point(void);
	Point(const Point &other);
	Point(const Fixed x, const Fixed y);
	~Point(void);

	Point	&operator=(const Point &other);
	// Arithmetic Operator overload
	Point	operator+(const Point &other) const;
	Point	operator-(const Point &other) const;
	Point	operator*(const Point &other) const;
	Point	operator/(const Point &other) const;
	// Comparison Operator overload
	bool	operator==(const Point &other) const;
	bool	operator!=(const Point &other) const;
	bool	operator>(const Point &other) const;
	bool	operator<(const Point &other) const;
	bool	operator>=(const Point &other) const;
	bool	operator<=(const Point &other) const;
	// Getters
	Fixed	getX(void) const;
	Fixed	getY(void) const;
	// Dot product
	Fixed	dotProduct(const Point &other) const;
};

#endif