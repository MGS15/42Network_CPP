/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:25:46 by sel-kham          #+#    #+#             */
/*   Updated: 2022/10/01 15:26:25 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>

class	Fixed
{
	public:
		// Constructors and destructors
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();
		// Copy assignment operator overload
		Fixed &operator=(const Fixed &other);
		// Getters and setters
		void	setRawBit(int const raw);
		int		getRawBit(void) const;
	private:
		int					raw;
		static const int	fractions;
};

#endif