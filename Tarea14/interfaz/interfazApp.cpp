/***************************************************************
 * Name:      interfazApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DiegoMoreno ()
 * Created:   2020-11-27
 * Copyright: DiegoMoreno ()
 * License:
 **************************************************************/

#include "interfazApp.h"

//(*AppHeaders
#include "interfazMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(interfazApp);

bool interfazApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	interfazFrame* Frame = new interfazFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
        