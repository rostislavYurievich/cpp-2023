//вариант 17
#include <cmath>
#include <ostream>
export module Math;



export namespace Math {
    class Complex {
    private: double m_mod;
           double m_arg;

    public:
        Complex(double m_re, double m_im) {
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            if (m_mod< 6.6613381477509392e-15) //evil floating point hacking
                m_mod = 0;
            if ((m_arg > 3.1415926535897)&&(m_arg < 3.1415926535898))
                m_arg = 0;
           
        }

        Complex()
        {
            m_arg = m_mod = 0;
        }

        Complex(double m_mod) {
            this->m_mod = m_mod;
            this->m_arg = 0;
        }

        double Mod() const {
            return m_mod;
        }

        double Arg() const {
            return m_arg;
        }

        double Re() const {
            return m_mod * std::cos(m_arg);
        }

        double Im() const {
            return m_mod * std::sin(m_arg);
        }

        static Complex FromExponentialForm(double m_mod, double m_arg) {
            double m_re = m_mod * std::cos(m_arg);
            double m_im = m_mod * std::sin(m_arg);
            return Complex(m_re, m_im);
        }

        static Complex FromAlgebraicForm(double m_re, double m_im) {
            return Complex(m_re, m_im);
        }

        explicit operator double() {
            return Re();
        }

        Complex operator-() {
            return Complex(-this->Re(), -this->Im());
        }

        Complex& operator++() {
            double m_re = Re() + 1;
            double m_im = Im();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }

        Complex operator++(int) {
            Complex result(*this);
            double m_re = Re() + 1;
            double m_im = Im();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return result;
        }
        Complex& operator--() {
            double m_re = Re() - 1;
            double m_im = Im();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }
        Complex operator--(int) {
            Complex result(*this);
            double m_re = Re() - 1;
            double m_im = Im();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return result;
        }
        Complex& operator+=(Complex complex) {
            double m_re = this->Re() + complex.Re();
            double m_im = this->Im() + complex.Im();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }
        Complex& operator-=(Complex x) {
            double m_re = this->Re() - x.Re();
            double m_im = this->Im() - x.Im();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }
        Complex& operator*= (Complex x)
        {
            double m_re = this->Re() * x.Re() - this->Im() * x.Im();
            double m_im = this->Re() * x.Im() + this->Im() * x.Re();
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }
        Complex& operator/= (Complex x)
        {
            double m_re = (this->Re() * x.Re() + this->Im() * x.Im()) / (x.Re() * x.Re() + x.Im() * x.Im());
            double m_im = (this->Im() * x.Re() - this->Re() * x.Im()) / (x.Re() * x.Re() + x.Im() * x.Im());
            this->m_arg = std::atan2(m_im, m_re);
            this->m_mod = std::sqrt(m_re * m_re + m_im * m_im);
            return *this;
        }

        friend Complex operator+(Complex lhs, Complex rhs);
        friend Complex operator-(Complex lhs, Complex rhs);
        friend Complex operator*(Complex lhs, Complex rhs);
        friend Complex operator/(Complex lhs, Complex rhs);
        friend Complex operator""i(long double Im);
        friend Complex operator""i(unsigned long long Im);
        friend std::ostream& operator<< (std::ostream& os, Complex complex);
    };
    Complex operator+(Complex lhs, Complex rhs)
    {
        double re = lhs.Re() + rhs.Re();
        double im = lhs.Im() + rhs.Im();
        return Complex(re, im);
    }
    Complex operator-(Complex lhs, Complex rhs)
    {
        double re = lhs.Re() -rhs.Re();
        double im = lhs.Im() -rhs.Im();
        
        return Complex(re, im);
    }
    Complex operator*(Complex lhs, Complex rhs)
    {
        double re = lhs.Re() * rhs.Re() - lhs.Im() * rhs.Im();
        double im = lhs.Re() * rhs.Im() + lhs.Im() * rhs.Re();
        return Complex(re, im);
    }
    Complex operator/(Complex lhs, Complex rhs)
    {
        double re = (lhs.Re() * rhs.Re() + lhs.Im() * rhs.Im()) / (rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im());
        double im = (lhs.Im() * rhs.Re() - lhs.Re() * rhs.Im()) / (rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im());
        return Complex(re, im);
    }
    Complex operator""i(long double Im) { return Complex(0, Im); }
    Complex operator""i(unsigned long long Im) { return Complex(0, Im); }
    std::ostream& operator<< (std::ostream& os, Complex complex)
    {
        if (complex.Im() >= 0) {
            return os << complex.Re() << "+" << complex.Im() << "i";
        }
        return os << complex.Re() << complex.Im() << "i";
    }

    int FindGreatestCommonDivisor(int a, int b)
    {
        if (a < b)
        {
            int swap = a;
            a = b;
            b = swap;
        }
        int r;
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return abs(a);
    }
    int FindLeastCommonMultiple(int x, int y) {
        return abs(x * y) / FindGreatestCommonDivisor(x, y);
    }

    class Rational
    {

    public:
        void fun()
        {


            int nod = FindGreatestCommonDivisor(m_nominator, m_denominator);
            m_nominator = m_nominator / nod;
            m_denominator = m_denominator / nod;
            if (m_denominator < 0)
            {
                m_nominator = -m_nominator;
                m_denominator = -m_denominator;
            }
        }
        Rational() { m_nominator = 0; m_denominator = 1; }
        Rational(int x, int y)
        {
            m_nominator = x;
            m_denominator = y;
            this->fun();
        }
        Rational(int x) { m_nominator = x; m_denominator = 1; }

