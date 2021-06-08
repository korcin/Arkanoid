#include "gra1.h" //Zalaczenie okna dialogowego
#include "Arkanoid.h" //Zalaczenie okna dialogowego
#include <wx/msgdlg.h>
#include <iostream>
#include <wx/textfile.h>
#include <wx/txtstrm.h>
#include <wx/wfstream.h>
#include <wx/stattext.h>
#include <wx/filedlg.h>
#include <wx/log.h>

//(*InternalHeaders(gra1)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(gra1)
const long gra1::ID_STATICTEXT1 = wxNewId();
const long gra1::ID_TEXTCTRL1 = wxNewId();
const long gra1::ID_BUTTON1 = wxNewId();
const long gra1::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(gra1,wxDialog)
	//(*EventTable(gra1)
	//*)
END_EVENT_TABLE()

gra1::gra1(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(gra1)
	Create(parent, id, _("Arkanoid"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(650,800));
	Move(wxPoint(500,100));
	SetBackgroundColour(wxColour(0,0,0));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Podaj swoja nazwe gracza:"), wxPoint(152,208), wxSize(160,40), 0, _T("ID_STATICTEXT1"));
	StaticText1->SetForegroundColour(wxColour(255,0,0));
	wxFont StaticText1Font(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(208,288), wxSize(208,40), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->SetForegroundColour(wxColour(0,255,0));
	TextCtrl1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
	wxFont TextCtrl1Font(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	TextCtrl1->SetFont(TextCtrl1Font);
	Button1 = new wxButton(this, ID_BUTTON1, _("ZACZYNAMY"), wxPoint(200,400), wxSize(224,56), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetForegroundColour(wxColour(0,0,255));
	Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
	wxFont Button1Font(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	Button2 = new wxButton(this, ID_BUTTON2, _("POWROT"), wxPoint(235,520), wxSize(150,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetForegroundColour(wxColour(0,0,255));
	Button2->SetBackgroundColour(wxColour(0,0,0));
	wxFont Button2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button2->SetFont(Button2Font);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&gra1::OnTextCtrl1Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gra1::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gra1::OnButton2Click);
	//*)
}

gra1::~gra1()
{
	//(*Destroy(gra1)
	//*)
}


void gra1::OnTextCtrl1Text(wxCommandEvent& event)
{

}

void gra1::OnButton1Click(wxCommandEvent& event)
{
    //Zapisywanie nazwy gracza do liku tekstowego

     wxString data = TextCtrl1 -> GetValue();
     wxFileDialog dlg(this, ("Zapisz plik txt"), "", "", "Plik TXT (*.txt)|*.txt", wxFD_SAVE);

    if (dlg.ShowModal() == wxID_OK){
       wxFile file( dlg.GetPath(), wxFile::write );
       if(file.IsOpened()){
            file.Write(data);
            file.Close();
       }
    }

    //Otwieranie nowego okna z gra

    Arkanoid* Frame = new Arkanoid(NULL, 1);
    Frame->Show();

    /*gra3 dialog(this);
    dialog.ShowModal();*/
}

void gra1::OnButton2Click(wxCommandEvent& event) //Wyjœcie do poprzedniego okna dialogowego
{
    Close();
}
