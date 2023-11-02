#include "wxPaintView.h"
#include <wx/dcclient.h>

wxPaintView::wxPaintView(wxWindow *parent,
                         const wxGraphData *data,
                         double x_border,
                         int y_border_in_pixels) : wxPanel(parent, wxID_ANY, wxPoint(0, 0), wxSize(200, 300))
{
    m_flDraw = false;
    m_data = data;
    m_x_border = x_border;
    m_y_border_in_pixels = y_border_in_pixels;
    Connect(wxEVT_PAINT, (wxObjectEventFunction) &wxPaintView::OnPaint);
    Connect(wxEVT_SIZE, (wxObjectEventFunction) &wxPaintView::OnResize);
}

wxPaintView::~wxPaintView()
{
    m_flDraw = false;
}

wxPaintView::wxPaintView(const wxPaintView& other)
{
    //copy ctor
}

void wxPaintView::SetDrawFlag(bool flDraw)
{
    m_flDraw = flDraw;
    this->Refresh();
}

int wxPaintView::GetIntXCoord(double x, int width) const
{
    return (x + m_x_border * M_PI) * width / ((m_x_border * 2) * M_PI);
}

int wxPaintView::GetIntYCoord(double y, int height) const
{
    return height - m_y_border_in_pixels - (y + 1) * (height - m_y_border_in_pixels) / 2. + m_y_border_in_pixels / 2;
}


void wxPaintView::OnResize(wxSizeEvent& event)
{
    this->Refresh();
}

void wxPaintView::OnPaint(wxPaintEvent& event)
{
    if (m_flDraw)
    {
        wxPaintDC dc(this);
        dc.SetPen(*wxBLACK_PEN);
        wxRect rect = GetClientRect();
        wxCoord centerX = 0, centerY = 0;
        centerX = (int)(rect.width / 2.);
        centerY = (int)(rect.height / 2.);
        dc.DrawLine(wxPoint(0, centerY), wxPoint(rect.width, centerY));
        dc.DrawLine(wxPoint(centerX, 0), wxPoint(centerX, rect.height));
        dc.SetPen(*wxBLUE_PEN);
        if (!m_data->IsEmpty())
        {
            int count = (m_data->GetCount()) - 1;
            for (int i = 0; i < count; i += 2)
            {
                double x1 = m_data->GetPoint(i).x;
                double y1 = m_data->GetPoint(i).y;
                double x2 = m_data->GetPoint(i + 1).x;
                double y2 = m_data->GetPoint(i + 1).y;
                int i_x1 = GetIntXCoord(x1, rect.width);
                int i_y1 = GetIntYCoord(y1, rect.height);
                int i_x2 = GetIntXCoord(x2, rect.width);
                int i_y2 = GetIntYCoord(y2, rect.height);
                i_x2 = (i_x1 == i_x2) ? i_x1 + 1 : i_x2;
                dc.DrawLine(wxPoint(i_x1, i_y1), wxPoint(i_x2, i_y2));
            }
        }
    }
}
