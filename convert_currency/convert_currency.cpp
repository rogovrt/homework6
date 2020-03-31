#include <iostream>
#include <iomanip>

int main() {
    std::istringstream in("1.00USD");
    std::locale in_locale("en_US.UTF_8");
    in.imbue(in_locale);
    long double v;
    in >> std::get_money(v);
    v *= 78;
    std::locale cout_locale("ru_RU.UTF-8");
    std::cout.imbue(cout_locale);
    std::cout << std::showbase << std::put_money(v) << std::endl;
    std::cout << std::showbase << std::put_money(v, true) << std::endl;
    return 0;
}
