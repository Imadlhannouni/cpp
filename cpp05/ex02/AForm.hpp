#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
	private :
		const std::string name;
		bool sign;
		const int grade_s;
		const int grade_e;
	protected :
		void checkExecuted(const Bureaucrat& b) const;
	public :
		AForm(std::string _name, int _grade_s, int _grade_e);
		std::string getName() const;
		bool getSigned() const;
		int getGrade_s() const;
		int getGrade_e() const;
		void beSigned(Bureaucrat& b);
		void signForm(Bureaucrat& b);
		virtual void execute(Bureaucrat const &executor) const = 0;
		AForm& operator=(const AForm &other);
		AForm(const AForm &other);
		virtual ~AForm();
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				const char* what() const throw();
		};
		class ExecutionFailedException : public std::exception {
			public :
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm &b);

#endif