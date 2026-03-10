#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string _name, int _grade_s, int _grade_e) : name(_name), sign(false), grade_s(_grade_s), grade_e(_grade_e) {
	if (this->grade_s < 1 || this->grade_e < 1)
		throw AForm::GradeTooHighException();
	else if (this->grade_s > 150 || this->grade_e > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : name(other.name), sign(other.sign), grade_s(other.grade_s), grade_e(other.grade_e)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->sign = other.sign;
	std::cout << "Form Assignement operator called" << std::endl;
	return (*this);
}

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSigned() const
{
	return (this->sign);
}

int AForm::getGrade_s() const
{
	return (this->grade_s);
}

int AForm::getGrade_e() const
{
	return (this->grade_e);
}

std::ostream& operator<<(std::ostream& os, const AForm &b)
{
	os << "The form " << b.getName() << " is ";
	if (b.getSigned() == true)
		os << "Signed ";
	else
		os << "Unsigned ";
	os << "With a grade required to sign it of : " << b.getGrade_s() << " and a grade required to execute it of " << b.getGrade_e();
	return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High !";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low !";
}

const char* AForm::ExecutionFailedException::what() const throw()
{
	return "Form must be signed or execution grade too low !";
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= this->getGrade_s())
		this->sign = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::signForm(Bureaucrat& b)
{
	try {
		this->beSigned(b);
		if (this->sign == true)
			std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because " << e.what() << std::endl;
	}
}

void AForm::checkExecuted(const Bureaucrat& b) const
{
	if (getSigned() == false || b.getGrade() > grade_e)
		throw AForm::ExecutionFailedException();
}
