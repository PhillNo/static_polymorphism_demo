#ifndef Arduino_h
#include <cstdint>
#endif

namespace staticpoly
{

template <typename Derived>
class Base
{
public:
    void do_something()
    {
        static_cast<Derived*>(this)->do_something_impl();
    }
};

class DerivedTemplate : public Base<DerivedTemplate>
{
protected:
    uint32_t m_counter { 0 };
public:
    void do_something_impl()
    {
        ++m_counter;
    }

    uint32_t count_impl()
    {
        return m_counter;
    }

}; //class Derived

} // namespace staticpoly
