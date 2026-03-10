#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string Name, int Grade) : name(Name)
{
	if (Grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (Grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
			this->grade = Grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.grade;
	std::cout << "Bureaucrat Assignement operator called" << std::endl;

	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::IncrementeGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::DecrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low !";
}
