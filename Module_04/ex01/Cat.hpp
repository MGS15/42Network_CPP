/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 05:21:35 by sel-kham          #+#    #+#             */
/*   Updated: 2022/10/16 18:38:30 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CAT_HPP__
# define __CAT_HPP__

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

typedef std::string	str_t;

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		// Constructors and destructors
		Cat(void);
		~Cat(void);
		Cat(const Cat& other);
		// Assignment operator overload
		Cat& operator=(const Cat& other);
        // Public member functions
		void	makeSound(void) const;
};

#endif