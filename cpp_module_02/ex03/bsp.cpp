/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:16:53 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/11 16:18:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Triangle.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Triangle triangle = Triangle(a, b, c);

	// Check if the point is inside the triangle
	return(triangle.containsPoint(point));
}
