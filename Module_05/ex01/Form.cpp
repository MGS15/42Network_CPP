/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:23:30 by sel-kham          #+#    #+#             */
/*   Updated: 2022/10/18 20:58:08 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors and destructors
Form::Form(void) : name("Form"), minExecGrade(1), minSignGrade(1)
{
	this->_isSigned = false;
}

Form::~Form(void) { }

Form::Form(const Form& other) : name(other.name) , minExecGrade(other.minExecGrade), minSignGrade(other.minSignGrade)
{
	this->_isSigned = other.isSigned();
}

// Assignment operator overload
Form& Form::operator=(const Form& other)
{
	Form form = Form(other);

	return (*this);
};

// Insertion operator overload
std::ostream&	Form::operator<<(std::ostream &out)
{
	std::cout << "Form's name					 : " << name << std::endl;
	std::cout << "Form's minimum sign grade		 : " << minExecGrade << std::endl;
	std::cout << "Form's minimum execution grade : " << minExecGrade << std::endl;
	std::cout << "Is the form signed?			 : " << _isSigned << std::endl;
}

// Getters and setters
const str_t& Form::getName(void) const
{
	return (name);
}

bool Form::isSigned(void) const
{
	return (this->_isSigned);
}

const unsigned int& Form::getMinSignGrade(void) const
{
	return (this->minSignGrade);
}

const unsigned int& Form::getMinExecGrade(void) const
{
	return (this->minExecGrade);
}

// Member functions
void	Form::beSigned(Bureaucrat& b)
{
	try
	{
		if (b.getGrade() > 150)
			throw Form::GradeTooLowException();
		else if (b.getGrade() < 1)
			throw Form::GradeTooHighException();
		else
			this->_isSigned = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

// Exeptions Handling
const char*	Form::GradeTooHighException::what(void) const  throw()
{
	return ("\033[0;31mForm can't be signed because the grade is too high!\033[0;37m");
}

const char*	Form::GradeTooLowException::what(void) const  throw()
{
	return ("\033[0;31mForm can't be signed because the grade is too low!\033[0;37m");
}
