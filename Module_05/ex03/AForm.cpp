#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm"), _gradeToSign(150), _gradeToExecute(150)
{
	_signed = false;
}

AForm::AForm(std::string const &name, int gradeSign) : _name(name), _gradeToSign(gradeSign), _gradeToExecute(0)
{
	if (gradeSign < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150)
		throw AForm::GradeTooLowException();
	else
		this->_signed = false;
}

AForm::AForm(std::string const &name, int gradeSign, int gradeExec) : _name(name), _gradeToSign(gradeSign), _gradeToExecute(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
	else
		this->_signed = false;
}

AForm::AForm(AForm const &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::string const &AForm::getName() const
{
	return (this->_name);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

std::string AForm::getSigned() const
{
	return _signed ? "true" : "false";
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::string const &AForm::getTarget() const
{
	return _target;
}

void AForm::setTarget(const std::string &target)
{
	_target = target;
}

std::ostream &operator<<(std::ostream &out, AForm const &Aform)
{
	out << Aform.getName() << ", Aform grade to sign " << Aform.getGradeToSign() << ", Aform grade to execute " << Aform.getGradeToExecute() << ", Aform signed " << Aform.getSigned();
	return (out);
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}