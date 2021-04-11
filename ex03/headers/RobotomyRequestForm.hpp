/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:22:09 by praclet           #+#    #+#             */
/*   Updated: 2021/04/11 17:55:53 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUEST_HPP
# define ROBOTOMYREQUEST_HPP

# include "Form.hpp"
# define RRF_NAME "Robotomy Request"

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
		RobotomyRequestForm();
		virtual void _execute(Bureaucrat const & executor) const;
	public:
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;
};

#endif
