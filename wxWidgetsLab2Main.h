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
        static const long ID_MENU_OPEN;
        static const long ID_MENU_SAVE;
        static const long ID_MENU_CLOSE;
        static const long ID_MENU_EXPORT;
        static const long ID_MENU_EXIT;
        static const long ID_MENU_TABLE_DATA;
        static const long ID_MENU_GRAPHIC_DATA;
        static const long ID_MENU_GENERATE_DATA;
        static const long ID_MENU_ABOUT;
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
