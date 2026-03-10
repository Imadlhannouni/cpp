#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("shrubbery", 145, 137), target(_target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "Form Assignement operator called" << std::endl;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	checkExecuted(executor);
	std::ofstream outputfile((this->target + "_shrubbery").c_str());
	if (!outputfile)
	{
		throw ShrubberyCreationForm::OpenFailedException();
	}
	else
	{
		outputfile << "       ###\n";
		outputfile << "      #####\n";
		outputfile << "    #########\n";
		outputfile << "   ###\\#|#/###\n";
		outputfile << "    ###\\|/###\n";
		outputfile << "     # }|{ #\n";
		outputfile << "       }|{\n";
	}
	outputfile.close();
}

const char* ShrubberyCreationForm::OpenFailedException::what() const throw()
{
	return "Open file failed";
}
