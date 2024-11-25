/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassFixed.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:14:12 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/25 15:28:16 by vodebunm         ###   ########.fr       */
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
    Fixed(const Fixed& copy); // Copy constructor
    Fixed& operator=(const Fixed& copy); // Copy assignment operator
    ~Fixed(); // Destructor
	Fixed(const int integer);//constructor for int
	Fixed(const float floating);//constructor for int

    int getRawBits(void) const; //getter for retrieving raw value
    void setRawBits(int const raw);
	
	int toInt( void ) const; //function to convert  fixed-point num tofloat
	float toFloat( void ) const;//function to convert float
};
std::ostream& operator <<(std::ostream& overload, const Fixed& fixed);

#endif

