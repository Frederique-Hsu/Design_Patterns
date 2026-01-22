/*!
 *  \file       GlyphContext.cpp
 *  \brief      
 *  
 */


#include "GlyphContext.hpp"

#include "Font.hpp"


namespace gof_design_patterns
{
    GlyphContext::GlyphContext() : m_index{0}, m_fonts{nullptr}
    {
    }
    
    GlyphContext::~GlyphContext()
    {
    }
    
    void GlyphContext::next(int step)
    {
        m_index += step;
    }
    
    void GlyphContext::insert(int quantity)
    {
        (void)quantity;
        /*!
         *  \todo   Implement your code here in the future.
         */
    }
    
    Font* GlyphContext::getFont()
    {
        /*!
         *  \todo   GlyphContext::getFont() uses the index as a key into a BTree structure that stores the glyph-to-font mapping.
         *          Each node in the tree is labeled with the length of the string for which it gives font infotmation.
         *          Leaf node in the tree points to a font, while interior nodes break the string into sub-strings, one for each child.
         */
        return nullptr;
    }
    
    void GlyphContext::setFont(Font *, int span)
    {
        (void)span;
        /*!
         *  \todo   Implement your code here in the future.
         */
    }
}
