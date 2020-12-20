#include "Multi_Inheritance_Adapter.hpp"

#include <algorithm>

std::string MIAdapter::Request() const
{
    std::string to_reverse = SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "MIAdapter: (TRANSLATED) " + to_reverse;
}
