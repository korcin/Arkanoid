#ifndef ARKANOID_H
#define ARKANOID_H

//(*Headers(Arkanoid)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statbmp.h>
#include <wx/timer.h>
//*)

class Arkanoid: public wxFrame
{
    public:
        int x,y,x1,y1,w,h;

        int block1_x,block2_x,block3_x,block1_y,block2_y,block3_y;
        bool block1,block2,block3;


        Arkanoid(wxWindow* parent,wxWindowID id = -1);


        virtual ~Arkanoid();
        void OnKeyDown(wxKeyEvent& event);
    private:
        static const long ID_key;
        //(*Handlers(Arkanoid)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnTimer2Trigger(wxTimerEvent& event);
        //*)

        //(*Identifiers(Arkanoid)
        static const long ID_STATICBITMAP1;
        static const long ID_STATICBITMAP2;
        static const long ID_STATICBITMAP3;
        static const long ID_STATICBITMAP4;
        static const long ID_STATICBITMAP5;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(Arkanoid)
        wxMenu* Menu1;
        wxMenu* Menu2;
        wxMenuBar* MenuBar1;
        wxStaticBitmap* StaticBitmap1;
        wxStaticBitmap* StaticBitmap2;
        wxStaticBitmap* StaticBitmap3;
        wxStaticBitmap* StaticBitmap4;
        wxStaticBitmap* StaticBitmap5;
        wxTimer Timer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ARKANOID
