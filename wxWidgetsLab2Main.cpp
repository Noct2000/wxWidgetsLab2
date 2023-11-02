/***************************************************************
 * Name:      wxWidgetsLab2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-10-31
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wxWidgetsLab2Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxWidgetsLab2Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxWidgetsLab2Frame)
const long wxWidgetsLab2Frame::ID_MENU_OPEN = wxNewId();
const long wxWidgetsLab2Frame::ID_MENU_SAVE = wxNewId();
const long wxWidgetsLab2Frame::ID_MENU_CLOSE = wxNewId();
const long wxWidgetsLab2Frame::ID_MENU_EXPORT = wxNewId();
const long wxWidgetsLab2Frame::ID_MENU_EXIT = wxNewId();
const long wxWidgetsLab2Frame::ID_MENU_TABLE_DATA = wxNewId();
const long wxWidgetsLab2Frame::ID_MENU_GRAPHIC_DATA = wxNewId();
const long wxWidgetsLab2Frame::ID_MENU_GENERATE_DATA = wxNewId();
const long wxWidgetsLab2Frame::ID_MENU_ABOUT = wxNewId();
const long wxWidgetsLab2Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxWidgetsLab2Frame,wxFrame)
    EVT_MENU(ID_MENU_ABOUT, wxWidgetsLab2Frame::OnAbout)
END_EVENT_TABLE()

wxWidgetsLab2Frame::wxWidgetsLab2Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxWidgetsLab2Frame)
    wxMenuBar* MenuBar1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENU_OPEN, _("Open..."), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuItem2 = new wxMenuItem(Menu1, ID_MENU_SAVE, _("Save As..."), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem2);
    MenuItem3 = new wxMenuItem(Menu1, ID_MENU_CLOSE, _("Close"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    Menu1->AppendSeparator();
    MenuItem4 = new wxMenuItem(Menu1, ID_MENU_EXPORT, _("Export..."), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    Menu1->AppendSeparator();
    MenuItem5 = new wxMenuItem(Menu1, ID_MENU_EXIT, _("Exit"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    MenuBar1->Append(Menu1, _("File"));
    Menu2 = new wxMenu();
    MenuItem6 = new wxMenuItem(Menu2, ID_MENU_TABLE_DATA, _("Table Data"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu2, ID_MENU_GRAPHIC_DATA, _("Graphic Data"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem7);
    MenuBar1->Append(Menu2, _("View"));
    Menu3 = new wxMenu();
    MenuItem8 = new wxMenuItem(Menu3, ID_MENU_GENERATE_DATA, _("Generate Data..."), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem8);
    MenuBar1->Append(Menu3, _("Processing"));
    Menu4 = new wxMenu();
    MenuItem9 = new wxMenuItem(Menu4, ID_MENU_ABOUT, _("About..."), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem9);
    MenuBar1->Append(Menu4, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    //*)
}

wxWidgetsLab2Frame::~wxWidgetsLab2Frame()
{
    //(*Destroy(wxWidgetsLab2Frame)
    //*)
}

void wxWidgetsLab2Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxWidgetsLab2Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f) + "\nAuthor: Oleh Kvasha";
    wxMessageBox(msg, _("Welcome to wxWidgets Lab2 App"));
}
