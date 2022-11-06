#include <wx/wx.h>

class PlotGridPanel : public wxPanel
{
public:
    PlotGridPanel(wxPanel* parent);

    void OnPaintEvent(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);

    void SetGridUnitSize(int new_size);
    int GetGridUnitSize();

    DECLARE_EVENT_TABLE()

private:
    void DrawGrid(wxDC& dc);

    wxColor m_AxesColor = wxColor(0, 0, 0);
    wxColor m_TicksColor = wxColor(0, 0, 0);
    wxColor m_GridColor = wxColor(125, 125, 125);

    int m_GridUnitSize = 20; // in pixels
};