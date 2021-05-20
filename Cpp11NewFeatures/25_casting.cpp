#include <iostream>

class CParent
{
public:
    virtual void speak()
    {
        std::cout << "Parent" << std::endl;
    }
};
class CBrother : public CParent
{
};
class CSister : public CParent
{
};

int main()
{

    float value = 3.23;
    std::cout << (int)value << std::endl;
    std::cout << int(value) << std::endl;
    std::cout << static_cast<int>(value) << std::endl;

    CParent parent;
    CBrother brother;

    CParent *pParent = &brother;
    // CBrother *pBrother = &parent; // error: invalid conversion from ‘CParent*’ to ‘CBrother*’

    // The following use case is very unsafe because for example the subclass could have methods
    // that does not exist in the main class
    // CBrother *pBrother = static_cast<CBrother *>(&parent);

    // CBrother *pBrother = pParent; // error: invalid conversion from ‘CParent*’ to ‘CBrother*’
    CBrother *pBrother = static_cast<CBrother *>(pParent); // This is dangerous also because static_cast does not
                                                           // have type checking so this can fail at runtime
    std::cout << pBrother << std::endl;

    CParent &&p = static_cast<CParent &&>(parent); // Cast an LValue Reference to an RValue Reference
    p.speak();

    // Dynamic Cast
    CBrother *pBrother2 = dynamic_cast<CBrother *>(pParent); // Cast an LValue Reference to an RValue Reference
    if (pBrother2 == nullptr)
    {
        std::cout << "Invalid Cast" << std::endl;
    }
    else
    {
        std::cout << pBrother2 << std::endl;
    }

    // Reinterpret Cast
    CSister *pSister = dynamic_cast<CSister *>(pParent); // Returns nullptr
    if (pSister == nullptr)
    {
        std::cout << "Invalid Cast" << std::endl;
    }
    else
    {
        std::cout << pBrother2 << std::endl;
    }
    CSister *pSister2 = reinterpret_cast<CSister *>(pParent); // Returns correct pointer
    if (pSister2 == nullptr)
    {
        std::cout << "Invalid Cast" << std::endl;
    }
    else
    {
        std::cout << pBrother2 << std::endl;
    }

    return 0;
}
