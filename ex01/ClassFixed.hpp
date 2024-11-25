/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassFixed.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:14:12 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/25 16:33:50 by vodebunm         ###   ########.fr       */
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

    int getRawBits(void) const; // Getter for retrieving raw value
    void setRawBits(int const raw); // Setter for raw value

    int toInt(void) const; // Function to convert fixed-point num to int
    float toFloat(void) const; // Function to convert fixed-point num to float
};

// Overload operator
std::ostream& operator<<(std::ostream& out, const Fixed& val);

#endif

