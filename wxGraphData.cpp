#include "wxGraphData.h"
#include <wx/file.h>

#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(wxVectorRealPoint);

wxGraphData::wxGraphData()
{
    m_pts = new wxVectorRealPoint();
    m_x_border = 0;
}

wxGraphData::~wxGraphData()
{
    delete m_pts;
}

wxGraphData::wxGraphData(const wxGraphData& other)
{
    m_pts = new wxVectorRealPoint();
    m_x_border = other.GetXBorder();
    for (int i = 0; i < other.GetCount(); i++)
    {
        m_pts->Add(other.GetPoint(i));
    }
}

void wxGraphData::Clear()
{
    m_pts->Clear();
    m_x_border = 0;
}

bool wxGraphData::IsEmpty() const
{
    return GetCount() == 0;
}

int wxGraphData::GetCount() const
{
    return m_pts->GetCount();
}

void wxGraphData::AddPoint(double x, double y)
{
    m_pts->Add(wxRealPoint(x, y));
}

const wxRealPoint& wxGraphData::GetPoint(int index) const
{
    return (const wxRealPoint&)m_pts->Item(index);
}

const wxRealPoint& wxGraphData::operator[](int index)
{
    return m_pts->Item(index);
}

double wxGraphData::GetXBorder() const
{
    return m_x_border;
}

bool wxGraphData::SaveToFile(const wxString& filename) const
{
    wxFile file;
    if (!file.Open(filename, wxFile::write))
    {
        return false;
    }

    bool res = file.Write(&m_x_border, sizeof(double));
    if (!res)
    {
        file.Close();
        return false;
    }

    for (int i = 0; i < GetCount(); i++)
    {
        double x = GetPoint(i).x;
        double y = GetPoint(i).y;

        res = file.Write(&x, sizeof(double));
        if (!res)
        {
            file.Close();
            return false;
        }

        res = file.Write(&y, sizeof(double));
        if (!res)
        {
            file.Close();
            return false;
        }
    }

    file.Close();
    return true;
}

bool wxGraphData::LoadFromFile(const wxString& filename)
{
    wxFile file;
    if (!file.Open(filename, wxFile::read))
    {
        return false;
    }

    bool res = file.Read(&m_x_border, sizeof(double));
    if (!res)
    {
        file.Close();
        return false;
    }

    while (!file.Eof())
        {
            double x = 0, y = 0;
            if (!(res = file.Read(&x, sizeof(double)))) break;
            if (!(res = file.Read(&y, sizeof(double)))) break;
            AddPoint(x, y);
        }

    file.Close();
    return true;
}

void wxGraphData::Generate(MATH_FUNC periodic_math_func, double x_border)
{
    m_x_border = x_border;
    double step_x = 0.01;


    for (double x = -x_border * M_PI; x <= x_border * M_PI; x += step_x)
    {
        double y1 = periodic_math_func(x);
        double y2 = periodic_math_func(x + step_x);
        this->AddPoint(x, y1);
        this->AddPoint(x + step_x, y2);
    }
}
