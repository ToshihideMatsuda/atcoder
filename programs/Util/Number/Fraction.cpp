
template <typename T>
T gcd_calc(T a, T b) {
  T c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}

template <typename T = int64_t>
class Fraction {
 private:
  // 0 is always represented with "+0 / 1"
  bool m_sign;
  T m_numer;
  T m_denom;

  Fraction(bool sign, T numerator, T denominator)
      : m_sign(sign), m_numer(numerator), m_denom(denominator) {}

  void reduce() {
    auto gcd = gcd_calc(m_numer, m_denom);
    m_numer /= gcd;
    m_denom /= gcd;
  }

 public:
  T numerator() const { return m_numer; }
  T denominator() const { return m_denom; }
  T sign() const { return m_sign ? -1 : 1; }
  bool is_zero() const { return m_numer == 0; }
  bool is_positive() const { return !is_zero() && !is_negative(); }
  bool is_negative() const { return m_sign; }

  Fraction() : Fraction(static_cast<T>(0)) {}

  Fraction(T numerator, T denominator = 1)
      : m_sign(numerator != 0l && ((numerator > 0l) != (denominator > 0l))),
        m_numer(numerator < 0l ? -numerator : numerator),
        m_denom(denominator < 0l ? -denominator : denominator) {
    if (denominator == 0l) {
      throw std::runtime_error("denominator must not be 0.");
    }
    if (m_numer == 0l) {
      m_denom = 1;
    }
    reduce();
  }

  Fraction inv() const { return Fraction(m_sign, m_denom, m_numer); }

  friend Fraction operator-(const Fraction &frac) {
    if (frac.numerator() == static_cast<T>(0)) {
      return frac;
    }
    return Fraction(!frac.m_sign, frac.numerator(), frac.denominator());
  }

  friend Fraction operator+(const Fraction &lhs, const Fraction &rhs) {
    if (lhs == static_cast<T>(0)) {
      return rhs;
    }
    if (rhs == static_cast<T>(0)) {
      return lhs;
    }
    auto gcd = gcd_calc(lhs.denominator(), rhs.denominator());
    auto denom = lhs.denominator() / gcd * rhs.denominator();
    auto numer = lhs.sign() * lhs.numerator() * (denom / lhs.denominator()) +
                 rhs.sign() * rhs.numerator() * (denom / rhs.denominator());
    return Fraction(numer, denom);
  }

  friend Fraction operator-(const Fraction &lhs, const Fraction &rhs) {
    if (lhs == static_cast<T>(0)) {
      return -rhs;
    }
    if (rhs == static_cast<T>(0)) {
      return lhs;
    }
    auto gcd = gcd_calc(lhs.denominator(), rhs.denominator());
    auto denom = lhs.denominator() / gcd * rhs.denominator();
    auto numer = lhs.sign() * lhs.numerator() * (denom / lhs.denominator()) -
                 rhs.sign() * rhs.numerator() * (denom / rhs.denominator());
    return Fraction(numer, denom);
  }

  friend Fraction operator*(const Fraction &lhs, const Fraction &rhs) {
    if (lhs == static_cast<T>(0) || rhs == static_cast<T>(0)) {
      return static_cast<T>(0);
    }
    auto gcd1 = gcd_calc(lhs.numerator(), rhs.denominator());
    auto gcd2 = gcd_calc(lhs.denominator(), rhs.numerator());
    auto numer = (lhs.numerator() / gcd1) * (rhs.numerator() / gcd2);
    auto denom = (lhs.denominator() / gcd2) * (rhs.denominator() / gcd1);
    return Fraction(lhs.m_sign != rhs.m_sign, numer, denom);
  }

  friend Fraction operator/(const Fraction &lhs, const Fraction &rhs) {
    if (rhs == static_cast<T>(0)) {
      throw std::runtime_error("Fraction::operator/ : devision by zero.");
    }
    if (lhs == static_cast<T>(0)) {
      return static_cast<T>(0);
    }
    return lhs * rhs.inv();
  }

  Fraction &operator+=(const Fraction &other) {
    *this = *this + other;
    return *this;
  }

  Fraction &operator-=(const Fraction &other) {
    *this = *this - other;
    return *this;
  }

  Fraction &operator*=(const Fraction &other) {
    *this = *this * other;
    return *this;
  }

  Fraction &operator/=(const Fraction &other) {
    *this = *this / other;
    return *this;
  }

  friend bool operator==(const Fraction &lhs, const Fraction &rhs) {
    return lhs.numerator() == rhs.numerator() &&
           lhs.denominator() == rhs.denominator() && lhs.sign() == rhs.sign();
  }

  friend bool operator!=(const Fraction &lhs, const Fraction &rhs) {
    return !(lhs == rhs);
  }

  friend bool operator<(const Fraction &lhs, const Fraction &rhs) {
    if (lhs.is_negative() && rhs.is_positive()) {
      return true;
    }
    if (lhs.is_positive() && rhs.is_negative()) {
      return false;
    }
    return lhs.sign() * lhs.numerator() * rhs.denominator() <
           lhs.sign() * lhs.denominator() * rhs.numerator();
  }

  friend bool operator>(const Fraction &lhs, const Fraction &rhs) {
    if (lhs.is_negative() && rhs.is_positive()) {
      return false;
    }
    if (lhs.is_positive() && rhs.is_negative()) {
      return true;
    }
    return lhs.sign() * lhs.numerator() * rhs.denominator() >
           lhs.sign() * lhs.denominator() * rhs.numerator();
  }

  friend bool operator<=(const Fraction &lhs, const Fraction &rhs) {
    return lhs == rhs || lhs < rhs;
  }

  friend bool operator>=(const Fraction &lhs, const Fraction &rhs) {
    return lhs == rhs || lhs > rhs;
  }

  friend std::ostream &operator<<(std::ostream &os, const Fraction &rhs) {
    if (rhs.denominator() == 1 || rhs.numerator() == 0) {
      os << rhs.numerator();
    } else {
      if (rhs.is_negative()) {
        os << "-";
      }
      os << rhs.numerator() << " / " << rhs.denominator();
    }
    return os;
  }
};

