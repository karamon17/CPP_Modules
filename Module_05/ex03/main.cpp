#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
	Intern  someRandomIntern;
	AForm*   rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bob");
	delete rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Alice");
	delete rrf;
	try {
		rrf = someRandomIntern.makeForm("Robotomy requesT", "Wrong");
		delete rrf;
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
    return 0;
}