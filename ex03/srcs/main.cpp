/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:18:53 by praclet           #+#    #+#             */
/*   Updated: 2021/04/13 14:38:56 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		Intern obj;
		Intern obj1(obj);
		Intern obj2;

		obj2 = obj;
	}
	std::cout << "******** " << __LINE__ << std::endl;
	{
		Intern bob;
		PresidentialPardonForm *ptr1;
		RobotomyRequestForm *ptr2;
		ShrubberyCreationForm *ptr3;

		ptr1 = (PresidentialPardonForm*) bob.makeForm(PPF_NAME, "Samuel II Croonie");
		ptr2 = (RobotomyRequestForm*)bob.makeForm(RRF_NAME, "GHY 5900");
		ptr3 = (ShrubberyCreationForm*)bob.makeForm(SCF_NAME, "home");
		std::cout << *ptr1 << *ptr2 << *ptr3;
		delete ptr1;
		delete ptr2;
		delete ptr3;
	}
	return (0);
}
