/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:13:12 by praclet           #+#    #+#             */
/*   Updated: 2021/04/19 13:30:34 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
#include "Bureaucrat.hpp"

static void _checkGrade(int grade, int refGrade)
{
	if (grade <= 0)
		throw (Form::GradeTooHighException());
	if ((unsigned char)grade > refGrade || grade > 150 )
		throw (Form::GradeTooLowException());
}

void Form::_checkSigningGrade(int grade) const
{
	_checkGrade(grade, _signingGrade);
}

void Form::_checkExecutingGrade(int grade) const
{
	_checkGrade(grade, _executingGrade);
}

Form::Form()
	: _name(""), _signingGrade(1), _executingGrade(1), _isSigned(false)
{
}

Form::Form(std::string const & name, int signingGrade, int executingGrade, std::string const & target)
	: _name(name), _signingGrade(signingGrade), _executingGrade(executingGrade),
	_isSigned(false), _target(target)
{
	_checkSigningGrade(signingGrade);
	_checkExecutingGrade(executingGrade);
}

Form::Form(Form const & src)
	: _name(src._name), _signingGrade(src._signingGrade),
	_executingGrade(src._executingGrade), _isSigned(src._isSigned)
{
}

Form::~Form()
{
}

Form & Form::operator=(Form const & src)
{
	(void)src;
	return (*this);
}

std::string const & Form::getName() const
{
	return (_name);
}

std::string const & Form::getTarget() const
{
	return (_target);
}

int Form::getSigningGrade() const
{
	return (_signingGrade);
}

int Form::getExecutingGrade() const
{
	return (_executingGrade);
}

bool Form::isSigned() const
{
	return (_isSigned);
}

void Form::beSigned(Bureaucrat const & signary)
{
	if (!_isSigned)
	{
		_checkSigningGrade(signary.getGrade());
		_isSigned = true;
	}
}

std::ostream & operator<< (std::ostream & os, Form const & element) 
{
	os << "The ";
	if (element.isSigned())
		os << "signed";
	else
		os << "unsigned";
	os << " form \"" << element.getName() << "\" can be signed by bureaucrats of grade "
		<< element.getSigningGrade() << " at least, it can be executed by bureaucrats of grade "
		<< element.getExecutingGrade() << " and above." << std::endl; 
	return (os);
}

void Form::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw Form::FormNotSignedException();
	_checkExecutingGrade(executor.getGrade());
	_execute(executor);
}

Form::GradeTooHighException::GradeTooHighException()
{
}

const char* Form::GradeTooHighException::what(void) const _NOEXCEPT
{
	return ("Bureaucrat's grade is too high for this form.");
}

Form::GradeTooLowException::GradeTooLowException()
{
}

const char* Form::GradeTooLowException::what(void) const _NOEXCEPT
{
	return ("Bureaucrat's grade is too low for this form.");
}

Form::FormNotSignedException::FormNotSignedException()
{
}

const char* Form::FormNotSignedException::what(void) const _NOEXCEPT
{
	return ("Form is not signed.");
}
