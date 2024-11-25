/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:14:05 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/25 16:39:04 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassFixed.hpp" // Include the header fi

int main() {
    Fixed a; // Default constructor
    Fixed const b(10); // Integer constructor
    Fixed const c(42.42f); // Float constructor
    Fixed const d(b); // Copy constructor

    a = Fixed(1234.4321f);
	
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}