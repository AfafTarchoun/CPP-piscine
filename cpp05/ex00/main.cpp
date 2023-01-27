#include "Bureaucrat.hpp"
int main()
{
    try {
        Bureaucrat b("John", 0);
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        // handle exception
    }
    return 0;
}
/*#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("John", 0); // should throw Bureaucrat::GradeTooHighException
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat b2("Jane", 160); // should throw Bureaucrat::GradeTooLowException
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat b3("Bob", 1); // should not throw an exception
        std::cout << b3 << std::endl; // should print: "Bob, bureaucrat grade 1."
        b3.incrementGrade(); // should throw Bureaucrat::GradeTooHighException
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat b4("Bill", 150); // should not throw an exception
        std::cout << b4 << std::endl; // should print: "Bill, bureaucrat grade 150."
        b4.decrementGrade(); // should throw Bureaucrat::GradeTooLowException
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat b5("Sara", 10); // should not throw an exception
        std::cout << b5 << std::endl; // should print: "Sara, bureaucrat grade 10."
        b5.incrementGrade();
        std::cout << b5 << std::endl; // should print: "Sara, bureaucrat grade 9."
        b5.decrementGrade();
        std::cout << b5 << std::endl; // should print: "Sara, bureaucrat grade 10."
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
*/