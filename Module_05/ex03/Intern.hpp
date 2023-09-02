#ifndef INRERN_HPP
# define INRERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &copy);
		Intern &operator=(Intern const &copy);
		~Intern();

		AForm *makeForm(std::string const &formName, std::string const &target);
};

#endif