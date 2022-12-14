/***************************************************************
 * Name:      Dual_ParabolicModelingApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DiegoMorenoGalvan (diego.moreno@cimat.mx)
 * Created:   2020-12-03
 * Copyright: DiegoMorenoGalvan ()
 * License:
 **************************************************************/

#include "Dual_ParabolicModelingApp.h"

//(*AppHeaders
#include "Dual_ParabolicModelingMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Dual_ParabolicModelingApp);

bool Dual_ParabolicModelingApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Dual_ParabolicModelingFrame* Frame = new Dual_ParabolicModelingFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
        