#ifndef Arduino_h
#include <cstdint>
#endif

namespace runtimepoly
{

class Base
{
public:
    virtual void do_something() = 0;
};

class Derived : public Base
{
protected:
    uint32_t m_counter { 0 };
public:
    
    void do_something()
    {
        ++m_counter;
    }

    uint32_t count()
    {
        return m_counter;
    }
}; // class Derived

class OtherDerived : public Base
{
protected:
    uint32_t m_counter { 0 };
public:
    void do_something()
    {
        ++m_counter;
    }

    uint32_t count()
    {
        return m_counter;
    }
}; // class OtherDerived

} // namespace runtimepoly
