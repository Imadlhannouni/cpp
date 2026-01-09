#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b("Imad", 150);
		std::cout << b << std::endl;
		b.DecrementGrade();
		std::cout << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}