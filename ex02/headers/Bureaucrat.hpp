/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:06 by praclet           #+#    #+#             */
/*   Updated: 2021/04/11 10:21:11 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	protected:
		std::string const _name;
		unsigned char _grade;
		static void _checkGrade(int grade);
		Bureaucrat();
	public:
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const & src);
		std::string const & getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form & form) const;
		class GradeTooHighException : public std::exception
		{
		};	
		class GradeTooLowException : public std::exception
		{
		};	
};

std::ostream & operator << (std::ostream & os, Bureaucrat const & element); 

#endif
