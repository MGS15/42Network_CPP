/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:04:36 by sel-kham          #+#    #+#             */
/*   Updated: 2022/10/24 03:55:07 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

// Constructors and destructors
Converter::Converter(void)
{
	this->setInput("");
}

Converter::Converter(str_t input)
{
	this->setInput(input);
}

Converter::~Converter(void) { }

Converter::Converter(const Converter& converter)
{
	this->input = converter.input;
}

// Assignment operator overload
Converter& Converter::operator=(const Converter& converter)
{
	this->input = converter.input;
	return (*this);
}

// Getters and setters
str_t	Converter::getInput(void) const
{
    return (this->input);
}

void    Converter::setInput(str_t input)
{
	if (input == "")
		throw Converter::InvalidInputExeption();
	this->input = input;
}

// Member functions
static bool	isSign(int c)
{
	return (c == '-' || c == '+');
}

bool	Converter::isPseudo(void) const
{
	return (this->input == "nan" || this->input == "+inf" || this->input == "-inf" || this->input == "inf" || this->input == "nanf");
}

bool	Converter::isChar(void) const
{
	return (this->input.length() == 1 && this->input[0] >= 0 && this->input[0] <= 127);
}

bool	Converter::isInt(void) const
{
	int	i;

	i = -1;
	while (this->input[++i])
	{
		if (i == 0 && isSign(this->input[i]))
			i++;
		if (!isdigit(this->input[i]))
			return (false);
	}
	return (true);
}

bool	Converter::isDouble(void) const
{
	int		i;
	bool	dPoint;
	
	i = -1;
	dPoint = false;
	while (++i < (int) this->input.size())
	{
		if (i == 0 && isSign(this->input[i]))
			continue ;
		if (!dPoint && this->input[i] == '.')
		{
			dPoint = true;
			continue ;
		}
		if (dPoint && this->input[i] == '.')
			return (false);
		if (!isdigit(this->input[i]))
			return (false);
	}
	if (!isdigit(this->input[i - 1]) || !dPoint)
		return (false);
	return (true);
}

bool	Converter::isFloat(void) const
{
	str_t	tmp;
	bool	res;

	tmp = this->input;
	tmp = tmp.substr(0, this->input.length() - 1);
	res = (this->isDouble() && tmp[this->input.length() - 1] == 'f');
	return (res);
}

bool	Converter::isValid(void) const
{
	return (this->isChar() || this->isInt() || this->isFloat() || this->isDouble() || this->isPseudo());
}

void	Converter::printChar(void) const
{
	char	toPrint;

	toPrint = static_cast<char> (std::strtof(this->input.c_str(), NULL));
	std::cout << "char	: ";
	if (isprint(toPrint))
		std::cout <<  toPrint << std::endl;
	else
		std::cout <<  "Non-printable" << std::endl;
		
}

void	Converter::printInt(void) const
{
	int	toPrint;

	toPrint = static_cast<int> (std::atoi(this->input.c_str()));;
	std::cout << "int	: " << toPrint << std::endl;
}

void	Converter::printFloat(void) const
{
	float	toPrint;

	toPrint = static_cast<float> (std::strtof(this->input.c_str(), NULL));
	std::cout << "float	: " << toPrint << ((toPrint == static_cast<float> (toPrint)) ? "f" : ".0f" ) << std::endl;
}

void	Converter::printDouble(void) const
{
	double	toPrint;

	toPrint = static_cast<double> (std::strtof(this->input.c_str(), NULL));
	std::cout << "double	: " << toPrint << (toPrint == static_cast<double> (toPrint) ? "" : ".0") << std::endl;
}

void    Converter::printResults(void) const
{
	if (!this->isValid())
		throw Converter::InvalidInputExeption();
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

// Exeptions handling
const char* Converter::InvalidInputExeption::what(void) const throw()
{
	return ("\n\t\033[0;31mERROR\033[0;37m: \033[0;33mInvalid input!\033[0;31m\n");
}
