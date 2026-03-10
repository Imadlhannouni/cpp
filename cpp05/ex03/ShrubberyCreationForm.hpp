#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private :
		std::string target;
	public :
		void execute(Bureaucrat const &executor) const;
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		class OpenFailedException : public std::exception {
			public :
				const char* what() const throw();
		};
};

#endif