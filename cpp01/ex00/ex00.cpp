/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:48:56 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/16 15:26:29 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string name) : name(name) {}
        ~Zombie()
        {
            std::cout << name << " is destroyed" << std::endl;
        }
        void announce()
        {
            std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
        }
};

Zombie* newZombie(std::string name)
{
    return new Zombie(name);
}

void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}
int main()
{
    Zombie* heapZombies = newZombie("Heap Zombie");
    heapZombies->announce();
    delete heapZombies;

    randomChump("Stack Zombie");
    return 0;
}
/*The purpose of the exercise is to learn about memory allocation in C++,
 specifically the difference between allocating an object on the stack and on the heap. 
 The Zombie class has been implemented with a private attribute name and a member function announce() 
 which prints the name of the zombie followed by "BraiiiiiiinnnzzzZ...".
Two functions have been provided, newZombie( std::string name ) which creates and returns a new zombie with the given name,
 and randomChump( std::string name ) which creates a new zombies with the given name and announces itself.
 The destructor of the class should be implemented to print a message with the name of the zombie for debugging purposes.
  When the zombies is no longer needed, it should be destroyed.
It's better to allocate the zombies on heap if the object needs to be created dynamically 
and the lifetime of the object exceeds the lifetime of the block scope where it was created.Otherwise, stack allocation is sufficient.*/

/*You can see that the newZombie function creates a new Zombie object on the heap, assigns it to a pointer, and returns it.
The lifetime of this object will be until it's deleted by calling delete on the pointer.
The randomChump function creates a Zombie object on the stack, and its lifetime is only for the duration of the function call.
Also in the destructor you can print the message with the name of the zombies for debugging purposes*/