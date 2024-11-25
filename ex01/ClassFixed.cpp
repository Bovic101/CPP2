/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassFixed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:14:16 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/25 16:35:13 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassFixed.hpp"

// Default Constructor
Fixed::Fixed() : value(0) 
{
    std::cout << "Default Constructor called" << std::endl;
}

// Constructor for integer
Fixed::Fixed(const int integer) 
{
    std::cout << "Integer Constructor called" << std::endl;
    value = integer << fraction_part;  // Scaling of int to fixed-point
}

// Float Constructor
Fixed::Fixed(const float floating) 
{
    std::cout << "Float Constructor called" << std::endl;
    value = roundf(floating * (1 << fraction_part));  // Scaling of float to fixed-point
}

// Copy Constructor
Fixed::Fixed(const Fixed& copy) 
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = copy;  //  to copy assignment operator
}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed& copy) 
{
    std::cout << "Copy Assignment Operator called" << std::endl;

    if (this != &copy) {
        this->value = copy.getRawBits();  // Copy the raw value
    }
    return *this;  // Allow for chained assignments
}

// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const 
{
    std::cout << "getRawBits called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits called" << std::endl;
    value = raw;
}

// Convert Fixed-point number to int
int Fixed::toInt() const 
{
    return value >> fraction_part;  // Scaling down to integer
}

// Convert Fixed-point number to float
float Fixed::toFloat() const 
{
    return static_cast<float>(value) / (1 << fraction_part);  // Scaling down to float
}

// Overloaded operator to print fixed-point number as floating point
std::ostream& operator<<(std::ostream& out, const Fixed& val) 
{
    out << val.toFloat();
    return out;
}
