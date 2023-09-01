#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form"), _gradeToSign(150), _gradeToExecute(150)
{
	_signed = false;
}

Form::Form(std::string const &name, int gradeSign) : _name(name), _gradeToSign(gradeSign), _gradeToExecute(0)
{
	if (gradeSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150)
		throw Form::GradeTooLowException();
	else
		this->_signed = false;
}

Form::Form(std::string const &name, int gradeSign, int gradeExec) : _name(name), _gradeToSign(gradeSign), _gradeToExecute(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	else
		this->_signed = false;
}

Form::Form(Form const &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
}

Form::~Form()
{
}

Form &Form::operator=(Form const &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::string const &Form::getName() const
{
	return (this->_name);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

std::string Form::getSigned() const
{
	return _signed ? "true" : "false";
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ", form signed " << form.getSigned();
	return (out);
}
