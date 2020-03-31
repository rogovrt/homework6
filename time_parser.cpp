#include <iostream>
#include <regex>
#include <string>
#include <algorithm>

int main() {
    std::string data = R"(data 2003.04.06 again 1058.12.32 time 09:27:55 again 12:32:45 plus 25:14:40)";
    std::regex pattern_data(R"(([0-2][0-9]{3})\.(0[1-9]|1[0-2])\.(0[1-9]|[1-2][0-9]|3[0-1]))");
    std::regex pattern_time(R"(([0-1][0-9]|2[0-3])(:[0-5][0-9]){2})");
    std::sregex_iterator begin(data.cbegin(), data.cend(), pattern_data);
    std::sregex_iterator end;
    std::cout << "data\n";
    std::for_each(begin, end, [](const std::smatch& m) {
        std::cout << m.str(0) << std::endl;
        });
    std::sregex_iterator begin0(data.cbegin(), data.cend(), pattern_time);
    std::cout << "time\n";
    std::for_each(begin0, end, [](const std::smatch& m) {
        std::cout << m.str(0) << std::endl;
        });
    return 0;
}