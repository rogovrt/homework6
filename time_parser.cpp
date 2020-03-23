#include <iostream>
#include <regex>
#include <string>
#include <algorithm>

int main() {
    std::string data = "data 2003.4.6 "
        "again 2099.12.31 "
        "time 09:2:55 "
        "again 12:32:45 ";
    std::regex pattern_data(R"([12][09][0-9]{2}.1?[0-9].[123]?[0-9])");
    std::regex pattern_time(R"([012]?[0-9]:[0-5]?[0-9]:[0-5][0-9])");
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
    system("pause");
    return 0;
}