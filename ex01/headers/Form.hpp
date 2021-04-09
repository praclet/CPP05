/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:13:14 by praclet           #+#    #+#             */
/*   Updated: 2021/04/09 15:00:40 by praclet          ###   ########lyon.fr   */
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
	public:
		Form(std::string const & name, int signingGrade, int executingGrade);
		Form(Form const & src);
		~Form();
		Form & operator=(Form const & src);
		std::string const & getName() const;
		int getSigningGrade() const;
		int getExecutingGrade() const;
		bool isSigned() const;
		void beSigned(Bureaucrat const & signary);
		class GradeTooHighException : public std::exception
		{
		};	
		class GradeTooLowException : public std::exception
		{
		};	
};

std::ostream & operator << (std::ostream & os, Form const & element); 

#endif
