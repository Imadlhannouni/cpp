#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		std::string getName() const;
		int getGrade() const;
		Bureaucrat(std::string Name, int grade);
		void IncrementeGrade();
		void DecrementGrade();
		void executeForm(AForm const & form);
		Bureaucrat& operator=(const Bureaucrat &other);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &b);

#endif