/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassFixed.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:46:29 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/30 07:37:05 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSFIXED_HPP
#define CLASSFIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int value;
    static const int fraction_part = 8;

public:
    Fixed();                             // Default constructor
    Fixed(const int integer);            // Constructor for int
    Fixed(const float floating);         // Constructor for float
    Fixed(const Fixed& copy);            // Copy constructor
    Fixed& operator=(const Fixed& copy); // Copy assignment operator
    ~Fixed();                            // Destructor

    // Getters and converters
    int getRawBits() const;
    void setRawBits(int const raw);
    int toInt() const;
    float toFloat() const;

    // Unary Operators
    Fixed& operator++();    // Pre-increment
    Fixed operator++(int);  // Post-increment
    Fixed& operator--();    // Pre-decrement
    Fixed operator--(int);  // Post-decrement

    // Relational Operators
    bool operator>(const Fixed& cp) const;
    bool operator<(const Fixed& cp) const;
    bool operator>=(const Fixed& cp) const;
    bool operator<=(const Fixed& cp) const;
    bool operator==(const Fixed& cp) const;
    bool operator!=(const Fixed& cp) const;

    // Arithmetic Operators
    Fixed operator+(const Fixed& cp) const;
    Fixed operator-(const Fixed& cp) const;
    Fixed operator*(const Fixed& cp) const;
    Fixed operator/(const Fixed& cp) const;

    // Static Functions
    static Fixed& min(Fixed& num1, Fixed& num2);
    static Fixed& max(Fixed& num1, Fixed& num2);
    static const Fixed& min(const Fixed& num1, const Fixed& num2);
    static const Fixed& max(const Fixed& num1, const Fixed& num2);
};

// Overloaded << operator
std::ostream& operator<<(std::ostream& out, const Fixed& val);

#endif



