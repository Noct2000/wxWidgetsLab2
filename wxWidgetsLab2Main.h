/***************************************************************
 * Name:      wxWidgetsLab2Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-10-31
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef WXWIDGETSLAB2MAIN_H
#define WXWIDGETSLAB2MAIN_H

//(*Headers(wxWidgetsLab2Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class wxWidgetsLab2Frame: public wxFrame
{
    public:

        wxWidgetsLab2Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxWidgetsLab2Frame();

    private:

        //(*Handlers(wxWidgetsLab2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxWidgetsLab2Frame)
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM7;
        static const long ID_MENUITEM8;
        static const long ID_MENUITEM9;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxWidgetsLab2Frame)
        wxMenu* Menu1;
        wxMenu* Menu2;
        wxMenu* Menu3;
        wxMenu* Menu4;
        wxMenuItem* MenuItem1;
        wxMenuItem* MenuItem2;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem8;
        wxMenuItem* MenuItem9;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXWIDGETSLAB2MAIN_H
