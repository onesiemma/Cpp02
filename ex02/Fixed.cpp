/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:37:44 by ombatkam          #+#    #+#             */
/*   Updated: 2025/11/07 15:01:10 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value (0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(int n)
{
    //std::cout << "Int constructor called" << std::endl;
    value = n << bits;
}

Fixed::Fixed(const float f) {
    //std::cout << "Float constructor called" << std::endl;
    value = roundf(f * (1 << bits));
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.value;
    return (*this);
}
// Comparaisons operators
bool   Fixed::operator>(const Fixed& other) const
{
    return(value > other.value);
}

bool   Fixed::operator<(const Fixed& other) const
{
    return(value < other.value);
}

bool   Fixed::operator==(const Fixed& other) const
{
    return(value == other.value);
}

bool   Fixed::operator>=(const Fixed& other) const
{
    return(value >= other.value);
}

bool   Fixed::operator<=(const Fixed& other) const
{
    return(value <= other.value);
}

bool   Fixed::operator!=(const Fixed& other) const
{
    return(value != other.value);
}
// Arithmetic operators
Fixed   Fixed::operator+(const Fixed& other) const
{
    Fixed   result;
    result.value = value + other.value;
    return (result);
}

Fixed   Fixed::operator-(const Fixed& other) const
{
    Fixed   result;
    result.value = value + other.value;
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long    tmp;
    tmp = static_cast<long>(value) * static_cast<long>(other.value);
    result.value = static_cast<int>(tmp >> bits);
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    long    tmp;
    tmp = static_cast<long>(value) / static_cast<long>(other.value);
    result.value = static_cast<int>(tmp >> bits);
    return (result);
}

// incrementation/decrementation

Fixed&  Fixed::operator++()
{
    value++;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   temp (*this);
    value++;
    return (temp);
}

Fixed&  Fixed::operator--()
{
    value--;
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed   temp(*this);
    value--;
    return (temp);
}

// Max/Min

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    return ((a > b) ? a : b);
}

Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
    return ((a < b) ? a : b);
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b)
{
    return ((a > b) ? a : b);
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b)
{
    return ((a < b) ? a : b);
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(value) / (1 << bits));
}

int Fixed::toInt(void) const {
    return (value >> bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}