#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Roboto", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "Form Assignement operator called" << std::endl;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	this->checkExecuted(executor);
	std::cout << "Bzzzz... Vrrrrr... (drilling noises)" << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy on " << this->target << " failed." << std::endl;
}
