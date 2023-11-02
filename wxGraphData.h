#ifndef WXGRAPHDATA_H
#define WXGRAPHDATA_H

#include <wx/dynarray.h>
#include <wx/gdicmn.h>

WX_DECLARE_OBJARRAY(wxRealPoint, wxVectorRealPoint);

typedef double (*MATH_FUNC)(double);

class wxGraphData
{
public:
    wxGraphData();
    virtual ~wxGraphData();
    wxGraphData(const wxGraphData& other);
    void Clear();
    bool IsEmpty() const;
    int GetCount() const;
    void AddPoint(double x, double y);
    const wxRealPoint& GetPoint(int index) const;
    const wxRealPoint& operator[] (int index);
    bool SaveToFile(const wxString& filename) const;
    bool LoadFromFile(const wxString& filename);
    void Generate(MATH_FUNC periodic_math_func = sin, double x_border = 4.);
    double GetXBorder() const;

protected:

private:
    double m_x_border;
    wxVectorRealPoint* m_pts;
};

#endif // WXGRAPHDATA_H
