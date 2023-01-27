#include "span.hpp"

template <typename InputIterator>
void Span::addNumbers(InputIterator first, InputIterator last) {
    for (auto it = first; it != last; it++) {
        addNumber(*it);
    }
}
/*This function takes two iterators as input, 
and it iterates from the first iterator to the last one,
adding each element to the Span by calling the addNumber() function.*/

/*int main() {
    Span<int> sp = Span<int>(5);
    int arr[] = {6, 3, 17, 9, 11};
    sp.addNumbers(arr, arr + sizeof(arr) / sizeof(int));
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
*/