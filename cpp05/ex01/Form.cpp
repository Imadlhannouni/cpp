#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string _name, int _grade_s, int _grade_e) : name(_name), sign(false), grade_s(_grade_s), grade_e(_grade_e) {
	if (this->grade_s < 1 || this->grade_e < 1)
		throw Form::GradeTooHighException();
	else if (this->grade_s > 150 || this->grade_e > 150)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSigned() const
{
	return (this->sign);
}

int Form::getGrade_s() const
{
	return (this->grade_s);
}

int Form::getGrade_e() const
{
	return (this->grade_e);
}

std::ostream& operator<<(std::ostream& os, const Form &b)
{
	os << "The form " << b.getName() << " is ";
	if (b.getSigned() == true)
		os << "Signed ";
	else
		os << "Unsigned ";
	os << "With a grade required to sign it of : " << b.getGrade_s() << " and a grade required to execute it of " << b.getGrade_e();
	return os;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade Too High !";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade Too Low !";
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= this->getGrade_s())
		this->sign = true;
	else
		throw Form::GradeTooLowException();
}

void Form::signForm(Bureaucrat& b)
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
