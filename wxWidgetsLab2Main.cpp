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
#include <wx/file.h>
#include <wxGraphData.h>

//(*InternalHeaders(wxWidgetsLab2Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#define GRAPH_DATA_FILENAME "graph.dat"

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
    EVT_MENU(ID_MENU_EXIT, wxWidgetsLab2Frame::OnQuit)
    EVT_MENU(ID_MENU_GRAPHIC_DATA, wxWidgetsLab2Frame::OnGraphData)
    EVT_MENU(ID_MENU_TABLE_DATA, wxWidgetsLab2Frame::OnGridData)
    EVT_CLOSE(wxWidgetsLab2Frame::OnClose)
END_EVENT_TABLE()

wxWidgetsLab2Frame::wxWidgetsLab2Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxWidgetsLab2Frame)
    wxMenuBar* MenuBar1;

    Create(parent, id, _("wxWidgetsLab2"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
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

    m_paintView = nullptr;
    m_gridView = nullptr;
    m_data = new wxGraphData();

    if (!wxFile::Exists(GRAPH_DATA_FILENAME)) m_data->Generate();
    else m_data->LoadFromFile(GRAPH_DATA_FILENAME);
}

wxWidgetsLab2Frame::~wxWidgetsLab2Frame()
{
    DestroyView(ID_GRAPHICS_VIEW);
    DestroyView(ID_GRID_VIEW);
    delete m_data;

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

void wxWidgetsLab2Frame::OnClose(wxCloseEvent& event)
{
    wxMessageBox("Close");
    Destroy();
}

void wxWidgetsLab2Frame::CreateView(int id_view)
{
    if (!m_data->IsEmpty())
    {
        switch(id_view) {
        case ID_GRAPHICS_VIEW:
            m_paintView = new wxPaintView(this, (const wxGraphData *)m_data, m_data->GetXBorder(), 20);
            m_paintView->SetDrawFlag(true);
            break;

        case ID_GRID_VIEW:
            m_gridView = new wxGridView(this, (const wxGraphData *)m_data);
            break;
    }

    this->PostSizeEvent();
    }
    else {
        wxMessageBox("No Data", "ERROR",
                     wxOK | wxICON_ERROR, this);
        Close();
    }
}

void wxWidgetsLab2Frame::DestroyView(int id_view)
{
    switch(id_view) {
        case ID_GRAPHICS_VIEW:
            if (m_paintView != nullptr) {
                m_paintView->SetDrawFlag(false);
                if (m_paintView->Destroy()) m_paintView = nullptr;
            }
            break;
        case ID_GRID_VIEW:
            if (m_gridView != nullptr) {
                if (m_gridView->Destroy()) m_gridView = nullptr;
            }
            break;
    }
}

void wxWidgetsLab2Frame::SwitchToSelectView()
{
    if (m_paintView != nullptr) {
        DestroyView(ID_GRAPHICS_VIEW);
        CreateView(ID_GRID_VIEW);
    } else {
        DestroyView(ID_GRID_VIEW);
        CreateView(ID_GRAPHICS_VIEW);
    }
}

void wxWidgetsLab2Frame::OnLoadData(wxCommandEvent& event)
{
    if (m_data->LoadFromFile(GRAPH_DATA_FILENAME)) SwitchToSelectView();
}

void wxWidgetsLab2Frame::OnSaveData(wxCommandEvent& event)
{
    m_data->SaveToFile(GRAPH_DATA_FILENAME);
}

void wxWidgetsLab2Frame::OnGraphData(wxCommandEvent& event)
{
    if (m_gridView != nullptr) {
        DestroyView(ID_GRID_VIEW);
        CreateView(ID_GRAPHICS_VIEW);
    } else if (m_paintView != nullptr) {
        DestroyView(ID_GRAPHICS_VIEW);
    } else {
        CreateView(ID_GRAPHICS_VIEW);
    }
}

void wxWidgetsLab2Frame::OnGridData(wxCommandEvent& event)
{
    if (m_paintView != nullptr) {
        DestroyView(ID_GRAPHICS_VIEW);
        CreateView(ID_GRID_VIEW);
    } else if (m_gridView != nullptr) {
        DestroyView(ID_GRID_VIEW);
    } else {
        CreateView(ID_GRID_VIEW);
    }
}

