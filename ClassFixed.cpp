/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassFixed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:42:15 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/25 14:08:25 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassFixed.hpp"

// Default Constructor
Fixed::Fixed() : value(0) 
{
    std::cout << "Default Constructor" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed& copy) : value(copy.value) 
{
    std::cout << "Copy Constructor" << std::endl;
}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed& copy) 
{
    std::cout << "Copy Assignment Operator" << std::endl;

    if (this != &copy) 
	{ 
        this->value = copy.value; //Check for self-assignment andCopy the value
    }
    return *this; //allow for chained assignments
}

//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor\n";
}

int Fixed::getRawBits() const
{
	std::cout <<"get the rew value of the fixed-point"<<std::endl;
}

void Fixed::setRawBits(int const raw)
{
	std::cout <<"set the raw value of the fixed-point value\n";
	value = raw;
}