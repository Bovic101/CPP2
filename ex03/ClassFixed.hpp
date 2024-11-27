/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassFixed.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:46:29 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/27 09:49:13 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSFIXED_HPP
#define CLASSFIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int value; // Fixed-point number
    static const int fraction_part = 8;

public:
    Fixed(); // Default constructor
    Fixed(const int integer); // Constructor for int
    Fixed(const float floating); // Constructor for float
    Fixed(const Fixed& copy); // Copy constructor
    Fixed& operator=(const Fixed& copy); // Copy assignment operator
    ~Fixed(); // Destructor

	//Arithematic Op
	Fixed operator +(const Fixed& cp) const;
	Fixed operator *(const Fixed& cp) const;
	Fixed operator -(const Fixed& cp) const;
	Fixed operator /(const Fixed& cp) const;
	
	//Unary Op
	Fixed operator ++();//pre_increment
	Fixed operator --();
	Fixed operator ++(int);//post increment
	Fixed operator --(int);

	//Relational Op
	bool operator >(const Fixed& cp) const;
	bool operator <(const Fixed& cp) const;
	bool operator ==(const Fixed& cp) const;
	bool operator >=(const Fixed& cp) const;
	bool operator !=(const Fixed& cp) const;
	bool operator <=(const Fixed& cp) const;

    int getRawBits(void) const; // Getter for retrieving raw value
    void setRawBits(int const raw); // Setter for raw value
    int toInt(void) const; // Function to convert fixed-point num to int
    float toFloat(void) const; // Function to convert fixed-point num to float
	
	//Static Function
	static Fixed& min(Fixed& num1, Fixed& num2);
	static Fixed& max(Fixed& num1, Fixed& num2);
	static const Fixed& min(const Fixed& num1, const Fixed& num2);
	static const Fixed& max(const Fixed& num1, const Fixed& num2);
	//function for output
	friend std::ostream& operator<<(std::ostream& cout, const Fixed& val);
};

#endif