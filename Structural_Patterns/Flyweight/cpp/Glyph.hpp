/*!
 *  \file       Glyph.hpp
 *  \brief      
 *  
 */


#pragma once


namespace gof_design_patterns
{
    class Window;
    class GlyphContext;
    class Font;
    
    class Glyph
    {
    public:
        virtual ~Glyph();
        
    protected:
        Glyph();
        
    public:
        virtual void draw(Window *, GlyphContext &);
        
        virtual void setFont(Font *, GlyphContext &);
        virtual Font* getFont(GlyphContext &);
        
        virtual void first(GlyphContext &);
        virtual void next(GlyphContext &);
        virtual bool isDone(GlyphContext &);
        virtual Glyph* current(GlyphContext &);
        virtual void insert(Glyph *, GlyphContext &);
        virtual void remove(GlyphContext &);
    };
}
