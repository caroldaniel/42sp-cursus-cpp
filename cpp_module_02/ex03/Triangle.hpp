/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:02:02 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/09 22:48:20 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include "Point.hpp"

class Triangle {
private:
	Point _a;
	Point _b;
	Point _c;
public:
	// Constructors & Destructors
	Triangle(void);
	Triangle(const Point &a, const Point &b, const Point &c);
	Triangle(const Triangle &other);
	~Triangle(void);

	// Assignment Operator overload
	Triangle	&operator=(const Triangle &other);

	// Getters
	Point	getA(void) const;
	Point	getB(void) const;
	Point	getC(void) const;

	// Methods
	bool	containsPoint(Point const &p) const;
};

#endif