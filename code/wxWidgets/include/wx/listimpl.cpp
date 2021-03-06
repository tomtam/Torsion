/////////////////////////////////////////////////////////////////////////////
// Name:        listimpl.cpp
// Purpose:     second-part of macro based implementation of template lists
// Author:      Vadim Zeitlin
// Modified by:
// Created:     16/11/98
// RCS-ID:      $Id: listimpl.cpp,v 1.8.2.1 2006/01/17 19:02:24 JS Exp $
// Copyright:   (c) 1998 Vadim Zeitlin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#if wxUSE_STL

    #undef  WX_DEFINE_LIST
    #define WX_DEFINE_LIST(name)                                        \
        void name::DeleteFunction( _WX_DELETEFUNCTIONCONST _WX_LIST_ITEM_TYPE_##name X )  \
        {                                                               \
            delete X;                                                   \
        }

#else // if !wxUSE_STL

    #define _DEFINE_LIST(T, name)         \
        void wx##name##Node::DeleteData() \
        {                                 \
            delete (T *)GetData();        \
        }

    // redefine the macro so that now it will generate the class implementation
    // old value would provoke a compile-time error if this file is not included
    #undef  WX_DEFINE_LIST
    #define WX_DEFINE_LIST(name) _DEFINE_LIST(_WX_LIST_ITEM_TYPE_##name, name)

    // don't pollute preprocessor's name space
    //#undef  _DEFINE_LIST

#endif

