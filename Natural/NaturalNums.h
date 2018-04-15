#ifndef NATURALNUMS_H_INCLUDED
#define NATURALNUMS_H_INCLUDED

#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <vector>
#include <iostream>

class BigNatural {
private:
    std::vector<unsigned short> num;
public:
    BigNatural factorial();
    bool is_perfect();
    bool is_perfect_square();
    bool is_palindrome();
    bool is_prime();
    std::string toHex();
    std::string toBin();
    std::string toOct();
    BigNatural mdc(BigNatural k);
    BigNatural mmc(BigNatural k);
    BigNatural operator *(BigNatural a);
    friend std::ostream & operator << (std::ostream& out, const BigNatural& object) {
        for(const auto& item : object.num) {
            out << item;
        }
        return out;
    };
    friend std::istream & operator >> (std::istream& in,  BigNatural& object) {
        std::string digits;
        in >> digits;
        for(auto& digit : digits) {
            object.num.push_back(std::atoi(&digit));
        }
        return in;
    };
};

class Natural {
private:
    unsigned int num;
public:
    Natural(unsigned int num);
    BigNatural factorial();
    bool is_perfect();
    static bool is_perfect(unsigned int n);
    bool is_perfect_square();
    static bool is_perfect_square(unsigned int n);
    bool is_palindrome();
    static bool is_palindrome(unsigned int n);
    bool is_prime();
    static bool is_prime(int n);
    std::string toHex();
    std::string toBin();
    std::string toOct();
    unsigned int mdc(Natural k);
    unsigned int mmc(Natural k);
    bool prime_relative(Natural k);
    void set_num(unsigned int num);
    unsigned int get_num();
};


#endif // NATURALNUMS_H_INCLUDED

