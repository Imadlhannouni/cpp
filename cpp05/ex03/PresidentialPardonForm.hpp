#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	public :
		void execute(Bureaucrat const &executor) const;
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();
	private:
		std::string target;
};

#endif