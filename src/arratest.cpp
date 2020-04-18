#include "arraconv.h"
#include <iostream>

int main()
{
    auto roman = toRoman(0);
    std::cout << "Wynik: " << roman << '\n';
    roman = toRoman(4000);
    std::cout << "Wynik: " << roman << '\n';
    roman = toRoman(993);
    std::cout << "Wynik: " << roman << '\n';
    
    auto arabic = fromRoman("XYZ");
    std::cout << "Wynik: " << arabic << '\n';
    arabic = fromRoman(roman);
    std::cout << "Wynik: " << arabic << '\n';
}