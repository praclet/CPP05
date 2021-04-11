/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:57:34 by praclet           #+#    #+#             */
/*   Updated: 2021/04/11 17:56:36 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	return (ShrubberyCreationForm &)Form::operator=(src);
}

ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: Form(SCF_NAME, 145, 137, target)
{
}

void ShrubberyCreationForm::_execute(Bureaucrat const & executor) const
{
	std::ofstream result(getTarget() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);

	(void) executor;
	result << "             * *" << std::endl;
 	result << "          *    *  *" << std::endl;
 	result << "     *  *    *     *  *" << std::endl;
 	result << "    *     *    *  *    *" << std::endl;
 	result << "* *   *    *    *    *   *" << std::endl;
 	result << "*     *  *    * * .#  *   *" << std::endl;
 	result << "*   *     * #.  .# *   *" << std::endl;
 	result << " *     \"#.  #: #\" * *    *" << std::endl;
 	result << "*   * * \"#. ##\"       *" << std::endl;
 	result << "  *       \"###" << std::endl;
 	result << "            \"##" << std::endl;
 	result << "             ##." << std::endl;
 	result << "             .##:" << std::endl;
 	result << "             :###" << std::endl;
 	result << "             ;###" << std::endl;
 	result << "           ,####." << std::endl;
	result << "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\" << std::endl;
	result << std::endl;
	result.close();
	std::cout << getTarget() << " shrubbery has been created." << std::endl;
}
