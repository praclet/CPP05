/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 08:39:51 by praclet           #+#    #+#             */
/*   Updated: 2021/04/19 09:58:56 by praclet          ###   ########lyon.fr   */
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
		std::cout << bob1;
		Bureaucrat bob2("tmp",150);
		bob2 = bob;
		std::cout << bob2;
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
		catch (std::exception const & e)
		{
			std::cout << e.what() << std::endl;
		}	
	}
	std::cout << "------------" << std::endl;
	{
		try
		{
			Bureaucrat titi("Titi",151);
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << std::endl;
		}	
	}
	return (0);
}
