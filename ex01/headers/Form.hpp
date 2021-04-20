/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:13:14 by praclet           #+#    #+#             */
/*   Updated: 2021/04/19 12:43:45 by praclet          ###   ########lyon.fr   */
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
	protected:
		void _checkSigningGrade(int grade) const;
		void _checkExecutingGrade(int grade) const;
		Form();
		Form & operator=(Form const & src);
	public:
		Form(std::string const & name, int signingGrade, int executingGrade);
		Form(Form const & src);
		virtual ~Form();
		std::string const & getName() const;
		int getSigningGrade() const;
		int getExecutingGrade() const;
		bool isSigned() const;
		void beSigned(Bureaucrat const & signatory);
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
};

std::ostream & operator << (std::ostream & os, Form const & element); 

#endif
