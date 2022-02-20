#include <numeric>
#include <algorithm>
#include <iostream>
#include <iterator>

#define RANGE(container) std::begin(container), std::end(container)

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector) {
    out << '[';
    std::copy(std::begin(vector), std::prev(std::end(vector)),
              std::ostream_iterator<T>(out, ", "));
    return out << *std::prev(std::end(vector)) << ']';
}

int main() {
//    auto number1 = 45, number2 = 25;
//    auto gcd = std::gcd(number1, number2);
//    auto lcm = std::lcm(number1, number2);
//    std::cout << gcd << ' ' << lcm << ' ' << std::boolalpha
//        << (number1 * number2 == gcd * lcm);

//    std::vector<int> numbers{5, 42, 33, -65, 80};
//    std::for_each(numbers.begin(), numbers.end(), [](auto elem){
//        std::cout << elem << ' ';
//    });
//    std::cout << std::endl;

    std::vector<int> generated_numbers(10);
    std::iota(generated_numbers.begin(), generated_numbers.end(), 8);
//    for(auto item: generated_numbers) {
//        std::cout << item << ' ';
//    }
//    std::cout << std::endl;
//
//    auto sum_of_numbers = std::accumulate(generated_numbers.begin(),
//                                          generated_numbers.end(),
//                                          0);
//    std::cout << sum_of_numbers << std::endl;
//
//
//    auto product_of_numbers = std::accumulate(std::begin(generated_numbers),
//                                              std::end(generated_numbers),
//                                              1ll,
//                                              [](auto lhs, auto rhs){
//        return lhs * rhs;
//    });
//    std::cout << product_of_numbers << std::endl;

    std::vector<int> reversed;
    std::reverse_copy(RANGE(generated_numbers),
                      std::back_inserter(reversed));

    std::cout << reversed << std::endl;

    std::cout << std::inner_product(std::begin(reversed), std::end(reversed),
                       std::begin(generated_numbers), 0)
                       << std::endl;

    std::vector<int> squared;
    std::transform(RANGE(reversed), std::back_inserter(squared),
                   [](auto elem){return elem * elem;});
    std::cout << squared << std::endl;
    std::vector<int> products;
    std::transform(RANGE(squared), std::begin(reversed),
                   std::back_inserter(products),
                   [](auto lhs, auto rhs) {return lhs * rhs;});
    auto dot_product = std::accumulate(RANGE(products), 0);
    std::cout << dot_product << std::endl;



}