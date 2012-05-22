
// Copyright (C) 2011 R. Keith Morley 
// 
// (MIT/X11 License)
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#ifndef OTK_COMMON_LEXICAL_SCOPE_HPP_
#define OTK_COMMON_LEXICAL_SCOPE_HPP_

#include <string>

namespace otk
{


class LexicalScope
{
public:
    LexicalScope();

    void bindVariables();

    template <typename OPTIX_NODE>
    void bindVariables( OPTIX_NODE node );

    template <typename VTYPE>
    bool setf( const std::string& name, VTYPE val );
    
    template <typename VTYPE, typename NTYPE>
    bool setf( const std::string& name, VTYPE val, NTYPE node );


private:
    class OptiXNode
    {
    public:
        explicit OptiXNode( optix::Context          context );
        explicit OptiXNode( optix::Geometry         geometry );
        explicit OptiXNode( optix::GeometryInstance geometry_instance );
        explicit OptiXNode( optix::Material         material );


    private:
        RTobjecttype  m_node_type;
        union
        {
            RTcontext          context; 
            RTgeometry         geometry;
            RTgeometryinstance geometry_instance;
            RTmaterial         material;
        } m_node;             
    };

    typedef std::map<std::string, OptiXNode> m_variables;
};


}

#endif // OTK_COMMON_LEXICAL_SCOPE_HPP_
