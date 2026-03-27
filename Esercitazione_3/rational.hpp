#include <iostream>
#include <numeric>
#include <concepts>

template<typename I> 
requires std::integral<I>
class rational {
    I num_;
    I den_;
    bool is_nan_ = false;
    bool is_inf_ = false;

    void semplificazione() {
        if (is_nan_ || is_inf_) return;

        if (num_ == 0) {
            den_ = 1;
            return;
        }

        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }

        I comune_divisore = std::gcd(num_, den_);
        num_ /= comune_divisore;
        den_ /= comune_divisore;
    }

public:
    // Costruttore di default
    rational() : num_(0), den_(1), is_nan_(false), is_inf_(false) {}

    // Costruttore a due argomenti
    rational(I n, I d) : num_(n), den_(d) {
        if (d == 0) {
            if (n == 0) {
                is_nan_ = true; is_inf_ = false;
            } else {
                is_nan_ = false; is_inf_ = true;
            }
        } else {
            is_nan_ = false; is_inf_ = false;
            semplificazione();
        }
    }

    I num() const { return num_; }
    I den() const { return den_; }
    bool is_nan() const { return is_nan_; }
    bool is_inf() const { return is_inf_; }

    // Incremento
    rational& operator+=(const rational& other) {
        if (is_nan_ || other.is_nan_) {
            is_nan_ = true; is_inf_ = false;
        } else if (is_inf_ || other.is_inf_) {
            is_inf_ = true;
        } else {
            num_ = num_ * other.den_ + other.num_ * den_;
            den_ *= other.den_;
            semplificazione();
        }
        return *this;
    }

    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }

    // Decremento
    rational& operator-=(const rational& other) {
        if (is_nan_ || other.is_nan_) {
            is_nan_ = true; is_inf_ = false;
        } else if (is_inf_ || other.is_inf_) {
            is_inf_ = true;
        } else {
            num_ = num_ * other.den_ - other.num_ * den_;
            den_ *= other.den_;
            semplificazione();
        }
        return *this;
    }

    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }

    // Prodotto per SCALARE
    rational& operator*=(const I& s) {
        if (is_nan_) return *this;
        if (is_inf_) {
            if (s == 0) { is_nan_ = true; is_inf_ = false; }
            return *this;
        }
        num_ *= s;
        semplificazione();
        return *this;
    }

    // Prodotto tra RAZIONALI
    rational& operator*=(const rational& other) {
        if (is_nan_ || other.is_nan_) {
            is_nan_ = true; is_inf_ = false;
        } else if (is_inf_ || other.is_inf_) {
            if ((is_inf_ && other.num_ == 0) || (other.is_inf_ && num_ == 0)) {
                is_nan_ = true; is_inf_ = false;
            } else {
                is_inf_ = true;
            }
        } else {
            num_ *= other.num_;
            den_ *= other.den_;
            semplificazione();
        }
        return *this;
    }

    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }

    // Divisione tra RAZIONALI
    rational& operator/=(const rational& other) {
        if (is_nan_ || other.is_nan_) {
            is_nan_ = true; is_inf_ = false;
        } else if (other.num_ == 0) { // Dividere per zero
            if (num_ == 0) is_nan_ = true;
            else is_inf_ = true;
        } else if (is_inf_) {
            is_inf_ = true;
        } else {
            num_ *= other.den_;
            den_ *= other.num_;
            semplificazione();
        }
        return *this;
    }

    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }

    // Stampa (definita come friend dentro la classe è più semplice)
    friend std::ostream& operator<<(std::ostream& os, const rational& r) {
        if (r.is_nan_) os << "NaN";
        else if (r.is_inf_) os << "Inf";
        else os << r.num_ << "/" << r.den_;
        return os;
    }
};