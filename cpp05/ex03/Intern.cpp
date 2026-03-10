#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern Copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern Assignment operator called" << std::endl;
	return (*this);
}

const char* Intern::InexistantFormException::what() const throw()
{
	return "Inexistant form !";
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm *Form = NULL;
	int i = 0;
	std::string names[] = {"shrubbery", "Roboto", "Presidential"};

	while (i < 3)
	{
		if (names[i] == name)
			break ;
		i++;
	}

	switch (i)
	{
		case 0 :
			return Form = new ShrubberyCreationForm(target);
		case 1 :
			return Form = new RobotomyRequestForm(target);
		case 2 :
			return Form = new PresidentialPardonForm(target);
		default :
			throw Intern::InexistantFormException();
	}
	return Form;
}