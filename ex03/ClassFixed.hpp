/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassFixed.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:46:29 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/27 11:07:06 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSFIXED_HPP
#define CLASSFIXED_HPP

#include <iostream>
#include <cmath>
#include <iomanip>

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

    // Arithmetic operators
    Fixed operator +(const Fixed& cp) const;
    Fixed operator *(const Fixed& cp) const;
    Fixed operator -(const Fixed& cp) const;
    Fixed operator /(const Fixed& cp) const;

    // Unary operators
    Fixed& operator ++();
    Fixed& operator --();  // Pre-decrement
    Fixed operator ++(int); // Post-increment
    Fixed operator --(int); 

    // Relational operators
    bool operator >(const Fixed& cp) const;
    bool operator <(const Fixed& cp) const;
    bool operator ==(const Fixed& cp) const;
    bool operator >=(const Fixed& cp) const;
    bool operator !=(const Fixed& cp) const;
    bool operator <=(const Fixed& cp) const;

    int getRawBits(void) const;
    void setRawBits(int const raw); 
    int toInt(void) const; // Convert fixed-point to int
    float toFloat(void) const; // Convert fixed-point to float

    // Static functions
    static Fixed& min(Fixed& num1, Fixed& num2);
    static Fixed& max(Fixed& num1, Fixed& num2);
    static const Fixed& min(const Fixed& num1, const Fixed& num2);
    static const Fixed& max(const Fixed& num1, const Fixed& num2);

    // Function for output
    friend std::ostream& operator<<(std::ostream& out, const Fixed& val);
};

#endif


