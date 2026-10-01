/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:16:24 by ombatkam          #+#    #+#             */
/*   Updated: 2025/11/07 15:18:01 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Helper to compute signed area * 2
static Fixed area(Point const a, Point const b, Point const c)
{
    return ((a.getX() * (b.getY() - c.getY())) +
            (b.getX() * (c.getY() - a.getY())) +
            (c.getX() * (a.getY() - b.getY())));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = area(a, b, c);
    Fixed areaPAB = area(point, a, b);
    Fixed areaPBC = area(point, b, c);
    Fixed areaPCA = area(point, c, a);

    // If point is on the same side of all triangle edges and not on edges
    if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
        return (false);

    // Check if the point is inside using sign consistency
    bool has_neg = (areaPAB < 0) || (areaPBC < 0) || (areaPCA < 0);
    bool has_pos = (areaPAB > 0) || (areaPBC > 0) || (areaPCA > 0);

    return !(has_neg && has_pos);
}
