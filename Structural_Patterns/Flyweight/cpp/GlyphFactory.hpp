/*!
 *  \file       GlyphFactory.hpp
 *  \brief
 *
 */


#pragma once


namespace gof_design_patterns
{
    constexpr const int NCHARCODES = 128;
    
    class Character;
    class Row;
    class Column;
    
    class GlyphFactory
    {
    public:
        GlyphFactory();
        virtual ~GlyphFactory();
        
    private:
        Character *m_characters[NCHARCODES];
        
    public:
        virtual Character* createCharacter(char);
        virtual Row* createRow();
        virtual Column* createColumn();
    };
}
