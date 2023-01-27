#include "span.hpp"
/*In the constructor, I would initialize the max_size variable with the value of N, and initialize the count to 0.

The addNumber() function would first check if the count is less than max_size, and if it is, it would add the number to the numbers array and increment the count. If the count is already at max_size, it would throw an exception.

The shortestSpan() and longestSpan() functions would first check if the count is less than 2, and if it is, they would throw an exception. If the count is 2 or more, they would iterate through the numbers array, comparing the difference between each pair of numbers, keeping track of the smallest and largest difference respectively.
Finally, both function would return the smallest and largest difference.

To test the Span class, I would create an instance of the class, add a large number of integers to it, and then call the shortestSpan() and longestSpan() functions to check the results. I would also test the class with different number of numbers, including edge cases like adding numbers to the class when it is already full and calling the shortestSpan() and longestSpan() functions when the class is empty.

*/
#include <iostream>
#include <random>

int main() {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    return 0;
}

/*In this example, we first create an instance of the Span class with a maximum of 5 integers.
Then we add 5 integers to it using the addNumber function.
Finally, we call the shortestSpan and longestSpan functions and print the results.
If any exception is thrown by the Span class
 it will be caught and the error message will be printed.*/
