/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:04:44 by sel-kham          #+#    #+#             */
/*   Updated: 2023/03/05 23:43:36 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

# include<iostream>
# include<algorithm>
# include<vector>
# include<deque>
# include<list>

template <typename T>
typename	T::iterator	easyfind(T &c, int i)
{
	typename	T::iterator it;

	it = std::find(c.begin(), c.end(), i);
	if (it != c.end())
		return it;
	throw std::runtime_error("Number not found!");
}

#endif