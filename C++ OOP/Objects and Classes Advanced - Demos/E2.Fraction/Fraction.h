#pragma once

class Fraction {
public:
    Fraction(int num, int denom)
        : numerator(num), denominator(denom) {
    }

    int getNumerator() const {
        return this->numerator;
    }

    int getDenominator() const {
        return this->denominator;
    }

    /*bool operator<(const Fraction& other) const {
        return this->numerator * other.denominator
            < other.numerator * this->denominator;
    }*/

    // This is one way with "equals".
    bool equals(const Fraction& other) {
        return numerator* other.getDenominator() == 
               denominator * other.getNumerator();
    }

    // This is other way with operator "==".
    bool operator==(const Fraction& other) const {
        return numerator * other.denominator ==
            denominator * other.numerator;
    }

    bool operator!=(const Fraction& other) const {
        return (*this != other);
        // same
        //return !(*this == other);
    }

    // Postfix operator
    //Fraction operator++(int) const {

    // Prefix operator
    Fraction& operator++() {
        numerator += denominator;
        return *this;
    }

    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
    // This is the one way with a friend.
    //friend std::ostream& operator<<(std::ostream& out, Fraction& fraction);

private:
    int numerator;
    int denominator;
};

bool operator<(const Fraction& left, const Fraction& right) {
    return left.getNumerator() * right.getDenominator()
        < right.getNumerator() * left.getDenominator();
}

bool operator>=(const Fraction& left, const Fraction& right) {
    //return (left >= right);
    // same
    return !(left < right);
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    in >> fraction.numerator >> fraction.denominator;
    return in;
}

//std::ostream& operator<<(std::ostream& out, Fraction& fraction) {
//    out << fraction.numerator << " " << fraction.denominator;
//    return out;
//}

// It's the other way around with getters.
std::ostream& operator<<(std::ostream& out, Fraction& fraction) {
    out << fraction.getNumerator() << " " << fraction.getDenominator();
    return out;
}
