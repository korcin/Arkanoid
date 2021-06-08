/***************************************************************
 * Name:      arkanoidMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Marcin Kozera, Patryk Kożuchowski ()
 * Created:   2020-12-28
 * Copyright: Marcin Kozera, Patryk Kożuchowski ()
 * License:
 **************************************************************/

#include "arkanoidMain.h"
#include <wx/msgdlg.h>
#include <iostream>
#include <wx/textfile.h>
#include <wx/txtstrm.h>
#include <wx/wfstream.h>
#include <wx/stattext.h>
#include <wx/filedlg.h>
#include <wx/log.h>
#include "gra1.h" //Załączenie okna dialogowego
#include "gra2.h" //Załączenie okna dialogowego

//(*InternalHeaders(arkanoidFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(arkanoidFrame)
const long arkanoidFrame::ID_STATICTEXT1 = wxNewId();
const long arkanoidFrame::ID_BUTTON1 = wxNewId();
const long arkanoidFrame::ID_BUTTON2 = wxNewId();
const long arkanoidFrame::ID_BUTTON3 = wxNewId();
const long arkanoidFrame::ID_STATICTEXT2 = wxNewId();
const long arkanoidFrame::idMenuQuit = wxNewId();
const long arkanoidFrame::idMenuAbout = wxNewId();
const long arkanoidFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(arkanoidFrame,wxFrame)
    //(*EventTable(arkanoidFrame)
    //*)
END_EVENT_TABLE()

arkanoidFrame::arkanoidFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(arkanoidFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Arkanoid"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(650,800));
    Move(wxPoint(500,100));
    SetBackgroundColour(wxColour(0,0,0));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ARKANOID!"), wxPoint(200,0), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColour(255,0,0));
    wxFont StaticText1Font(30,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial Rounded MT Bold"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    Button1 = new wxButton(this, ID_BUTTON1, _("GRA"), wxPoint(255,175), wxSize(120,32), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetForegroundColour(wxColour(255,0,0));
    Button1->SetBackgroundColour(wxColour(0,0,0));
    wxFont Button1Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    Button2 = new wxButton(this, ID_BUTTON2, _("RANKING"), wxPoint(255,255), wxSize(120,32), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetForegroundColour(wxColour(0,128,0));
    Button2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont Button2Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Button2->SetFont(Button2Font);
    Button3 = new wxButton(this, ID_BUTTON3, _("WYJDZ Z GRY"), wxPoint(200,335), wxSize(240,32), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->SetForegroundColour(wxColour(0,0,255));
    Button3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont Button3Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button3->SetFont(Button3Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Autorzy:\nMarcin Kozera\nPatryk Kozuchowski"), wxPoint(8,664), wxSize(183,54), 0, _T("ID_STATICTEXT2"));
    StaticText2->SetForegroundColour(wxColour(255,0,0));
    StaticText2->SetBackgroundColour(wxColour(0,0,0));
    wxFont StaticText2Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
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
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&arkanoidFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&arkanoidFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&arkanoidFrame::OnButton3Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&arkanoidFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&arkanoidFrame::OnAbout);
    //*)
}

arkanoidFrame::~arkanoidFrame()
{
    //(*Destroy(arkanoidFrame)
    //*)
}

void arkanoidFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void arkanoidFrame::OnAbout(wxCommandEvent& event)
{
//    wxString msg = wxbuildinfo(long_f);
//    wxMessageBox(msg, _("Welcome to..."));
}

void arkanoidFrame::OnButton1Click(wxCommandEvent& event) //Otiweranie nowego okna z grą
{
    gra1 dialog(this);
    dialog.ShowModal();
}

void arkanoidFrame::OnButton2Click(wxCommandEvent& event) //Otwieranie nowego okna z rankingiem
{
    gra2 dialog(this);
    dialog.ShowModal();
}

void arkanoidFrame::OnButton3Click(wxCommandEvent& event) //Wyjście z gry
{
    int odp = wxMessageBox("Czy na pewno chcesz wyjsc z gry?",
                           "Wyjscie z gry", wxYES_NO);
    if(odp == wxYES) Close();
    if(odp == wxNO) odp = wxMessageBox("Swietnie, gramy dalej!",
                                      "Wyjscie z gry", wxOK);
}
