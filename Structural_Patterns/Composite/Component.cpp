#include "Component.hpp"

Component::~Component()
{
}

void Component::SetParent(Component *parent)
{
    m_parent = parent;
}

Component* Component::GetParent() const
{
    return m_parent;
}

void Component::Add(Component *component)
{
}

void Component::Remove(Component *component)
{
}

bool Component::IsComposite() const
{
    return false;
}
