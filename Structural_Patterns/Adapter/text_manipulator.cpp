/*!
 *  \file       text_manipulator.cpp
 *  \brief      
 *  
 */


#include "text_manipulator.hpp"
#include "text_shape.hpp"

TextManipulator::TextManipulator(const TextShape* pshape) 
    : Manipulator(), m_text_shape{pshape}
{
}

TextManipulator::~TextManipulator()
{
#if false
    /*!
     *  \warning    at this moment, we cannot destroy the m_text_shape pointer object, because it was passed from
     *              the constructor. Inside the ~TextShape destructor, the m_text will be deleted according.
     *              If we delete inside the ~TextManipulator, it will incur the double free issue, and the program
     *              crashed definitely.
     */
    if (m_text_shape != nullptr)
    {
        delete m_text_shape;
    }
#endif
}