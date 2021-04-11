/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:42:53 by praclet           #+#    #+#             */
/*   Updated: 2021/04/11 17:56:06 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	return (RobotomyRequestForm &)Form::operator=(src);
}

RobotomyRequestForm::RobotomyRequestForm() : Form()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form(src)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: Form(RRF_NAME, 72, 45, target)
{
}

void RobotomyRequestForm::_execute(Bureaucrat const & executor) const
{
	(void) executor;
	std::cout << "DRILL, DRILL" << std::endl; 
	std::cout << getTarget();
	if (rand() % 2)
		std::cout << " has been robotomized successfully.";
	else
		std::cout << " has not been robotomized successfully.";
	std::cout << std::endl;
}
