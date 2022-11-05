#include "GUI.hpp"

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