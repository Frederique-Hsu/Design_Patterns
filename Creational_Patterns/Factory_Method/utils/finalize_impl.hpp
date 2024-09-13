/*!
 *  \file       finalize_impl.hpp
 *  \brief      
 *  
 */


template<typename FnObjType>
class FinalAction
{
public:
    FinalAction(FnObjType fn_obj);
    ~FinalAction();
private:
    FnObjType clean;
};


template<typename FnObjType>
FinalAction<FnObjType>::FinalAction(FnObjType fn_obj) : clean{fn_obj}
{
}

template<typename FnObjType>
FinalAction<FnObjType>::~FinalAction()
{
    clean();
}

template<typename FnObjType>
FinalAction<FnObjType> finalize(FnObjType fn_obj)
{
    return FinalAction<FnObjType>(fn_obj);
}