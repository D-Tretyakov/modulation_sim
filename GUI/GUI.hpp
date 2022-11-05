#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/sizer.h>

class BasicDrawPane : public wxPanel
{
    
public:
    BasicDrawPane(wxFrame* parent);
    
    void paintEvent(wxPaintEvent & evt);
    void paintNow();

    void mouseDown(wxMouseEvent& event);
    
    void render(wxDC& dc);
    void draw_dot(wxDC& dc, int x, int y);
       
    DECLARE_EVENT_TABLE()
};


class App: public wxApp
{
    bool OnInit();
    
    wxFrame *frame;
    BasicDrawPane * drawPane;
};