#include "GUI.hpp"

bool App::OnInit()
{
    wxBoxSizer* frame_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* main_panel_sizer = new wxBoxSizer(wxHORIZONTAL);

    frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Hello wxDC"), wxPoint(50,50), wxSize(800,600));
    main_panel = new wxPanel(frame);
    grid = new PlotGridPanel(main_panel);

    main_panel_sizer->Add(grid, 1, wxEXPAND);
    main_panel->SetSizer(main_panel_sizer);

    frame_sizer->Add(main_panel, 1, wxEXPAND);
	
    frame->SetSizer(frame_sizer);
    frame->SetAutoLayout(true);
	
    frame->Show();
    return true;
}
