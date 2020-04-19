#include "arraconv.h"
#include <iostream>

int main()
{
    // Za mała liczba
    auto roman = toRoman(0);
    std::cout << "Wynik: " << roman << "\n\n";
    // Za duża liczba
    roman = toRoman(4000);
    std::cout << "Wynik: " << roman << "\n\n";

    roman = toRoman(1984);
    std::cout << "Wynik: " << roman << "\n\n";
    
    auto arabic = fromRoman(roman);
    std::cout << "Wynik: " << arabic << "\n\n";
    // Znaki nie są znakami rzymskimi
    arabic = fromRoman("XYZ");
    std::cout << "Wynik: " << arabic << "\n\n";
    // 4 takie same znaki
    arabic = fromRoman("VV");
    std::cout << "Wynik: " << arabic << "\n\n";
    // Znaki w nieprawidłowej kolejności
    arabic = fromRoman("XVID");
    std::cout << "Wynik: " << arabic << "\n\n";
    // Znaki w kolejności malejącej, lecz nieprawidłowy zapis liczby
    arabic = fromRoman("CMD");
    std::cout << "Wynik: " << arabic << "\n";
}