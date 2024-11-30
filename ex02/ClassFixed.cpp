/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassFixed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:47:18 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/30 07:44:24 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassFixed.hpp"

// Default Constructor
Fixed::Fixed() : value(0) {
   // std::cout << "Default Constructor called" << std::endl;
}

// Constructor for integer
Fixed::Fixed(const int integer) {
    //std::cout << "Integer Constructor called" << std::endl;
    value = integer << fraction_part;
}

// Constructor for float
Fixed::Fixed(const float floating) {
    //std::cout << "Float Constructor called" << std::endl;
    value = roundf(floating * (1 << fraction_part));
}

// Copy Constructor
Fixed::Fixed(const Fixed& copy) {
    //std::cout << "Copy Constructor called" << std::endl;
    *this = copy;
}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed& copy) {
    //std::cout << "Copy Assignment Operator called" << std::endl;
    if (this != &copy) {
        this->value = copy.value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    //std::cout << "Destructor called" << std::endl;
}

// Getter for raw value
int Fixed::getRawBits() const {
    //std::cout << "getRawBits called" << std::endl;
    return value;
}

// Setter for raw value
void Fixed::setRawBits(int const raw) {
    //std::cout << "setRawBits called" << std::endl;
    value = raw;
}

// Convert to integer
int Fixed::toInt() const {
    return value >> fraction_part;
}

// Convert to float
float Fixed::toFloat() const {
    return static_cast<float>(value) / (1 << fraction_part);
}

// Overload << operator for output
std::ostream& operator<<(std::ostream& out, const Fixed& val) 
{
    out << val.toFloat();
    return out;
}

// Relational Operators
bool Fixed::operator>(const Fixed& cp) const 
{ 
    return value > cp.value; 
}
bool Fixed::operator<(const Fixed& cp) const 
{ 
    return value < cp.value; 
}
bool Fixed::operator>=(const Fixed& cp) const 
{ 
    return value >= cp.value; 
}
bool Fixed::operator<=(const Fixed& cp) const 
{ 
    return value <= cp.value; 
}
bool Fixed::operator==(const Fixed& cp) const 
{ 
    return value == cp.value; 
}
bool Fixed::operator!=(const Fixed& cp) const 
{ 
    return value != cp.value; 
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed& cp) const 
{
    Fixed result;
    result.value = this->value + cp.value;
    return result;
}

Fixed Fixed::operator-(const Fixed& cp) const 
{
    Fixed result;
    result.value = this->value - cp.value;
    return result;
}

Fixed Fixed::operator*(const Fixed& cp) const 
{
    Fixed result;
    result.value = (this->value * cp.value) >> fraction_part;
    return result;
}

Fixed Fixed::operator/(const Fixed& cp) const 
{
    if (cp.value == 0) {
        throw std::runtime_error("Division by zero");
    }
    Fixed result;
    result.value = (this->value << fraction_part) / cp.value;
    return result;
}

// Unary Operators
Fixed& Fixed::operator++()
{
    ++value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    value++;
    return tmp;
}

Fixed& Fixed::operator--()
{
    --value;
    return *this;
}

Fixed Fixed::operator--(int) 
{ 
    // Post-decrement
    Fixed tmp = *this;
    value--;
    return tmp;
}

// Static Functions
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



