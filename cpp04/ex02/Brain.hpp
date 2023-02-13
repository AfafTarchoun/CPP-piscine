
#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "Animal.hpp"

class Brain
{
    protected :
        std::string ideas[100];
    public :
        Brain();
        Brain(std::string ideas);
        Brain(Brain & B);
        Brain & operator=(Brain const & B);
        ~Brain();
        std::string    getIdeas(int n) const ;
        void            setIdeas(std::string idea, int n);
        
};

 #endif