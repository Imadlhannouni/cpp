#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "Form Assignement operator called" << std::endl;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	this->checkExecuted(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}