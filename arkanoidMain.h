/***************************************************************
 * Name:      arkanoidMain.h
 * Purpose:   Defines Application Frame
 * Author:    Marcin Kozera, Patryk Kożuchowski ()
 * Created:   2020-12-28
 * Copyright: Marcin Kozera, Patryk Kożuchowski ()
 * License:
 **************************************************************/

#ifndef ARKANOIDMAIN_H
#define ARKANOIDMAIN_H

//(*Headers(arkanoidFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

class arkanoidFrame: public wxFrame
{
    public:

        arkanoidFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~arkanoidFrame();

    private:

        //(*Handlers(arkanoidFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        //*)

        //(*Identifiers(arkanoidFrame)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(arkanoidFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ARKANOIDMAIN_H
