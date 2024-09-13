/*!
 *  \file       parameterized_creator_impl.hpp
 *  \brief
 *
 */

/*!
 *  \section    Implementation
 */

template<typename ProductType>
ParameterizedCreator<ProductType>::ParameterizedCreator() : VirtualCreator()
{
}

template<typename ProductType>
ParameterizedCreator<ProductType>::~ParameterizedCreator()
{
}

template<typename ProductType>
ProductType* ParameterizedCreator<ProductType>::createProduct()
{
    return new ProductType;
}