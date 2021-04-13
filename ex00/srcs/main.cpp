/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 08:39:51 by praclet           #+#    #+#             */
/*   Updated: 2021/04/13 12:47:36 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat bob("Bob",50);
		std::cout << bob;
		Bureaucrat bob1(bob);
		std::cout << bob;
		Bureaucrat bob2("tmp",150);
		bob2 = bob;
		std::cout << bob;
	}
	std::cout << "------------" << std::endl;
	{
		Bureaucrat jack("Jack",75);
		std::cout << jack;
		jack.incrementGrade();
		std::cout << jack;
		jack.incrementGrade();
		std::cout << jack;
		jack.incrementGrade();
		std::cout << jack;
		jack.incrementGrade();
		std::cout << jack;
	}
	std::cout << "------------" << std::endl;
	{
		Bureaucrat james("James",75);
		std::cout << james;
		james.decrementGrade();
		std::cout << james;
		james.decrementGrade();
		std::cout << james;
		james.decrementGrade();
		std::cout << james;
		james.decrementGrade();
		std::cout << james;
	}
	std::cout << "------------" << std::endl;
	{
		try
		{
			Bureaucrat toto("Toto",1);
			std::cout << toto;
			toto.incrementGrade();
			std::cout << toto;
		}
		catch (Bureaucrat::GradeTooHighException const & e)
		{
			std::cout << "Ooops! This bureaucrat has a too high grade!" << std::endl;
		}	
		catch (Bureaucrat::GradeTooLowException const & e)
		{
			std::cout << "Ooops! This bureaucrat has a too low grade!" << std::endl;
		}	
	}
	std::cout << "------------" << std::endl;
	{
		try
		{
			Bureaucrat titi("Titi",151);
		}
		catch (Bureaucrat::GradeTooHighException const & e)
		{
			std::cout << "Ooops! This bureaucrat has a too high grade!" << std::endl;
		}	
		catch (Bureaucrat::GradeTooLowException const & e)
		{
			std::cout << "Ooops! This bureaucrat has a too low grade!" << std::endl;
		}	
	}
	return (0);
}
