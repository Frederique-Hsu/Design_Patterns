/*!
 *  \file       finalize.cpp
 *  \brief
 *
 */


#include "finalize.hpp"


template<typename FnReturnType>
class FinalAction
{
public:
    FinalAction(FnReturnType fn);
    ~FinalAction();

private:
    FnReturnType m_function;
};


template<typename FnReturnType>
FinalAction<FnReturnType>::FinalAction(FnReturnType fn) : m_function{fn}
{
}

template<typename FnReturnType>
FinalAction<FnReturnType>::~FinalAction()
{
    m_function();
}


template<typename FnReturnType>
FinalAction<FnReturnType> finalize(FnReturnType fn)
{
    return FinalAction<FnReturnType>(fn);
}
