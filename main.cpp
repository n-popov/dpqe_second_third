#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <iterator>
#include <algorithm>


template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector) {
    out << '[';
    std::copy(std::begin(vector), std::prev(std::end(vector)),
              std::ostream_iterator<T>(out, ", "));
    return out << *std::prev(std::end(vector)) << ']';
}


int main() {
    auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
//    auto generator = std::default_random_engine(current_timestamp);
    auto generator = std::mt19937_64(current_timestamp);
    auto distribution = std::uniform_int_distribution(1, 10);
//    for (auto i = 0; i < 10; i++) {
//        std::cout << distribution(generator) << ' ';
//    }
//    std::cout << std::endl;
    std::vector<int> random_numbers;
    std::generate_n(std::back_inserter(random_numbers), 10,
                    [&distribution, &generator](){
        return distribution(generator);
    });
    std::cout << random_numbers << std::endl;

    std::nth_element(std::begin(random_numbers),
                     std::next(std::begin(random_numbers), 2),
                     std::end(random_numbers),
                     std::greater<>());

    std::cout << random_numbers << std::endl;

    auto to_remove = std::remove_if(std::begin(random_numbers),
                                    std::end(random_numbers),
                                    [](auto elem){
        return !(elem % 2);
    });
    std::cout << *to_remove << std::endl;
    random_numbers.erase(to_remove, std::end(random_numbers));
    std::cout << random_numbers << std::endl;



    return 0;
}
