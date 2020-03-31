#include <iostream>
#include <regex>
#include <string>
#include <algorithm>

int main() {
    std::string data =  R"(.apdaNvalid@gmail.com one more lo.pp.pl@lol.su trash hello@world.edu some text tru|e@ma-il.ru JJ ex@-unwork.org)";
    //correct cout : lol.su world.edu ma-il.ru
    std::regex pattern(R"(\s[^\.]([[:alnum:]!#$%&'*+-/=?^_`{|}~]+[\.]?)+[^\.]@([^-][[:alnum:]-]+(\.[[:alnum:]-]*)[^-]))");
    std::sregex_iterator begin(data.cbegin(), data.cend(), pattern);
    std::sregex_iterator end;
    std::for_each(begin, end, [](const std::smatch& m) {
        std::cout << m.str(2) << std::endl;
        });
    return 0;
}
