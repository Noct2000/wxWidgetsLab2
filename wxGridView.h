#ifndef WXGRIDVIEW_H
#define WXGRIDVIEW_H

#include <wx/grid.h>
#include "wxGraphData.h"


class wxGridView : public wxGrid
{
    public:
        wxGridView(wxWindow *parent, const wxGraphData *data);
        virtual ~wxGridView();
        wxGridView(const wxGridView& other);
    private:
        const wxGraphData *m_data;
};

#endif // WXGRIDVIEW_H
