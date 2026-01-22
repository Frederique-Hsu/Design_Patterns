/*!
 *  \file       GlyphFactory.cpp
 *  \brief
 *
 */


#include "GlyphFactory.hpp"

#include "Character.hpp"
#include "Row.hpp"
#include "Column.hpp"


namespace gof_design_patterns
{
    GlyphFactory::GlyphFactory()
    {
        for (int index = 0; index < NCHARCODES; ++index)
        {
            m_characters[index] = nullptr;
        }
    }
    
    GlyphFactory::~GlyphFactory()
    {
        for (int index = 0; index < NCHARCODES; ++index)
        {
            if (m_characters[index])
            {
                delete m_characters[index];
                m_characters[index] = nullptr;
            }
        }
    }
    
    Character* GlyphFactory::createCharacter(char c)
    {
        if (!m_characters[static_cast<int>(c)])
        {
            m_characters[static_cast<int>(c)] = new Character(c);
        }
        return m_characters[static_cast<int>(c)];
    }
    
    Row* GlyphFactory::createRow()
    {
        return new Row;
    }
    
    Column* GlyphFactory::createColumn()
    {
        return new Column;
    }
}
