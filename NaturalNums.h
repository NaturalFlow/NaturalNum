#ifndef NATURALNUMS_H_INCLUDED
#define NATURALNUMS_H_INCLUDED

#include <sstream>
#include <string>
#include <random>
#include <vector>
#include <iostream>

class Natural;
class BigNatural;

class Number {
public:
    virtual BigNatural factorial();
    virtual bool is_perfect();
    virtual bool is_perfect_square();
    virtual bool is_palindrome();
    virtual bool is_prime();
    virtual std::string toHex();
    virtual std::string toBin();
    virtual std::string toOct();
};

class BigNatural:Number {
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
    BigNatural mdc(Natural k);
    BigNatural mmc(Natural k);
    BigNatural operator * (BigNatural a);

    friend std::ostream & operator << (std::ostream& out, const BigNatural& object) {
        for(const auto& item : object.num) {
            out << item;
        }
        return out;
    };
    friend std::istream & operator >> (std::istream& in,  BigNatural& object) {
        std::string digits;
        in >> digits;
        for(auto digit : digits) {
            object.num.push_back(digit);
        }
        return in;

    };
};
class Natural:Number {
private:
    unsigned int num;
public:
    Natural(unsigned int num);
    BigNatural factorial();
    bool is_perfect();
    static bool is_perfect(int n);
    bool is_perfect_square();
    static bool is_perfect_square(int n);
    bool is_palindrome();
    static bool is_palindrome(int n);
    bool is_prime();
    static bool is_prime(int n);
    std::string toHex();
    std::string toBin();
    std::string toOct();
    unsigned int mdc(Natural k);
    unsigned int mmc(Natural k);
    void set_num(unsigned int num);
    unsigned int get_num();
};


#endif // NATURALNUMS_H_INCLUDED
