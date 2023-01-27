#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
    private:
        std::vector<int> numbers;
        unsigned int N;
        std::vector<int> _numbers;
        unsigned int _N;
    public:
        Span(unsigned int n) : N(n) {}
        void addNumber(int number) {
            if (numbers.size() == N)
                throw std::out_of_range("Span is full, cannot add more numbers");
            numbers.push_back(number);
        }
        int shortestSpan() {
            if (numbers.size() < 2)
                throw std::out_of_range("Cannot find span with less than 2 numbers");
            std::sort(numbers.begin(), numbers.end());
            int shortest = INT_MAX;
            for (unsigned int i = 1; i < numbers.size(); i++) {
                int diff = numbers[i] - numbers[i - 1];
                if (diff < shortest)
                    shortest = diff;
            }
            return shortest;
        }
        int longestSpan() {
            if (numbers.size() < 2)
                throw std::out_of_range("Cannot find span with less than 2 numbers");
            return *std::max_element(numbers.begin(), numbers.end()) - *std::min_element(numbers.begin(), numbers.end());
        }
         template <typename Iter>
        void addNumbers(Iter begin, Iter end) {
            for (auto it = begin; it != end && _numbers.size() < _N; ++it) {
                addNumber(*it);
            }
        }
};

#endif