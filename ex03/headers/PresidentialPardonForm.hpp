/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:19:46 by praclet           #+#    #+#             */
/*   Updated: 2021/04/11 17:53:35 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# define PPF_NAME "Presidential Pardon"

class PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
		PresidentialPardonForm();
		virtual void _execute(Bureaucrat const & executor) const;
	public:
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;
};

#endif
