/***************************************************************
 * Name:      Dual_ParabolicModelingMain.h
 * Purpose:   Defines Application Frame
 * Author:    DiegoMorenoGalvan (diego.moreno@cimat.mx)
 * Created:   2020-12-03
 * Copyright: DiegoMorenoGalvan ()
 * License:
 **************************************************************/

#ifndef DUAL_PARABOLICMODELINGMAIN_H
#define DUAL_PARABOLICMODELINGMAIN_H

//(*Headers(Dual_ParabolicModelingFrame)
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/statline.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class Dual_ParabolicModelingFrame: public wxFrame
{
    public:

        Dual_ParabolicModelingFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Dual_ParabolicModelingFrame();

    private:

        //(*Handlers(Dual_ParabolicModelingFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnPanel2Paint(wxPaintEvent& event);
        void OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event);
        void OnFilePickerCtrl2FileChanged(wxFileDirPickerEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(Dual_ParabolicModelingFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long ID_FILEPICKERCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_FILEPICKERCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_PANEL2;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON3;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Dual_ParabolicModelingFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxStaticText* StaticText1;
        wxPanel* Panel2;
        wxStaticText* StaticText3;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText2;
        wxFilePickerCtrl* FilePickerCtrl1;
        wxFilePickerCtrl* FilePickerCtrl2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DUAL_PARABOLICMODELINGMAIN_H
