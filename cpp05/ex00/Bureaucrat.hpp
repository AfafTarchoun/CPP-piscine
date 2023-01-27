#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>

class Bureaucrat
{
public:
    class GradeTooHighException {};
    class GradeTooLowException {};
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

private:
    std::string _name;
    int _grade;
};

#endif