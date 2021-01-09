#ifndef LEAF_HPP
#define LEAF_HPP

    #include "Component.hpp"

    class Leaf;

    /* The leaf class represents the end objects of a composition.
     * A leaf cannot have any children.
     *
     * Usuallu, it is the Leaf objects that do the actual work, whereas
     * Composite objects only delegate to their sub-components.
     */
    class Leaf : public Component
    {
    public:
        std::string Operation() const override;
    };

#endif  /* LEAF_HPP */
