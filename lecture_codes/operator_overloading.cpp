//operator overloading

#include <iostream>

class Fraction1 {
private:
    int numerator;
    int denominator;

public:
    Fraction1(int n, int d) : numerator(n), denominator(d) {}

    Fraction1 operator+(const Fraction1& other) const {
        int n = numerator * other.denominator + other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction1(n, d);
    }

    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

class Fraction2{

private:
    int numerator;
    int denominator;

public:
    Fraction2(int n, int d) : numerator(n), denominator(d) {}

    friend Fraction2 operator+(const Fraction2& f1, const Fraction2& f2) {
        int n = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
        int d = f1.denominator * f2.denominator;
        return Fraction2(n, d);
    }

    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};



int main() {
    Fraction1 f1(1, 2);
    Fraction1 f2(1, 3);

    Fraction1 result1 = f1 + f2; 

    result1.print();
    
    Fraction2 f11(1, 2);
    Fraction2 f22(1, 3);

    Fraction2 result2 = f11 + f22; 

    result2.print();

    return 0;
}
