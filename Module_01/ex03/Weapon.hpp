/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:21:39 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/25 03:11:59 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <iostream>
typedef std::string	str_t;

class	Weapon
{
	public:
		// Constructors and destructors
		Weapon(void);
		Weapon(const str_t type);
		Weapon& operator=(const Weapon& weapon);
		// Class methods
		str_t	getType(void) const;
		void	setType(const str_t type);
	private:
		str_t	type;
};

#endif