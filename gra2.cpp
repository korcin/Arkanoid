#include "gra2.h" //Za³¹czenie okna dialogowego
#include <wx/msgdlg.h>
#include <iostream>
#include <wx/textfile.h>
#include <wx/txtstrm.h>
#include <wx/wfstream.h>
#include <wx/stattext.h>
#include <wx/filedlg.h>
#include <wx/log.h>


//(*InternalHeaders(gra2)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(gra2)
const long gra2::ID_STATICTEXT1 = wxNewId();
const long gra2::ID_TEXTCTRL1 = wxNewId();
const long gra2::ID_BUTTON1 = wxNewId();
const long gra2::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(gra2,wxDialog)
	//(*EventTable(gra2)
	//*)
END_EVENT_TABLE()

gra2::gra2(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(gra2)
	Create(parent, wxID_ANY, _("Ranking"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(650,800));
	Move(wxPoint(500,100));
	SetBackgroundColour(wxColour(0,0,0));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Ranking graczy"), wxPoint(224,72), wxSize(248,48), 0, _T("ID_STATICTEXT1"));
	StaticText1->SetForegroundColour(wxColour(255,0,0));
	wxFont StaticText1Font(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(208,136), wxSize(224,248), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->SetForegroundColour(wxColour(0,255,0));
	TextCtrl1->SetBackgroundColour(wxColour(0,0,0));
	wxFont TextCtrl1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	TextCtrl1->SetFont(TextCtrl1Font);
	Button1 = new wxButton(this, ID_BUTTON1, _("POWROT"), wxPoint(240,464), wxSize(168,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetForegroundColour(wxColour(0,0,255));
	Button1->SetBackgroundColour(wxColour(0,0,0));
	wxFont Button1Font(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	Button2 = new wxButton(this, ID_BUTTON2, _("POKAZ"), wxPoint(240,405), wxSize(168,40), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetForegroundColour(wxColour(0,255,0));
	Button2->SetBackgroundColour(wxColour(0,0,0));
	wxFont Button2Font(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	Button2->SetFont(Button2Font);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&gra2::OnTextCtrl1Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gra2::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gra2::OnButton2Click);
	//*)
}

gra2::~gra2()
{
	//(*Destroy(gra2)
	//*)
}


void gra2::OnButton1Click(wxCommandEvent& event)
{
    Close();
}

void gra2::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void gra2::OnButton2Click(wxCommandEvent& event)
{
    //Odczytywanie pliku tekstowego

    wxFileDialog fdlog(this);
    wxString file;

    if(fdlog.ShowModal() != wxID_OK) return;
    file.Clear();
    file = fdlog.GetPath();
    TextCtrl1 -> Clear();
    wxFileInputStream input(file);
    wxTextInputStream text(input, file, wxConvUTF8 );
    while(input.IsOk() && !input.Eof() )
    {
        wxString line=text.ReadLine();
        TextCtrl1 -> WriteText(line + "\n");
    }
}
