/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:11:11 by ombatkam          #+#    #+#             */
/*   Updated: 2025/11/07 15:25:25 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0){}
Point::Point(const float x, const float y) : x(x), y(y) {}
Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
    (void)other;
    return (*this);
}

Point::~Point() {}

Fixed Point::getX(void) const
{ 
    return (x);
}
Fixed Point::getY(void) const
{
    return (y);
}
