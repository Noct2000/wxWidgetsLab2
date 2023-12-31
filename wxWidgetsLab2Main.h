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

#include "wxPaintView.h"
#include "wxGridView.h"

//(*Headers(wxWidgetsLab2Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#define ID_GRAPHICS_VIEW 1
#define ID_GRID_VIEW     2

class wxWidgetsLab2Frame: public wxFrame
{
    public:

        wxWidgetsLab2Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxWidgetsLab2Frame();

    private:

        wxPaintView *m_paintView;
        wxGridView *m_gridView;
        wxGraphData *m_data;
        void CreateView(int id_view);
        void DestroyView(int id_view);

        //(*Handlers(wxWidgetsLab2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnGraphData(wxCommandEvent& event);
        void OnGridData(wxCommandEvent& event);
        void OnGenerateData(wxCommandEvent& event);
        void OnCloseData(wxCommandEvent& event);
        void OnOpenFile(wxCommandEvent& event);
        void OnSaveFile(wxCommandEvent& event);
        void OnExport(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
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
