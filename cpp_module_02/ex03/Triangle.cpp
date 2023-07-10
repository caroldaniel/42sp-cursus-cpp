/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:01:45 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/09 22:40:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Triangle.hpp"

// Constructors & Destructors
Triangle::Triangle(void) : _a(0, 0), _b(0, 0), _c(0, 0) {
	return ;
}
Triangle::Triangle(const Point &a, const Point &b, const Point &c) : _a(a), _b(b), _c(c) {
	return ;
}
Triangle::Triangle(const Triangle &other) : _a(other._a), _b(other._b), _c(other._c) {
	return ;
}
Triangle::~Triangle(void) {
	return ;
}

// Assignment Operator overload
Triangle &Triangle::operator=(const Triangle &other) {
	if (this == &other)
		return (*this);
	_a = other._a;
	_b = other._b;
	_c = other._c;
	return (*this);
}

// Getters
Point Triangle::getA(void) const {
	return (_a);
}
Point Triangle::getB(void) const {
	return (_b);
}
Point Triangle::getC(void) const {
	return (_c);
}

// Methods
bool	Triangle::containsPoint(Point const &p) const {
	  // Calculate vectors
  Point v0 = _c - _a;
  Point v1 = _b - _a;
  Point v2 = p - _a;

  // Calculate dot products
  Fixed dot00 = v0.dotProduct(v0);
  Fixed dot01 = v0.dotProduct(v1);
  Fixed dot02 = v0.dotProduct(v2);
  Fixed dot11 = v1.dotProduct(v1);
  Fixed dot12 = v1.dotProduct(v2);

  // Compute barycentric coordinates
  Fixed invDenom = (dot00 * dot11) - (dot01 * dot01);
  Fixed u = ((dot11 * dot02) - (dot01 * dot12)) / invDenom;
  Fixed v = ((dot00 * dot12) - (dot01 * dot02)) / invDenom;

  // Check if the point is inside the triangle
  return (u >= Fixed(0) && v >= Fixed(0) && (u + v) <= Fixed(1));
}