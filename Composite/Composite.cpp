#include "Composite.hpp"

void Composite::Add(Component *component)
{
    children.push_back(component);
    component->SetParent(this);
}

void Composite::Remove(Component *component)
{
    for (auto iter = children.begin(); iter != children.end(); ++iter)
    {
        if (*iter == component)
        {
            children.remove(*iter);
            component->SetParent(nullptr);
            return;
        }
    }
}

bool Composite::IsComposite() const
{
    if (children.empty() == true)
        return false;
    else
        return true;
}

std::string Composite::Operation() const
{
    std::string result;
    for (const Component* comp : children)
    {
        if (comp == children.back())
        {
            result += comp->Operation();
        }
        else
        {
            result += comp->Operation() + "+";
        }
    }
    return "Branch(" + result + ")";
}
