/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 08:37:45 by msabr             #+#    #+#             */
/*   Updated: 2025/09/22 19:32:09 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int rawBits;
		static const int fractionalBits;
	public:
		Fixed(); // Default constructor
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed &other); // Copy constructor
		Fixed &operator=(const Fixed &other); // Copy assignment operator
		~Fixed(); // Destructor

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
