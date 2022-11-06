#include <wx/wx.h>

class PlotGridPanel : public wxPanel
{
public:
    PlotGridPanel(wxPanel* parent);

    void OnPaintEvent(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);

    DECLARE_EVENT_TABLE()

private:
    void DrawGrid(wxDC& dc);
};