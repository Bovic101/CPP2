/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassFixed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:47:18 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/27 10:47:32 by vodebunm         ###   ########.fr       */
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
    *this = copy;  // to copy assignment operator
}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed& copy) 
{
    std::cout << "Copy Assignment Operator called" << std::endl;

    if (this != &copy) 
	{
        this->value = copy.value;  // Copy the raw value
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

// Relational ops
bool Fixed::operator<=(const Fixed& cp) const
{
    return (this->value <= cp.value);
}

bool Fixed::operator>=(const Fixed& cp) const
{
    return (this->value >= cp.value);
}

bool Fixed::operator>(const Fixed& cp) const
{
    return (this->value > cp.value);
}

bool Fixed::operator<(const Fixed& cp) const
{
    return (this->value < cp.value);
}

bool Fixed::operator!=(const Fixed& cp) const
{
    return (this->value != cp.value);
}

bool Fixed::operator==(const Fixed& cp) const
{
    return (this->value == cp.value);
}

// Arithmetic ops
Fixed Fixed::operator+(const Fixed& cp) const
{
    Fixed result;
    result.value = this->value + cp.value; // Directly add the raw values
    return result;
}

Fixed Fixed::operator-(const Fixed& cp) const
{
    Fixed result;
    result.value = this->value - cp.value; // Directly subtract the raw values
    return result;
}

Fixed Fixed::operator*(const Fixed& cp) const
{
    Fixed result;
    result.value = (this->value * cp.value) >> fraction_part; // scale during multiplication
    return result;
}

Fixed Fixed::operator/(const Fixed& cp) const
{
    if (cp.value == 0) {
        throw std::runtime_error("Division by zero");
    }
    Fixed result;
    result.value = (this->value << fraction_part) / cp.value; // Correctly scale during division
    return result;
}

// Unary Operators
Fixed& Fixed::operator++() // Pre-increment
{
    ++value;
    return *this;
}

Fixed Fixed::operator++(int) // Post-increment
{
    Fixed tmp = *this;
    value++;
    return tmp; 
}

Fixed& Fixed::operator--() // Pre-decrement
{
    --value;
    return *this;
}

Fixed Fixed::operator--(int) // Post-decrement
{
    Fixed tmp = *this;
    value--;
    return tmp;
}

//Min and Min Function

Fixed& Fixed::min(Fixed& num1, Fixed& num2) 
{ 
    return (num1 < num2) ? num1 : num2; 
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2) 
{ 
    return (num1 > num2) ? num1 : num2; 
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2) 
{ 
    return (num1 < num2) ? num1 : num2; 
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2) 
{ 
    return (num1 > num2) ? num1 : num2; 
}

std::ostream& operator<<(std::ostream& cout, const Fixed& val) 
{
    cout << val.toFloat();
    return cout;
}
