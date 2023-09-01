#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
        Bureaucrat bureaucrat("ash", 12);
        Form form("formName", 15);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	return 0;
}
