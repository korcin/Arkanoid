/***************************************************************
 * Name:      arkanoidApp.h
 * Purpose:   Defines Application Class
 * Author:    Marcin Kozera, Patryk Kożuchowski ()
 * Created:   2020-12-28
 * Copyright: Marcin Kozera, Patryk Kożuchowski ()
 * License:
 **************************************************************/

#ifndef ARKANOIDAPP_H
#define ARKANOIDAPP_H

#include <wx/app.h>

class arkanoidApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // ARKANOIDAPP_H
