#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/sizer.h>

#include "PlotGrid/PlotGrid.hpp"

class App: public wxApp
{
    bool OnInit();
    
    wxFrame* frame;
    wxPanel* main_panel;
    PlotGridPanel* grid;
};