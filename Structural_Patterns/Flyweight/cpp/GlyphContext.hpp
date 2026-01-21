/*!
 *  \file       GlyphContext.hpp
 *  \brief      
 *  
 */


#pragma once


namespace gof_design_patterns
{
    class BTree;
    class Font;
    
    class GlyphContext
    {
    public:
        GlyphContext();
        virtual ~GlyphContext();
        
    private:
        int m_index;
        [[maybe_unused]] BTree *m_fonts;
        
    public:
        virtual void next(int step = -1);
        virtual void insert(int quantity = 1);
        
        virtual Font* getFont();
        virtual void setFont(Font *, int span = 1);
    };
}
