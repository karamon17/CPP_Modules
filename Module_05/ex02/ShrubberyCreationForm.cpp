#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	if (this == &copy)
		return *this;
	AForm::operator=(copy);
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > AForm::getGradeToExecute())
		throw GradeTooLowException();
	else if (getSigned() == "false")
		throw FormNotSignedException();
	std::ofstream outputFile(getTarget() + "_shrubbery");
	outputFile << "                      ___" << std::endl;
    outputFile << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
    outputFile << "             ,-'          __,,-- \\" << std::endl;
    outputFile << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
    outputFile << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    outputFile << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    outputFile << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    outputFile << "     (     ,-'                  `." << std::endl;
    outputFile << "      `._,'     _   _             ;" << std::endl;
    outputFile << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    outputFile << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    outputFile << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    outputFile << "                \"Hb HH dF" << std::endl;
    outputFile << "                 \"HbHHdF" << std::endl;
    outputFile << "                  |HHHF" << std::endl;
    outputFile << "                  |HHH|" << std::endl;
    outputFile << "                  |HHH|" << std::endl;
    outputFile << "                  |HHH|" << std::endl;
    outputFile << "                  |HHH|" << std::endl;
    outputFile << "                  dHHHb" << std::endl;
    outputFile << "                .dFd|bHb.               o" << std::endl;
    outputFile << "      o       .dHFdH|HbTHb.          o /" << std::endl;
    outputFile << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    outputFile << "##########################################" << std::endl;
    outputFile.close();
}


