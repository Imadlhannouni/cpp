#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <stdexcept>

class AForm;

class Intern {
	public:
		AForm* makeForm(std::string name, std::string target);
		Intern(const Intern &other);
		Intern();
		~Intern();
		Intern& operator=(const Intern &other);
		class InexistantFormException : public std::exception {
			public :
				const char* what() const throw();
		};
};

#endif