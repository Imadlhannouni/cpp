#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private :
		const std::string name;
		bool sign;
		const int grade_s;
		const int grade_e;
	public :
		Form(std::string _name, int _grade_s, int _grade_e);
		std::string getName() const;
		bool getSigned() const;
		int getGrade_s() const;
		int getGrade_e() const;
		void beSigned(Bureaucrat& b);
		void signForm(Bureaucrat& b);
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public :
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const Form &b);

#endif