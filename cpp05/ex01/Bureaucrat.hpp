#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

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
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public :
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &b);

#endif