/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:52:47 by praclet           #+#    #+#             */
/*   Updated: 2021/04/11 14:09:10 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void Bureaucrat::_checkGrade(int grade)
{
	if (grade <= 0)
		throw(new Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw(new Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
	_checkGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	_grade = src._grade;
	return (*this);
}

std::string const & Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	_checkGrade((int)_grade - 1);
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	_checkGrade((int)_grade + 1);
	_grade++;
}

std::ostream & operator << (std::ostream & os, Bureaucrat const & element)
{
	os << element.getName() << ", bureaucrat grade "
		<< element.getGrade() << "." << std::endl;
	return (os);
}

void Bureaucrat::signForm(Form & form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (Form::GradeTooHighException const & e)
	{
		std::cout << "Bureaucrat's rank is too high.";
	}
	catch (Form::GradeTooLowException const & e)
	{
		std::cout << "Bureaucrat's rank is too low.";
	}
}

void Bureaucrat::executeForm(Form const & form) const
{
	try 
	{
		form.execute(*this);
		std::cout << _name << " has executed form '"
			<< form.getName() << "'." << std::endl;
	}
	catch (Form::GradeTooHighException)
	{
		std::cout << _name << " has a too high grade to execute form '"
			<< form.getName() << "'." << std::endl;
	}
	catch (Form::GradeTooLowException)
	{
		std::cout << _name << " has a too low grade to execute form '"
			<< form.getName() << "'." << std::endl;
	}
	catch (Form::FormNotSignedException)
	{
		std::cout << _name << " can't execute unsigned form '"
			<< form.getName() << "'." << std::endl;
	}
}
