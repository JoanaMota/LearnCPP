#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>

class CComplex
{
private:
    double m_real;
    double m_imaginary;

public:
    ///@brief Default Constructor
    CComplex();
    ///@brief Parameterized Constructor
    CComplex(double f_real, double f_imaginary);
    ///@brief Copy Constructor
    CComplex(const CComplex &f_other);
    ///@brief Assignment Operator
    const CComplex &operator=(const CComplex &f_other);
    bool operator==(const CComplex &other) const;
    bool operator!=(const CComplex &other) const;
    ~CComplex();

    double getReal() const { return m_real; }
    double getImaginary() const { return m_imaginary; }
};

CComplex::CComplex() : m_real(0), m_imaginary(0)
{
    std::cout << "Default Constructor" << std::endl;
}
CComplex::CComplex(double f_real, double f_imaginary)
    : m_real(f_real), m_imaginary(f_imaginary)
{
    std::cout << "Parameterized Constructor" << std::endl;
}

CComplex::CComplex(const CComplex &f_other)
{
    std::cout << "Copy Constructor" << std::endl;
    m_real = f_other.m_real;
    m_imaginary = f_other.m_imaginary;
}

const CComplex &CComplex::operator=(const CComplex &f_other)
{
    std::cout << "Assignment Operator" << std::endl;
    m_real = f_other.m_real;
    m_imaginary = f_other.m_imaginary;
    return *this;
}

CComplex::~CComplex()
{
}

bool CComplex::operator==(const CComplex &other) const
{
    return (m_real == other.m_real) && (m_imaginary == other.m_imaginary);
}
bool CComplex::operator!=(const CComplex &other) const
{
    return !(*this == other);
}
//
std::ostream &operator<<(std::ostream &out, const CComplex &c)
{
    out << "(" << c.getReal() << "," << c.getImaginary() << ")";
    return out;
}
CComplex operator+(const CComplex &c1, const CComplex &c2)
{
    return CComplex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}
CComplex operator+(const CComplex &c1, double d)
{
    return CComplex(c1.getReal() + d, c1.getImaginary());
}
CComplex operator+(double d, const CComplex &c1)
{
    return CComplex(c1.getReal() + d, c1.getImaginary());
}
#endif /* COMPLEX_HPP */