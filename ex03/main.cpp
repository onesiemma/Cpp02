/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:09:20 by ombatkam          #+#    #+#             */
/*   Updated: 2025/11/07 15:19:54 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(3, 3);
    Point outside(10, 5);
    Point edge(5, 0);

    std::cout << std::boolalpha;
    std::cout << "Inside? " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside? " << bsp(a, b, c, outside) << std::endl;
    std::cout << "On edge? " << bsp(a, b, c, edge) << std::endl;

    return 0;
}


