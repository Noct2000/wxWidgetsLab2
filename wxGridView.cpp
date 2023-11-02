#include "wxGridView.h"

wxGridView::wxGridView(wxWindow *parent, const wxGraphData *data) : wxGrid(parent, wxID_ANY)
{
    m_data = data;
    int rows = m_data->GetCount();
    CreateGrid(rows, 2);
    SetColLabelValue(0, "X");
    SetColLabelValue(1, "Y");
    EnableScrolling(false, true);
    EnableEditing(false);
    for (int i = 0; i < rows; i++)
    {
        double x = m_data->GetPoint(i).x;
        double y = m_data->GetPoint(i).y;
        SetCellValue(i, 0, wxString::FromDouble(x));
        SetCellValue(i, 1, wxString::FromDouble(y));
    }
}

wxGridView::~wxGridView()
{
    ClearGrid();
}

wxGridView::wxGridView(const wxGridView& other)
{
    //copy ctor
}
