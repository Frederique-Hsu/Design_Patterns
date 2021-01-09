#ifndef COMPONENT_HPP
#define COMPONENT_HPP

    #include <string>

    class Component;

    /* The base Component class declares common operations for bot simple
     * and complex objects of a composition.
     */
    class Component
    {
    protected:
        Component* m_parent;
        /* Optionally, the base Component can declare an interface for setting and accessing
         * a parent of the Component in a tree structure. It can alse provide some
         * default implementation for these methods.
         */
    public:
        virtual ~Component();
    public:
        void SetParent(Component* parent);
        Component* GetParent() const;
        /* In some cases, it would be beneficial to define the child-management operations
         * right in the base Component class.
         * This way, you won't need to expose any concrete component classes to the client
         * code, even during the object tree assembly.
         * The downside is that these methods will be empty for the leaf-level components.
         */
        virtual void Add(Component* component);
        virtual void Remove(Component* component);
        /* You can provide a method that lets the client code figure out whether
         * a component can bear children.
         */
        virtual bool IsComposite() const;
        /* The base Component may implement some default behaviour or leave it to
         * concrete classes (by declaring the method containing the behaviour as abstract).
         */
        virtual std::string Operation() const = 0;
    };

#endif  /* COMPONENT_HPP */
