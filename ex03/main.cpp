/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:47:26 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/27 11:10:42 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassFixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );  // Construct b from multiplication

    std::cout << a << std::endl;                   // Output the initial value of q
    std::cout << ++a << std::endl;                 // Pre-increment, prints a after increment
    std::cout << a << std::endl;                   // Prints a after increment
    std::cout << a++ << std::endl;                 // Post-increment, prints a before increment
    std::cout << a << std::endl;                   // Prints a after increment
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;  // Output the max of a and b

    return 0;
}
