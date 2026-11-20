#include <chrono>
#include <iostream>

#include "static.hpp"
#include "runtime.hpp"

using namespace std;

void invoke_runtime(runtimepoly::Base& object)
{
    object.do_something();
}

template<typename AnyDerived>
void invoke_static(staticpoly::Base<AnyDerived>& object)
{
    object.do_something();
}

int main(int argc, char **argv)
{
    constexpr size_t loops { 5000 };
    uint32_t counter { 0 };

    runtimepoly::Derived rtpA;
    runtimepoly::OtherDerived rtpB;
    staticpoly::DerivedTemplate sp;

    std::chrono::_V2::system_clock::time_point begin, end;
    std::chrono::duration<int64_t, std::nano> elapsedA, elapsedB;

    /************************************************** */
    cout << "Runtime A: " << endl;
    
    begin = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < loops; ++i)
    {
        invoke_runtime(rtpA);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsedA = end - begin;
    cout << "Time: " << ((elapsedA).count()) << endl;
    cout << "Internal member incremented: " << rtpA.count() << endl << endl;
    /************************************************** */
    
    /************************************************** */
    cout << "Runtime B: " << endl;
    
    begin = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < loops; ++i)
    {
        invoke_runtime(rtpB);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsedA = end - begin;
    cout << "Time: " << ((elapsedA).count()) << endl;
    cout << "Internal member incremented: " << rtpB.count() << endl << endl;
    /************************************************** */

    /************************************************** */
    cout << "Static: " << endl;
    
    begin = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < loops; ++i)
    {
        invoke_static(sp);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsedB = end - begin;
    cout << "Time: " << ((elapsedB).count()) << endl;
    cout << "Internal member incremented: " << sp.count_impl() << endl << endl;
    /************************************************** */

    cout << "Elapsed diff: " << (elapsedA - elapsedB).count() << endl << endl;

    /************************************************** */
    cout << "No function: " << endl;
    
    begin = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < loops; ++i)
    {
        ++counter;
    }
    end = std::chrono::high_resolution_clock::now();
    elapsedA = end - begin;
    cout << "Time: " << ((elapsedA).count()) << endl;
    cout << "Counter incremented: " << counter << endl << endl;
    /************************************************** */
}
