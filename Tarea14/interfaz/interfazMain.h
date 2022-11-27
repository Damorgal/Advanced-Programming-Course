/***************************************************************
 * Name:      interfazMain.h
 * Purpose:   Defines Application Frame
 * Author:    DiegoMoreno ()
 * Created:   2020-11-27
 * Copyright: DiegoMoreno ()
 * License:
 **************************************************************/

#ifndef INTERFAZMAIN_H
#define INTERFAZMAIN_H

//(*Headers(interfazFrame)
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/statline.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class interfazFrame: public wxFrame
{
    public:

        interfazFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~interfazFrame();

    private:

        //(*Handlers(interfazFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnTextCtrl4Text(wxCommandEvent& event);
        void OnTextCtrlCapasText(wxCommandEvent& event);
        void OnTextCtrlTamagnosText(wxCommandEvent& event);
        void OnTextCtrlEpocasText(wxCommandEvent& event);
        void OnTextCtrlRazonText(wxCommandEvent& event);
        void OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        //*)

        //(*Identifiers(interfazFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long ID_FILEPICKERCTRL1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_PANEL2;
        static const long ID_STATICLINE1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(interfazFrame)
        wxTextCtrl* TextCtrl3;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxButton* Button2;
        wxStaticText* StaticText1;
        wxPanel* Panel2;
        wxStaticText* StaticText3;
        wxStaticLine* StaticLine1;
        wxTextCtrl* TextCtrl1;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxFilePickerCtrl* FilePickerCtrl1;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // INTERFAZMAIN_H
