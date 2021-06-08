/***************************************************************
 * Name:      arkanoidApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Marcin Kozera, Patryk Kożuchowski ()
 * Created:   2020-12-28
 * Copyright: Marcin Kozera, Patryk Kożuchowski ()
 * License:
 **************************************************************/

#include "arkanoidApp.h"

//(*AppHeaders
#include "arkanoidMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(arkanoidApp);

bool arkanoidApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	arkanoidFrame* Frame = new arkanoidFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
