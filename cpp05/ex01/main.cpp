#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat b("Imad", 12);
		std::cout << b << std::endl;
		b.DecrementGrade();
		std::cout << b << std::endl;
		Form f("f1", 14, 11);
		std::cout << f << std::endl;
		f.signForm(b);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}