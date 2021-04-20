/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:13:14 by praclet           #+#    #+#             */
/*   Updated: 2021/04/19 13:01:41 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		unsigned char const _signingGrade;
		unsigned char const _executingGrade;
		bool _isSigned;
		std::string const _target;
		virtual void _execute(Bureaucrat const & executor) const = 0;
	protected:
		Form & operator=(Form const & src);
		void _checkSigningGrade(int grade) const;
		void _checkExecutingGrade(int grade) const;
		Form();
	public:
		Form(std::string const & name, int signingGrade, int executingGrade, 
				std::string const & target);
		Form(Form const & src);
		virtual ~Form();
		std::string const & getName() const;
		std::string const & getTarget() const;
		int getSigningGrade() const;
		int getExecutingGrade() const;
		bool isSigned() const;
		void beSigned(Bureaucrat const & signary);
		void execute(Bureaucrat const & executor) const;
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				virtual const char* what(void) const _NOEXCEPT;
		};	
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				virtual const char* what(void) const _NOEXCEPT;
		};	
		class FormNotSignedException : public std::exception
		{
			public:
				FormNotSignedException();
				virtual const char* what(void) const _NOEXCEPT;
		};	
};

std::ostream & operator << (std::ostream & os, Form const & element); 

#endif
