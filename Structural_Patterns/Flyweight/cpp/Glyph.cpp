/*!
 *  \file       Glyph.cpp
 *  \brief      
 *  
 */


#include "Glyph.hpp"

#include <iostream>

#include "GlyphContext.hpp"


namespace gof_design_patterns
{
    Glyph::Glyph()
    {
        std::cout << "Glyph::Glyph()" << std::endl;
    }
    
    Glyph::~Glyph()
    {
        std::cout << "Glyph::~Glyph()" << std::endl;
    }
    
    void Glyph::draw(Window *, GlyphContext &)
    {
        std::cout << "Glyph::draw(Window *, GlyphContext &)" << std::endl;
    }
    
    void Glyph::setFont(Font *, GlyphContext &)
    {
        std::cout << "Glyph::setFont(Font *, GlyphContext &)" << std::endl;
    }
    
    Font* Glyph::getFont(GlyphContext &context)
    {
        std::cout << "Glyph::getFont(GlyphContext &)" << std::endl;
        return context.getFont();
    }
    
    void Glyph::first(GlyphContext &)
    {
        std::cout << "Glyph::first(GlyphContext &)" << std::endl;
    }
    
    void Glyph::next(GlyphContext &)
    {
        std::cout << "Glyph::next(GlyphContext &)" << std::endl;
    }
    
    bool Glyph::isDone(GlyphContext &)
    {
        std::cout << "Glyph::isDone(GlyphContext &)" << std::endl;
        return false;
    }
    
    Glyph* Glyph::current(GlyphContext &)
    {
        std::cout << "Glyph::current(GlyphContext &)" << std::endl;
        return nullptr;
    }
    
    void Glyph::insert(Glyph *, GlyphContext &)
    {
        std::cout << "Glyph::insert(Glyph *, GlyphContext &)" << std::endl;
    }
    
    void Glyph::remove(GlyphContext &)
    {
        std::cout << "Glyph::remove(GlyphContext &)" << std::endl;
    }
}
