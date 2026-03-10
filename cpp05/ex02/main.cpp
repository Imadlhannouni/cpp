#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	try {
		Bureaucrat b("Imad", 2);
		std::cout << b << std::endl;
		b.DecrementGrade();
		std::cout << b << std::endl;
		ShrubberyCreationForm S("home");
		S.signForm(b);
		b.executeForm(S);
		RobotomyRequestForm R("home");
		R.signForm(b);
		b.executeForm(R);
		b.executeForm(R);
		b.executeForm(R);
		PresidentialPardonForm P("home");
		P.signForm(b);
		b.executeForm(P);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}