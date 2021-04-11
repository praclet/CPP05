/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:34:39 by praclet           #+#    #+#             */
/*   Updated: 2021/04/11 17:53:56 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	return (PresidentialPardonForm &)Form::operator=(src);
}

PresidentialPardonForm::PresidentialPardonForm() : Form()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form(src)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: Form(PPF_NAME, 25, 5, target)
{
}

void PresidentialPardonForm::_execute(Bureaucrat const & executor) const
{
	(void) executor;
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox."
		<< std::endl;
}
