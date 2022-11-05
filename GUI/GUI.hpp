#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/sizer.h>

class BasicDrawPane : public wxPanel
{   
public:
    BasicDrawPane(wxFrame* parent);

    void mouseDown(wxMouseEvent& event);
    void mouseReleased(wxMouseEvent& event);
    void mouseMoved(wxMouseEvent& event);
    
    void draw_dot(wxDC& dc, int x, int y);
       
    DECLARE_EVENT_TABLE()

private:
    bool m_MouseIsPressed;
};


class App: public wxApp
{
    bool OnInit();
    
    wxFrame *frame;
    BasicDrawPane * drawPane;
};