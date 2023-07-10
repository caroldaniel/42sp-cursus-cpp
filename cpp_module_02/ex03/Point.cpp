/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:50:28 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/09 22:45:56 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors & Destructors
Point::Point(void) : _x(0), _y(0) {
	return ;
}
Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {
	return ;
}
Point::Point(const Point &other) : _x(other._x), _y(other._y) {
	return ;
}
Point::~Point(void) {
	return ;
}

// Assignment Operator overload
Point &Point::operator=(const Point &other) {
	if (this == &other)
		return (*this);
	_x = other._x;
	_y = other._y;
	return (*this);
}

// Arithmetic Operator overload
Point Point::operator+(const Point &other) const {
	return (Point(_x + other._x, _y + other._y));
}
Point Point::operator-(const Point &other) const {
	return (Point(_x - other._x, _y - other._y));
}
Point Point::operator*(const Point &other) const {
	return (Point(_x * other._x, _y * other._y));
}
Point Point::operator/(const Point &other) const {
	return (Point(_x / other._x, _y / other._y));
}

// Comparison Operator overload
bool Point::operator==(const Point &other) const {
	return (_x == other._x && _y == other._y);
}
bool Point::operator!=(const Point &other) const {
	return (_x != other._x || _y != other._y);
}
bool Point::operator>(const Point &other) const {
	return (_x > other._x && _y > other._y);
}
bool Point::operator<(const Point &other) const {
	return (_x < other._x && _y < other._y);
}
bool Point::operator>=(const Point &other) const {
	return (_x >= other._x && _y >= other._y);
}
bool Point::operator<=(const Point &other) const {
	return (_x <= other._x && _y <= other._y);
}

// Getters
Fixed Point::getX(void) const {
	return (_x);
}
Fixed Point::getY(void) const {
	return (_y);
}

// Dot Product
Fixed Point::dotProduct(const Point &other) const {
	return (_x * other._x + _y * other._y);
}