/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:30:40 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/16 15:30:40 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

class Harl
{
    private:
        void debug()
        {
            std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
        }
        void info()
        {
            std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
        }
        void warning()
        {
            std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
        }
        void error()
        {
            std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
        }

    public:
        void complain(std::string level)
        {
            void (Harl::*complainFunctions[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
            std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

            for (int i = 0; i < 4; i++)
            {
                if (level == levels[i])
                {
                    (this->*complainFunctions[i])();
                    break;
                }
            }
        }
};

int main()
{
    Harl harl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    return 0;
}