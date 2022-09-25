/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:21:39 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/25 02:31:21 by sel-kham         ###   ########.fr       */
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
		str_t	getType(void) const;
		void	setType(const str_t type);
	private:
		str_t	type;
};

#endif