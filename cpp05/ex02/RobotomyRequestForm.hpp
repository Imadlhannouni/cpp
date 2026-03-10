#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	public :
		void execute(Bureaucrat const &executor) const;
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
	private:
		std::string target;
};

#endif