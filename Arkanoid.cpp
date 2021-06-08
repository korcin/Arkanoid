#include "Arkanoid.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Arkanoid)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Arkanoid)
const long Arkanoid::ID_STATICBITMAP1 = wxNewId();
const long Arkanoid::ID_STATICBITMAP2 = wxNewId();
const long Arkanoid::ID_STATICBITMAP3 = wxNewId();
const long Arkanoid::ID_STATICBITMAP4 = wxNewId();
const long Arkanoid::ID_STATICBITMAP5 = wxNewId();
const long Arkanoid::idMenuQuit = wxNewId();
const long Arkanoid::idMenuAbout = wxNewId();
const long Arkanoid::ID_TIMER1 = wxNewId();
//*)
const long Arkanoid::ID_key = wxNewId();

BEGIN_EVENT_TABLE(Arkanoid,wxFrame)
    //(*EventTable(Arkanoid)
    //*)
END_EVENT_TABLE()

Arkanoid::Arkanoid(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Arkanoid)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,400));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("D:\\STUDIA\\Studia III semestr\\Programowanie w C++\\Arkanoid\\images\\paddle.png")).Rescale(wxSize(100,10).GetWidth(),wxSize(100,10).GetHeight())), wxPoint(150,300), wxSize(100,10), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    StaticBitmap2 = new wxStaticBitmap(this, ID_STATICBITMAP2, wxBitmap(wxImage(_T("D:\\STUDIA\\Studia III semestr\\Programowanie w C++\\Arkanoid\\images\\ball.png")).Rescale(wxSize(20,20).GetWidth(),wxSize(20,20).GetHeight())), wxPoint(192,248), wxSize(20,20), wxSIMPLE_BORDER, _T("ID_STATICBITMAP2"));
    StaticBitmap2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));
    StaticBitmap2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));
    StaticBitmap3 = new wxStaticBitmap(this, ID_STATICBITMAP3, wxBitmap(wxImage(_T("D:\\STUDIA\\Studia III semestr\\Programowanie w C++\\Arkanoid\\images\\block01.png")).Rescale(wxSize(60,30).GetWidth(),wxSize(60,30).GetHeight())), wxPoint(72,16), wxSize(60,30), wxSIMPLE_BORDER, _T("ID_STATICBITMAP3"));
    StaticBitmap4 = new wxStaticBitmap(this, ID_STATICBITMAP4, wxBitmap(wxImage(_T("D:\\STUDIA\\Studia III semestr\\Programowanie w C++\\Arkanoid\\images\\block01.png")).Rescale(wxSize(60,30).GetWidth(),wxSize(60,30).GetHeight())), wxPoint(152,16), wxSize(60,30), wxSIMPLE_BORDER, _T("ID_STATICBITMAP4"));
    StaticBitmap5 = new wxStaticBitmap(this, ID_STATICBITMAP5, wxBitmap(wxImage(_T("D:\\STUDIA\\Studia III semestr\\Programowanie w C++\\Arkanoid\\images\\block01.png")).Rescale(wxSize(60,30).GetWidth(),wxSize(60,30).GetHeight())), wxPoint(232,16), wxSize(60,30), wxSIMPLE_BORDER, _T("ID_STATICBITMAP5"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(11, false);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Arkanoid::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Arkanoid::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&Arkanoid::OnTimer1Trigger);
    //*)
    Connect(wxEVT_CHAR, wxKeyEventHandler(Arkanoid::OnKeyDown));
    w=0;
    h=0;
    x=1;
    y=1;
    x1=150;
    y1=300;
    block1_x=72;
    block1_y=16;
    block2_x=152;
    block2_y=16;
    block3_x=232;
    block3_y=16;
    block1=true;
    block2=true;
    block3=true;
}

Arkanoid::~Arkanoid()
{
    //(*Destroy(Arkanoid)
    //*)
}

void Arkanoid::OnQuit(wxCommandEvent& event)
{

    Close();
}

void Arkanoid::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Arkanoid::OnTimer1Trigger(wxTimerEvent& event)
{

    w+=x;
    h+=y;

    //Block(Hit)
    if(h>=16&&h<46&&w>=232&&w<232+60&&block3==true){
            y= -y;
            block3=false;
            delete StaticBitmap5;
    }
    if(h>=16&&h<46&&w>=152&&w<152+60&&block2==true){
            y= -y;
            block2=false;
            delete StaticBitmap4;
    }
     if(h>=16&&h<46&&w>=72&&w<72+60&&block1==true){
            y= -y;
            block1=false;
            delete StaticBitmap3;
    }

    if(h>280&&h<300&&w>x1&&w<x1+100) y = -y;
    if(w==390) x = -x;
    if(w==0)    x =  -x;
    if(h==0)  y = -y;
    if(h>400)
    {
        Timer1.Stop();
        wxMessageBox("You lost", _("Welcome to..."));
    }
    wxPoint new_point(w,h);
    StaticBitmap2->Move(new_point);
    if(block1==false&&block2==false&&block3==false)
         {
        Timer1.Stop();
        wxMessageBox("You Win!!", _("Welcome to..."));
    }

}

void Arkanoid::OnKeyDown(wxKeyEvent& event)
{

   //wxMessageBox(wxString::Format("KeyDown: %i\n", (int)event.GetKeyCode()));
   if((int)event.GetKeyCode()==314&&x1>0){
      x1-=7;
       wxPoint new_k(x1,y1);
    StaticBitmap1->Move(new_k);
    event.Skip();
   }
    if((int)event.GetKeyCode()==316&&x1<300){
      x1+=7;
       wxPoint new_k(x1,y1);
    StaticBitmap1->Move(new_k);
    event.Skip();
   }

}
