#include "GUI.hpp"
#include <Eigen/Dense>

bool App::OnInit()
{
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Hello wxDC"), wxPoint(50,50), wxSize(800,600));
	
    drawPane = new BasicDrawPane( (wxFrame*) frame );
    sizer->Add(drawPane, 1, wxEXPAND);
	
    frame->SetSizer(sizer);
    frame->SetAutoLayout(true);
	
    frame->Show();
    return true;
} 

BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
// some useful events
/*
 EVT_MOTION(BasicDrawPane::mouseMoved)
 EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
 EVT_LEFT_UP(BasicDrawPane::mouseReleased)
 EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
 EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
 EVT_KEY_DOWN(BasicDrawPane::keyPressed)
 EVT_KEY_UP(BasicDrawPane::keyReleased)
 EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
 */

// catch paint events
// EVT_PAINT(BasicDrawPane::paintEvent)
EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
EVT_LEFT_UP(BasicDrawPane::mouseReleased)
EVT_MOTION(BasicDrawPane::mouseMoved)

EVT_PAINT(BasicDrawPane::paintEvent)

END_EVENT_TABLE()


// some useful events
/*
 void BasicDrawPane::mouseMoved(wxMouseEvent& event) {}
 void BasicDrawPane::mouseDown(wxMouseEvent& event) {}
 void BasicDrawPane::mouseWheelMoved(wxMouseEvent& event) {}
 void BasicDrawPane::mouseReleased(wxMouseEvent& event) {}
 void BasicDrawPane::rightClick(wxMouseEvent& event) {}
 void BasicDrawPane::mouseLeftWindow(wxMouseEvent& event) {}
 void BasicDrawPane::keyPressed(wxKeyEvent& event) {}
 void BasicDrawPane::keyReleased(wxKeyEvent& event) {}
 */

BasicDrawPane::BasicDrawPane(wxFrame* parent) :
    wxPanel(parent),
    m_MouseIsPressed(false)
{
}

void BasicDrawPane::mouseDown(wxMouseEvent& event)
{
    wxClientDC dc(this);
    draw_dot(dc, event.GetX(), event.GetY());
    m_MouseIsPressed = true;
}

void BasicDrawPane::mouseReleased(wxMouseEvent& event)
{
    m_MouseIsPressed = false;
}

void BasicDrawPane::mouseMoved(wxMouseEvent& event)
{
    if (!m_MouseIsPressed)
        return;

    wxClientDC dc(this);
    draw_dot(dc, event.GetX(), event.GetY());
}

void BasicDrawPane::draw_dot(wxDC&  dc, int x, int y)
{
    dc.SetBrush(*wxBLACK_BRUSH); // black filling
    dc.SetPen( wxPen( wxColor(0,0,0), 1 ) ); // 1-pixels-thick black outline
    dc.DrawCircle( wxPoint(x, y), 2 /* radius */ );
}

void BasicDrawPane::paintEvent(wxPaintEvent & evt)
{
    // depending on your system you may need to look at double-buffered dcs
    wxPaintDC dc(this);
    render(dc);
}

void BasicDrawPane::render(wxDC& dc)
{
    wxSize window_size = dc.GetSize();
    int x_offset = window_size.GetWidth() / 2;
    int y_offset = window_size.GetHeight() / 2;

    dc.SetPen(wxPen(*wxLIGHT_GREY, 1));
    dc.DrawLine(0, y_offset, window_size.GetWidth(), y_offset);

    const auto linspace = Eigen::VectorXf::LinSpaced(100, 0, 3.1415*2);
    auto sin_values = linspace.array().sin();
    for (int i = 0; i < linspace.size(); i++)
    {
        draw_dot(dc, (int)(linspace[i] / (3.1415*2) * window_size.GetWidth()), (int)(100*sin_values[i]) + y_offset);
    }
}