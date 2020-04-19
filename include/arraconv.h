#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

const std::vector<std::pair<short, std::string>> arabic_roman {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"}, 
    {90, "XC"}, 
    {50, "L"}, 
    {40, "XL"}, 
    {10, "X"}, 
    {9, "IX"}, 
    {5, "V"}, 
    {4, "IV"}, 
    {1, "I"}
};

const std::vector<char> roman_signs {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

std::string toRoman(short arabic)
{
    std::string roman = "";

    if (arabic > 0 && arabic < 4000)
    {
        for(auto& p : arabic_roman)
        {
            while (arabic >= p.first)
            {
                roman += p.second;
                arabic -= p.first;
            }
        }
    }
    else
    {
        std::cout << "Błąd! Dane wejściowe poza zakresem (" << arabic << ").\n";
    }
    
    return roman;
}

bool isRomanSignValid(std::string roman)
{
    return std::all_of(roman.begin(),
                        roman.end(),
                        [](auto &rn){ return std::any_of(roman_signs.begin(),
                                                            roman_signs.end(),
                                                            [rn](auto &rs){ return rs == rn; }); });
}

short fromRoman(std::string roman)
{
    short arabic = 0;

    if (isRomanSignValid(roman))
    {
        short arabic_roman_idx = 0;
        short last_arabic_checked = 4000; // Sztucznie nadana wartość początkowa

        for(std::string::iterator roman_iter = roman.begin(); roman_iter != roman.end();)
        {
            if (arabic_roman_idx >= arabic_roman.size())
            {
                std::cout << "Błąd! Zła kolejność znaków (" << roman << ").\n";
                
                return 0;
            }
            auto roman_numeral = arabic_roman[arabic_roman_idx].second;
            short arabic_to_add = 0;
            while(std::equal(roman_iter, roman_iter + roman_numeral.size(), roman_numeral.begin()))
            {
                arabic_to_add += arabic_roman[arabic_roman_idx].first;
                roman_iter = roman_iter + roman_numeral.size();
            }
            if (arabic_to_add >= last_arabic_checked)
            {
                std::cout << "Błąd! Zbyt wiele znaków obok siebie (" << roman << ").\n";
                
                return 0;
            }
            arabic += arabic_to_add;
            last_arabic_checked = arabic_roman[arabic_roman_idx].first;
            arabic_roman_idx++;
        }

        if (toRoman(arabic) != roman)
        {
            std::cout << "Błąd! Walidacja liczby nieudana (" << roman << ").\n";
            
            return 0;
        }
    }
    else
    {
        std::cout << "Błąd! Nieprawidłowe znaki na wejściu (" << roman << ").\n";
    }

    return arabic;
}