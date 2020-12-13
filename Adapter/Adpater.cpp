#include "Adapter.hpp"
#include "Adaptee.hpp"

#include <functional>
#include <algorithm>

Adapter::Adapter(Adaptee* adaptee) : m_adaptee(adaptee)
{
}

std::string Adapter::Request() const
{
    std::string to_reverse = m_adaptee->SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
}

Adapter::~Adapter()
{
    /* DO NOT delete this pointer, because it was not created and
     * allocated by the Adpter class itself.
     */
    m_adaptee = nullptr;
}
