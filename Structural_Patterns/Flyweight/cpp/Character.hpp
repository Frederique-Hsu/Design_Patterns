/*!
 *  \file       Character.hpp
 *  \brief
 *
 */


#pragma once

#include "Glyph.hpp"

namespace gof_design_patterns
{
    class Character : public Glyph
    {
    public:
        Character(char);
        
    private:
        [[maybe_unused]] char m_charcode;
        
    public:
        void draw(Window *, GlyphContext &) override;
    };
}
