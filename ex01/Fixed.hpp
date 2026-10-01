/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:21:19 by ombatkam          #+#    #+#             */
/*   Updated: 2025/11/07 13:11:51 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 value;
    static const int    bits = 8;
public:
    Fixed();
    Fixed(const int n); 
    Fixed(const float f); 
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
    ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif