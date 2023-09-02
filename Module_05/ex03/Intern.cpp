#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other){ (void)other; return (*this); }

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &fr, std::string const &name)
{
	AForm	*ret = 0;
	size_t	i = 0;

	std::string ptfr[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (; fr != ptfr[i] && i < 3; i++);
	switch (i)
	{
	case 0:
		ret = new ShrubberyCreationForm(name);
		std::cout << "Intern creates " << name << std::endl;
		break;
	case 1:
		ret = new RobotomyRequestForm(name);
		std::cout << "Intern creates " << name << std::endl;
		break;
	case 2:
		ret = new PresidentialPardonForm(name);
		std::cout << "Intern creates " << name << std::endl;
		break;
	default:
		throw "Error creates! Form does not exist";
		break;
	}
	return (ret);
}