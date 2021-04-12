/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:13:09 by praclet           #+#    #+#             */
/*   Updated: 2021/04/12 10:19:29 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const & src)
{
	(void)src;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(Intern const &)
{
	return (*this);
}

Form * Intern::makeForm(std::string const & formName, std::string const & targetName)
{
	std::size_t	const nbForms = 3;
	std::string const formNames[nbForms] = {PPF_NAME, RRF_NAME, SCF_NAME};
	Form * (*formCreators[nbForms])(std::string const &) =
		{ &Intern::_createPPF, &Intern::_createRRF, &Intern::_createSCF};

	for (std::size_t i = 0;i < nbForms;i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << "." << std::endl;
			return (formCreators[i](targetName));
		}
	}
	std::cout << "Intern can't create " << formName << "." << std::endl;
	return (NULL);
}

Form * Intern::_createPPF(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

Form * Intern::_createRRF(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

Form * Intern::_createSCF(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}
