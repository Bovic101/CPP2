/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassFixed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:14:16 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/25 16:09:15 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassFixed.hpp"

// Default Constructor
Fixed::Fixed() : value(0) 
{
    std::cout << "Default Constructor called" << std::endl;
}

//Constructor for integer
Fixed::Fixed(const int integer)
{
	std::cout << "Integer Cconstructor called\n";
	value = integer <<fraction_part; //Scaling of int  to fixed-point
}

//Float Constructor
Fixed::Fixed(const float floating)
{
	std::cout << "Float constructor called\n";
	value = roundf(floating * (1 << fraction_part));
}

// Copy Constructor
Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy Constructor called" << std::endl;
	*this=copy;
}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed& copy) 
{
    std::cout << "Copy Assignment Operator called" << std::endl;

    if (this != &copy) 
	{ 
        this->value = copy.getRawBits(); //Check andCopy the value
    }
    return *this; //allow for chained assignments
}

//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	std::cout <<"get the raw value of the fixed-point"<<std::endl;
	return(value);
	
}

void Fixed::setRawBits(int const raw)
{
	std::cout <<"set the raw value of the fixed-point value\n";
	value = raw;
}

//Fixed-point number to int
int Fixed::toInt() const
{
	return(value >> fraction_part);//scaling down to integer
}

//Fixed-point number to float
float Fixed::toFloat() const
{
	return static_cast<float>(value)/ (1 <<fraction_part);
}

//Ovrelan the operator to print fixed-point to floating point num
std::ostream& operator << (std::ostream& overload, const Fixed& val)
{
	overload << val.toFloat();
	return(overload);
}