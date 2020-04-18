#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

const std::vector<std::pair<int, std::string>> arabic_roman {
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

std::string toRoman(unsigned int arabic)
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
        std::cout << "Błąd! Nieprawidłowe dane wejściowe (" << arabic << ").\n";
    }
    
    return roman;
}

bool isRomanValid(std::string roman)
{
    return std::all_of(roman.begin(),
                        roman.end(),
                        [](auto &rn){ return std::any_of(roman_signs.begin(),
                                                            roman_signs.end(),
                                                            [rn](auto &rs){ return rs == rn; }); });
}

int fromRoman(std::string roman)
{
    int arabic = 0;

    if (isRomanValid(roman))
    {
        std::string::iterator roman_iter = roman.begin();

        for (auto& p : arabic_roman)
        {
            auto roman_numeral = p.second;
            while(std::equal(roman_iter, roman_iter + roman_numeral.size(), roman_numeral.begin()))
            {
                arabic += p.first;
                roman_iter = roman_iter + roman_numeral.size();
            }
        }
    }
    else
    {
        std::cout << "Błąd! Nieprawidłowe dane wejściowe (" << roman << ").\n";
    }    
    
    return arabic;
}