/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:13:10 by praclet           #+#    #+#             */
/*   Updated: 2021/04/12 10:23:44 by praclet          ###   ########lyon.fr   */
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
		static Form * _createPPF(std::string const & target);
		static Form * _createRRF(std::string const & target);
		static Form * _createSCF(std::string const & target);
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();
		Intern & operator=(Intern const &);
		Form * makeForm(std::string const & formName, std::string const & targetName);
};

#endif
