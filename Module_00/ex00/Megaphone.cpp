/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 03:13:40 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/12 21:22:22 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Megaphone.hpp"
#include <iostream>
using std::cout;

void	str_toupper(char *str)
{
	while (*str)
		std::cout << (char) toupper(*str++);
	std::cout << " ";
}

int main(int c, char **v)
{
	int	i;

	if (c <= 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 0;
	while (v[++i])
		str_toupper(v[i]);
	cout << std::endl;
	return (0);
}
