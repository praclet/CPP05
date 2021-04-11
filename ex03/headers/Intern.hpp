/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:13:10 by praclet           #+#    #+#             */
/*   Updated: 2021/04/11 18:22:27 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		struct _FormGenerator
		{
			std::string const name;
			Form * (*formCreator)(std::string const &);
		};
		static Form * createPPF(std::string const & formName);
		static Form * createRRF(std::string const & formName);
		static Form * createSCF(std::string const & formName);
		static std::size_t const _nbForms = 3;
		static _FormGenerator const _tabForms[_nbForms] =
		{
			{PPF_NAME, Intern::createPPF},
			{RRF_NAME, &createRRF},
			{SCF_NAME, &createSCF}
		};
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();
		Intern & operator=(Intern const &);
		Form * makeForm(std::string const & formName, std::string const & targetName);
};

#endif

		/*
		 * The intern has one important thing, the makeForm function. It takes two strings, the
first representing the name of a form, and the second one being the target for the form. It
will return, as a pointer to Form, a pointer to whichever concrete form class is represented
by the first parameter, initialized with the second parameter. It will print something like
"Intern creates <form>" to the standard output. If it’s using a worse method, like
if/elseif/elseif/else branchings, or some other ugly stuff like this, it will not be accepted
during the evaluation. If the requested form is not known, print an explicit error message.


*/