        int Nominator() const { return m_nominator; }
        int Denominator() const { return m_denominator; }
        explicit  operator double() {
            return ((double)Nominator() / Denominator());
        }
        Rational operator- () { return Rational(-this->m_nominator, this->m_denominator); }
        Rational& operator++ ()
        {
            this->m_nominator += m_denominator;
            this->fun(); return *this;
        }
        Rational operator++ (int x) {
            Rational star = *this;
            m_nominator += m_denominator;
            this->fun();
            return star;
        }
        Rational& operator-- () { this->m_nominator -= m_denominator; this->fun(); return *this; }
        Rational operator-- (int x) { Rational star = *this; m_nominator -= m_denominator; this->fun(); return star; }
        Rational& operator+= (Rational x)
        {
            int no = m_nominator * x.m_denominator + m_denominator * x.m_nominator;
            int de = m_denominator * x.m_denominator;
            m_nominator = no;
            m_denominator = de;
            fun();
            return *this;
        }
        Rational& operator-= (Rational x)
        {
            int no = m_nominator * x.m_denominator - m_denominator * x.m_nominator;
            int de = m_denominator * x.m_denominator;
            m_nominator = no;
            m_denominator = de;
            fun();
            return *this;
        }
        Rational& operator*= (Rational x)
        {
            int no = m_nominator * x.m_nominator;
            int de = m_denominator * x.m_denominator;
            m_nominator = no;
            m_denominator = de;
            fun();
            return *this;
        }
        Rational& operator/= (Rational x)
        {
            int no = m_nominator * x.m_denominator;
            int de = m_denominator * x.m_nominator;
            m_nominator = no;
            m_denominator = de;
            fun();
            return *this;
        }
        friend Rational operator+ (Rational lhs, Rational rhs);
        friend Rational operator- (Rational lhs, Rational rhs);
        friend Rational operator* (Rational lhs, Rational rhs);
        friend Rational operator/ (Rational lhs, Rational rhs);
        friend bool operator== (Rational lhs, Rational rhs);
        friend bool operator<(Rational lhs, Rational rhs);
        friend bool operator>(Rational lhs, Rational rhs);
        friend bool operator<=(Rational lhs, Rational rhs);
        friend bool operator<=(Rational lhs, Rational rhs);

        friend std::ostream& operator<< (std::ostream& os, const Rational& rational);
    private:
        int m_nominator;
        int m_denominator;
    };
    Rational operator+ (Rational lhs, Rational rhs)
    {
        int no = lhs.m_nominator * rhs.m_denominator + lhs.m_denominator * rhs.m_nominator;
        int de = lhs.m_denominator * rhs.m_denominator;
        Rational now = Rational(no, de);
        now.fun();
        return now;
    }
    Rational operator- (Rational lhs, Rational rhs)
    {
        int no = lhs.m_nominator * rhs.m_denominator - lhs.m_denominator * rhs.m_nominator;
        int de = lhs.m_denominator * rhs.m_denominator;
        Rational now = Rational(no, de);
        now.fun();
        return now;
    }
    Rational operator* (Rational lhs, Rational rhs)
    {
        int no = lhs.m_nominator * rhs.m_nominator;
        int de = lhs.m_denominator * rhs.m_denominator;
        Rational now = Rational(no, de);
        now.fun();
        return now;
    }
    Rational operator/ (Rational lhs, Rational rhs)
    {
        int no = lhs.m_nominator * rhs.m_denominator;
        int de = lhs.m_denominator * rhs.m_nominator;
        Rational now = Rational(no, de);
        now.fun();
        return now;
    }
    bool operator== (Rational lhs, Rational rhs)
    {
        if (lhs.m_nominator == rhs.m_nominator && lhs.m_denominator == rhs.m_denominator)
            return true;
        else
            return false;
    }

    bool operator< (Rational lhs, Rational rhs)
    {
        return (double)lhs < (double)rhs;
    }
    bool operator> (Rational lhs, Rational rhs)
    {
        return (double)lhs > (double)rhs;
    }
    bool operator>= (Rational lhs, Rational rhs)
    {
        return (double)lhs >= (double)rhs;
    }

    bool operator<= (Rational lhs, Rational rhs)
    {
        return (double)lhs <= (double)rhs;
    }


    std::ostream& operator<< (std::ostream& os, const Rational& rational)
    {
        return os << rational.m_nominator << "/" << rational.m_denominator;
    }


    Complex cosine(Complex x) {
        return Complex(std::cos(x.Re()) * std::cosh(x.Im()), -std::sin(x.Re()) * std::sinh(x.Im()));
    }

    Complex f(const Complex& z) {
        Complex a = 1 + 0i;
        return a * z * z - cosine(2 * z);
    }

    Rational cosine(Rational x) {
        return std::cos((double)x);
    }

    Rational f(const Rational& r) {
        Rational a = 1 / 1;
        return a * r * r - cosine(2 * r);
    }

    double f(double x) {
        double a = 1.0;
        return a * x * x - std::cos(2 * x);
    }


}
