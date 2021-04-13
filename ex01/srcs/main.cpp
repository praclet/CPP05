/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:56:55 by praclet           #+#    #+#             */
/*   Updated: 2021/04/13 13:28:05 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		Form obj("Basic form",150,150);
		Form obj1(obj);

		std::cout << obj << obj1;
	}
	std::cout << "******** " << __LINE__ << std::endl;
	{
		Form basicForm("Basic Form", 50, 10);
		Form basicForm1(basicForm);
		Form basicForm2(basicForm);
		Bureaucrat johnSmith49("John Smith [49]", 49);
		Bureaucrat johnSmith50("John Smith [50]", 50);
		Bureaucrat johnSmith51("John Smith [51]", 51);

		std::cout << johnSmith49 << basicForm;
		johnSmith49.signForm(basicForm);
		std::cout << basicForm;
		std::cout << "------- " << __LINE__ << std::endl;
		std::cout << johnSmith50 << basicForm1;
		johnSmith50.signForm(basicForm1);
		std::cout << basicForm1;
		std::cout << "------- " << __LINE__ << std::endl;
		std::cout << johnSmith51 << basicForm2;
		johnSmith51.signForm(basicForm2);
		std::cout << basicForm2;
	}
	return (0);
}
