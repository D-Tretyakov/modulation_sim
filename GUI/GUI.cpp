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
EVT_PAINT(BasicDrawPane::paintEvent)
EVT_LEFT_DOWN(BasicDrawPane::mouseDown)

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
    wxPanel(parent)
{
}

void BasicDrawPane::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void BasicDrawPane::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void BasicDrawPane::mouseDown(wxMouseEvent& event)
{
    wxClientDC dc(this);
    draw_dot(dc, event.GetX(), event.GetY());
}


void BasicDrawPane::render(wxDC&  dc)
{
    // // draw some text
    // dc.DrawText(wxT("Testing"), 40, 60); 
    
    // // draw a circle
    // dc.SetBrush(*wxGREEN_BRUSH); // green filling
    // dc.SetPen( wxPen( wxColor(255,0,0), 5 ) ); // 5-pixels-thick red outline
    // dc.DrawCircle( wxPoint(200,100), 25 /* radius */ );
    
    // // draw a rectangle
    // dc.SetBrush(*wxBLUE_BRUSH); // blue filling
    // dc.SetPen( wxPen( wxColor(255,175,175), 10 ) ); // 10-pixels-thick pink outline
    // dc.DrawRectangle( 300, 100, 400, 200 );
    
    // // draw a line
    // dc.SetPen( wxPen( wxColor(0,0,0), 3 ) ); // black line, 3 pixels thick
    // dc.DrawLine( 300, 100, 700, 300 ); // draw line across the rectangle
    
    // // Look at the wxDC docs to learn how to draw other stuff
}

void BasicDrawPane::draw_dot(wxDC&  dc, int x, int y)
{
    dc.SetBrush(*wxBLACK_BRUSH); // black filling
    dc.SetPen( wxPen( wxColor(0,0,0), 1 ) ); // 1-pixels-thick black outline
    dc.DrawCircle( wxPoint(x, y), 2 /* radius */ );
}