#include "PlotGrid.hpp"

PlotGridPanel::PlotGridPanel(wxPanel* parent)
    : wxPanel(parent)
{

}

void PlotGridPanel::OnPaintEvent(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    DrawGrid(dc);
}

void PlotGridPanel::OnSize(wxSizeEvent& event)
{
    Refresh();
    event.Skip(); // ???
}

void PlotGridPanel::DrawGrid(wxDC& dc)
{
    wxSize grid_size = dc.GetSize();
    int x_center = grid_size.GetWidth() / 2;
    int y_center = grid_size.GetHeight() / 2;

    const int h_offset = 10; // px
    const int v_offset = 10; // px

    dc.SetPen(wxPen(*wxLIGHT_GREY, 2));
    // draw Y axis
    dc.DrawLine(h_offset, v_offset, h_offset, grid_size.GetHeight() - 10);
    // draw X axis
    dc.DrawLine(h_offset, y_center, grid_size.GetWidth() - 10, y_center);
}

BEGIN_EVENT_TABLE(PlotGridPanel, wxPanel)
    EVT_PAINT(PlotGridPanel::OnPaintEvent)
    EVT_SIZE(PlotGridPanel::OnSize)
END_EVENT_TABLE()