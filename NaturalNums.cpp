#include "NaturalNums.h"

Natural::Natural(unsigned int num) {
    this->num = num;
}
BigNatural factorial() {

}
bool Natural::is_perfect(int n) {
    unsigned int soma;
    if(n & 1 == 0)
        return false;
    for(unsigned int i = 0; i < n; i++) {
        if(n % i == 0) {
            soma += i;
        }
    }
    return soma == n;
}
bool Natural::is_perfect() {
    unsigned int soma;
    if(num & 1 == 0)
        return false;
    for(unsigned int i = 0; i < num; i++) {
        if(num % i == 0) {
            soma += i;
        }
    }
    return soma == num;

// Since was proved by Euclides that if (2^p)-1 is prime therefore 2^(p-1)*(2^p)-1 is perfect
/* So I'm looking for Mersenne primes
    if(num & 1 == 0)
        return false;
    else {

    }
    return true;
    */
}
bool Natural::is_perfect_square(int n) {
    unsigned short lastDigit = n %10;
    if(lastDigit == 2 || lastDigit == 3 || lastDigit == 7 || lastDigit == 8)
        return false;
    for(unsigned int i = 0; i*i < n; i++) {
        if(i*i == n) {
            return true;
        }
    }
    return false;
}
bool Natural::is_perfect_square() {
    unsigned short lastDigit = num % 10;
    if(lastDigit == 2 || lastDigit == 3 || lastDigit == 7 || lastDigit == 8)
        return false;
    for(unsigned int i = 0; i*i < num; i++) {
        if(i*i == num) {
            return true;
        }
    }
    return false;
}
bool Natural::is_palindrome(int n) {
    std::stringstream ss;
    ss << n;
    std::string numStr = ss.str();

    for(unsigned int i = 0; i < numStr.size()/2; i++) {
        if(numStr[i] != numStr[numStr.size()-i-1]) {
            return false;
        }
    }
    return true;
}
bool Natural::is_palindrome() {
    std::stringstream ss;
    ss << num;
    std::string numStr = ss.str();

    for(unsigned int i = 0; i < numStr.size()/2; i++) {
        if(numStr[i] != numStr[numStr.size()-i-1]) {
            return false;
        }
    }
    return true;
}
bool Natural::is_prime() {
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num & 1 || num % 3 == 0)
        return false;
    for (int i = 5; i*i <= num; i = i+6) //any prime must be the form of 6n+1
        if (num%i == 0 || num%(i+2) == 0)
           return false;
    return true;
// I believe in Riemann ...
/* Jim Sinclair 7 prime base
    EM CONSTRUÇAO MILLER RABIN
    const primesBase[] = {2, 325, 9375, 28178, 450775, 9780504,1795265022};
    for(unsigned int i = 0 ; i < 7; i++) {
        if(num % primesBase[i] == 0)
            return num == p[i];
    }
    int powMod = [](int x, unsigned int y, int prime) {
        int res = 1;
        x = x % p;
        while (y > 0) {
            if (y & 1) res = (res*x) % p;
            y = y >> 1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    }
*/
}
std::string Natural::toHex() {
    std::string hexBaseChars = "0123456789ABCDEF";
    std::string hex = "";
    unsigned int index;
    while(num >= 1) {
        index = num%16;
        hex.insert(hex.begin(),hexBaseChars[index]);
        num /= 16;
    }
    return hex;
}
std::string Natural::toBin() {
    std::string bin;
    while (num >= 1) {
        if (num % 2 == 0)
            bin.insert(bin.begin(), 0);
        else
            bin.insert(bin.begin(), 1);
       num = num/2;
    }
    return bin;
}
std::string Natural::toOct() {
}
unsigned int Natural::mdc(Natural k) {

}
unsigned int Natural::mmc(Natural k) {

}
void Natural::set_num(unsigned int num) {
    this->num = num;
}
unsigned int Natural::get_num() {
    return num;
}
