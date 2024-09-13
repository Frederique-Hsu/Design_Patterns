/*!
 *  \file       finalize.hpp
 *  \brief      
 *  
 */


#pragma once


template<typename FnObjType> class FinalAction;


template<typename FnObjType> FinalAction<FnObjType> finalize(FnObjType fn_obj);


#include "finalize_impl.hpp"