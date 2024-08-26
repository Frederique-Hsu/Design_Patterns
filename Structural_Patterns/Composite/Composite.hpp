#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

    #include <list>
    #include "Component.hpp"

    class Composite;

    /* The Composite class represents the complex components that may have children.
     * Usually, the Composite objects delegate the actual work to their children and
     * then "sum-up" the result.
     */
    class Composite : public Component
    {
    protected:
        std::list<Component*> children;
    public:
        /* A composite object can add or remove other components (both simple or
         * complex) to or from its child list.
         */
        void Add(Component* component) override;
        /* Keep in mind that this method removes the pointer from the list,
         * but does not frees the memory.
         * You should do it manually or better use the smart pointers.
         */
        void Remove(Component* component) override;
        bool IsComposite() const override;
        /* The Composite executes its primary logic in a particular way.
         * It traverses ewcursively through all its children, collecting and summing
         * their results.
         * Sincere the composite's children pass these calls to their children
         * and so forth, the whole object tree is traversed as a result.
         */
        std::string Operation() const override;
    };


#endif  /* COMPOSITE_HPP */
