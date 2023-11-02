#ifndef WXPAINTVIEW_H
#define WXPAINTVIEW_H

#include <wx/panel.h>
#include <wx/window.h>
#include "wxGraphData.h"


class wxPaintView : public wxPanel
{
    public:
        wxPaintView(wxWindow *parent, const wxGraphData *data, double x_border, int y_border_in_pixels);
        virtual ~wxPaintView();
        wxPaintView(const wxPaintView& other);
        void OnPaint(wxPaintEvent& event);
        void OnResize(wxSizeEvent& event);
        void SetDrawFlag(bool flDraw);
    private:
        bool m_flDraw;
        double m_x_border;
        int m_y_border_in_pixels;
        const wxGraphData *m_data;
        int GetIntXCoord(double x, int width) const;
        int GetIntYCoord(double y, int width) const;

};

#endif // WXPAINTVIEW_H
