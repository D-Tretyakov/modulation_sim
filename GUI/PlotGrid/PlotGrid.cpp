#include "PlotGrid.hpp"
#include <iostream>

PlotGridPanel::PlotGridPanel(wxPanel* parent)
    : wxPanel(parent)
{

}

void PlotGridPanel::SetGridUnitSize(int new_size)
{
    m_GridUnitSize = new_size;
}

int PlotGridPanel::GetGridUnitSize()
{
    return m_GridUnitSize;
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
    const wxSize grid_size = dc.GetSize();
    const int grid_width = grid_size.GetWidth();
    const int grid_height = grid_size.GetHeight();

    const int h_offset = 10; // px
    const int v_offset = 10; // px
    const int tick_size = 6; // px - length of tick  

    dc.SetPen(wxPen(m_AxesColor, 2));
    // draw Y axis
    dc.DrawLine(h_offset, v_offset, h_offset, grid_height - v_offset);
    // draw X axis
    dc.DrawLine(h_offset, grid_height / 2, grid_width - h_offset, grid_height / 2);

    // draw grid and ticks on axes
    // draw ticks from y = 0 to bottom
    for (int i = grid_height / 2 + m_GridUnitSize; i < (grid_height - v_offset); i += m_GridUnitSize)
    {
        // draw tick
        dc.SetPen(wxPen(m_TicksColor, 1));
        dc.DrawLine(h_offset - tick_size / 2, i, h_offset + tick_size / 2, i);
        // draw grid line
        dc.SetPen(wxPen(m_GridColor, 1));
        dc.DrawLine(h_offset, i, grid_width - h_offset, i);
    }
    // draw ticks from y = 0 to top
    for (int i = grid_height / 2 - m_GridUnitSize; i > v_offset; i -= m_GridUnitSize)
    {
        // draw tick
        dc.SetPen(wxPen(m_TicksColor, 1));
        dc.DrawLine(h_offset - tick_size / 2, i, h_offset + tick_size / 2, i);
        // draw grid line
        dc.SetPen(wxPen(m_GridColor, 1));
        dc.DrawLine(h_offset, i, grid_width - h_offset, i);
    }
    // draw ticks for X axis
    for (int i = h_offset + m_GridUnitSize; i < (grid_width - h_offset); i += m_GridUnitSize)
    {
        // draw tick
        dc.SetPen(wxPen(m_TicksColor, 1));
        dc.DrawLine(i, grid_height / 2 - tick_size / 2, i, grid_height / 2 + tick_size / 2);
        // draw grid line
        dc.SetPen(wxPen(m_GridColor, 1));
        dc.DrawLine(i, v_offset, i, grid_height - v_offset);
    }
}

BEGIN_EVENT_TABLE(PlotGridPanel, wxPanel)
    EVT_PAINT(PlotGridPanel::OnPaintEvent)
    EVT_SIZE(PlotGridPanel::OnSize)
END_EVENT_TABLE()