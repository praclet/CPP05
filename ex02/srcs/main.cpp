/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:34:31 by praclet           #+#    #+#             */
/*   Updated: 2021/04/14 09:22:46 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "stdlib.h"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat bob("Big Cat",1);
	Bureaucrat bobby("Small Cat",150);

	srand(time(NULL));
	{
		ShrubberyCreationForm obj("home");
		ShrubberyCreationForm obj1(obj);

		std::cout << obj << obj1;
		bob.executeForm(obj);
		bob.signForm(obj);
		bobby.executeForm(obj);
		bob.executeForm(obj);
	}
	std::cout << "******** " << __LINE__ << std::endl;
	{
		PresidentialPardonForm obj("Samuel III Croonie");
		PresidentialPardonForm obj1(obj);

		std::cout << obj << obj1;
		bob.executeForm(obj);
		bob.signForm(obj);
		bobby.executeForm(obj);
		bob.executeForm(obj);
	}
	std::cout << "******** " << __LINE__ << std::endl;
	{
		RobotomyRequestForm obj("WXF 3000");
		RobotomyRequestForm obj1(obj);

		std::cout << obj << obj1;
		bob.executeForm(obj);
		bob.signForm(obj);
		bobby.executeForm(obj);
		bob.executeForm(obj);
	}
	return (0);
}
