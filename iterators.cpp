#include <iostream>
#include <set>
#include <map>
#include <vector>

int main() {
    std::vector<int> numbers{25, 655, 7777, 80, 8080, 42, -65, 77, 255};
//    std::set<int, std::greater<>> numbers{25, 655, 7777, 80, 8080, 42, -65, 77, 255};
    for(auto it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    auto end_iterator = numbers.end();
    auto last_iterator = std::prev(end_iterator);
    auto third_iterator = std::next(numbers.begin(), 59999);
    auto distance = std::distance(third_iterator, last_iterator);
    std::cout << *end_iterator << std::endl;
    std::cout << *last_iterator << std::endl;
    std::cout << *third_iterator << std::endl;
    std::cout << distance << std::endl;
}