#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	try {
		Bureaucrat b("Imad", 2);
		Intern I;
		AForm* rrf;
		rrf = I.makeForm("shrubberw", "home");
		rrf->signForm(b);
		b.executeForm(*rrf);
		delete(rrf);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}