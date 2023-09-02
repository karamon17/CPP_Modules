#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
	private:
		std::string const	_name;
		std::string 		_target;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	
	public:
		AForm();
		AForm(std::string const &name, int gradeSign);
		AForm(std::string const &name, int gradeSign, int gradeExec);
		AForm(AForm const &copy);
		virtual ~AForm();
		virtual AForm &operator=(AForm const &copy);
		virtual std::string const &getTarget() const;
		virtual void setTarget(std::string const &target);
		virtual std::string const	&getName() const;
		virtual std::string 		getSigned() const;
		virtual int					getGradeToSign() const;
		virtual int					getGradeToExecute() const;
		virtual void				beSigned(Bureaucrat const &bureaucrat);
		virtual void 				execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &Aform);

#endif