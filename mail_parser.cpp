#include <iostream>
#include <regex>
#include <string>
#include <algorithm>

int main() {
    std::string data =  ".apdaNvalid@gmail.com one more "  
                        "lo.pp.pl@lol.su trash " //correct
                        "hello@world.edu some text " //correct
                        "tru|e@ma-il.ru JJ " //correct
                        "ex@-unwork.org";
    std::regex pattern (R"(\s[^.]([[:alnum:]!#$%&'*+-/=?^_`{|}~]+[.]?)*[^.]@([^-][[:alnum:]-]+.[[:alnum:]-]+[^-]))");
    //�������: ����� �����, �����, �������; �������� � ����������� �� ������, ������ �� ����� ����� � ����
    //�����: �����, �����, - (�� � ����� � �� � ������)
    std::sregex_iterator begin(data.cbegin(), data.cend(), pattern);
    std::sregex_iterator end;
    std::for_each(begin, end, [](const std::smatch& m) {
        std::cout << m.str(2) << std::endl;
        });
    system("pause");
    return 0;
}