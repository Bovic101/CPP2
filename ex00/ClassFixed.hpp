/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassFixed.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:42:26 by vodebunm          #+#    #+#             */
/*   Updated: 2024/11/25 13:30:32 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSFIXED_HPP
#define CLASSFIXED_HPP

#include <iostream>

class Fixed {
private:
    int value; // Fixed-point number
    static const int fraction_part = 8;

public:
    Fixed(); // Default constructor
    Fixed(const Fixed& copy); // Copy constructor
    Fixed& operator=(const Fixed& copy); // Copy assignment operator
    ~Fixed(); // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif