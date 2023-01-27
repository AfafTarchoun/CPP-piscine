#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <exceptions>
class Form
{
    private:
        const std::string name;
        bool signed;
        const int grade_to_sign;
        const int grade_to_execute;

    public:
        Form(const std::string& name, int grade_to_sign, int grade_to_execute);
        Form(const Form& other);
        ~Form();

        std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat& bureaucrat);
        friend std::ostream& operator<<(std::ostream& os, const Form& form);
};

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form& form);
        friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
};

#endif