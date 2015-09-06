//
// nvGlutWidgets
//
//  Adaptor classes to integrate the nvWidgets UI library with the GLUT windowing
// toolkit. The adaptors convert native GLUT UI data to native nvWidgets data. All
// adaptor classes are implemented as in-line code in this header. The adaptor
// defaults to using the standard OpenGL painter implementation.
//
// Author: Ignacio Castano, Samuel Gateau, Evan Hart
// Email: sdkfeedback@nvidia.com
// 
// Modified for GLFW support: Charles de Rousiers
// Email: Charles de Rousiers
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef GLUI_CONTEXT_HPP
#define GLUI_CONTEXT_HPP

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <glui/widgets.hpp>

namespace glui
{

	//-------------------------------------------------------------------------
	// Class default Context
	// To call (in event callback) for using widget framework
	//  - IOContext::Mouse
	//  - UIContext::Motion
	//  - IOContext::Special
	//  - UIContext::Keyboard
	//  - UIContext::Reshape
	//
	//-------------------------------------------------------------------------
    class GlfwContext : public UIContext
    {
    public:

		//---------------------------------------------------------------------
        // Default UI constructor
        //
        //  Creates private OpenGL painter
		//---------------------------------------------------------------------
		GlfwContext();

		//---------------------------------------------------------------------
        // Alternate UI constructor
        //
        //  Allows for overriding the standard painter
		//---------------------------------------------------------------------
        GlfwContext(UIPainter& _painter);

		//---------------------------------------------------------------------
        // UI  destructor
        //
        //  Destroy painter if it is private
		//---------------------------------------------------------------------
        virtual ~GlfwContext();

		//---------------------------------------------------------------------
        // UI method for processing GLUT mouse button events
        //
        //  Call this method from the glutMouseFunc callback, the
        // modifier parameter maps to glutGetModifiers.
 		//---------------------------------------------------------------------
        void Mouse(int _x, int _y, int _button, int _state);

		//---------------------------------------------------------------------
        // UI method for processing key events
        //
        //  Call this method from the glutReshapeFunc callback
		//---------------------------------------------------------------------
       // void Special(IO::Keyboard::Key _k, IO::Keyboard::State _s);

    private:
		enum Modifier { CTRL, SHIFT, ALT };
		int m_modifiers;
    };

};

#endif
