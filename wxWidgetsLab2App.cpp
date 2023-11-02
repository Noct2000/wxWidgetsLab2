/***************************************************************
 * Name:      wxWidgetsLab2App.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-10-31
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wxWidgetsLab2App.h"

//(*AppHeaders
#include "wxWidgetsLab2Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxWidgetsLab2App);

bool wxWidgetsLab2App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxWidgetsLab2Frame* Frame = new wxWidgetsLab2Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
