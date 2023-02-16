
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : target("Target")
{
    std::cout << "ShrubberyCreationForm Default Constructor Called\n";
    if(this->getSGrade() > 145 || this->getEGrade() > 137)
        throw(GradeTooLowException());
    drawTree(this->target);
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name, const int sign_grade, const int execute_grade) : Form(name, sign_grade, execute_grade)
{
    this->target = "EEEEEEE_";
    std::cout << "ShrubberyCreationForm Paramitrized Constructor Called\n";
    if(this->getSGrade() > 145 || this->getEGrade() > 137)
        throw(GradeTooLowException());
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
    drawTree(this->target);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : target(target)
{
    if(this->getSGrade() > 145 || this->getEGrade() > 137)
        throw(GradeTooLowException());
    drawTree(this->target);
    // std::cout << getTarget() << "has been pardoned by Zaphod Beeblebrox\n";// here
}

void ShrubberyCreationForm::drawTree(std::string target)
{
    std::cout << this->target << std::endl;
    std::ofstream file (target + "_Shrubbery");
    file << "             _{\\ _{\\{\\/}/}/}__\n";
    file << "            {/{/\\}{/{/\\}(\\}{/\\} _\n";
    file << "          {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n";
    file << "        {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n";
    file << "       {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n";
    file << "      _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n";
    file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n";
    file << "       _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n";
    file << "       {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n";
    file << "       {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n";
    file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n";
    file << "        {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n";
    file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n";
    file << "        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n";
    file << "        (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n";
    file << "         {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n";
    file << "          {/{\\{\\{\\/}/}{\\{\\}/}\n";
    file << "           {){/ {\\/}{\\/} \\}\\}\n";
    file << "            {){/ {\\/}{\\/} \\}\\}\n";
    file << "              (_)  \\.-'.-/\n";
    file << "         __...--- |'-.-'| --...__\n";
    file << "   _...--   .-'   |'-.-'|  ' -.  \"--..__\n";
    file << "      ' .  . '    |.'-._| '  . .  '   ___\n";
    file << "   '-  '    .--'  | '-.'|    .  '  . '\n";
    file << "         ' ..     |'-_.-|\n";
    file << " .  '  .       _.-|-._ -|-._  . \n";

    
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Deastuctor Called\n";
}

void    ShrubberyCreationForm::setTarget(std::string T)
{
    this->target = T;
}

std::string ShrubberyCreationForm::getTarget(void) const 
{
    return (this->target);
}
