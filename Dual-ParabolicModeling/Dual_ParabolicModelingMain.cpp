/***************************************************************
 * Name:      Dual_ParabolicModelingMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    DiegoMorenoGalvan (diego.moreno@cimat.mx)
 * Created:   2020-12-03
 * Copyright: DiegoMorenoGalvan ()
 * License:
 **************************************************************/

#include "Dual_ParabolicModelingMain.h"
#include <wx/msgdlg.h>
#include <wx/cshelp.h>
#include <wx/dcclient.h>
#include <wx/settings.h>
#include <wx/filepicker.h>

//(*InternalHeaders(Dual_ParabolicModelingFrame)
#include <wx/string.h>
#include <wx/intl.h>
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

//(*IdInit(Dual_ParabolicModelingFrame)
const long Dual_ParabolicModelingFrame::ID_BUTTON1 = wxNewId();
const long Dual_ParabolicModelingFrame::ID_BUTTON2 = wxNewId();
const long Dual_ParabolicModelingFrame::ID_PANEL1 = wxNewId();
const long Dual_ParabolicModelingFrame::ID_FILEPICKERCTRL1 = wxNewId();
const long Dual_ParabolicModelingFrame::ID_STATICTEXT1 = wxNewId();
const long Dual_ParabolicModelingFrame::ID_STATICTEXT2 = wxNewId();
const long Dual_ParabolicModelingFrame::ID_FILEPICKERCTRL2 = wxNewId();
const long Dual_ParabolicModelingFrame::ID_STATICTEXT3 = wxNewId();
const long Dual_ParabolicModelingFrame::ID_PANEL2 = wxNewId();
const long Dual_ParabolicModelingFrame::ID_STATICLINE1 = wxNewId();
const long Dual_ParabolicModelingFrame::ID_BUTTON3 = wxNewId();
const long Dual_ParabolicModelingFrame::idMenuQuit = wxNewId();
const long Dual_ParabolicModelingFrame::idMenuAbout = wxNewId();
const long Dual_ParabolicModelingFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Dual_ParabolicModelingFrame,wxFrame)
    //(*EventTable(Dual_ParabolicModelingFrame)
    //*)
END_EVENT_TABLE()

Dual_ParabolicModelingFrame::Dual_ParabolicModelingFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Dual_ParabolicModelingFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(860,505));
    Button1 = new wxButton(this, ID_BUTTON1, _("Determinar"), wxPoint(650,250), wxSize(164,30), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Rotar 180"), wxPoint(650,218), wxSize(164,30), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(10,10), wxSize(600,400), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FilePickerCtrl1 = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, wxEmptyString, wxEmptyString, wxPoint(650,35), wxSize(172,30), wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    FilePickerCtrl1->SetHelpText(_("Seleccionar imagen a cargar"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Imagen a determinar:"), wxPoint(650,10), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Imagen de prueba:"), wxPoint(650,70), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FilePickerCtrl2 = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL2, wxEmptyString, wxEmptyString, wxEmptyString, wxPoint(650,95), wxSize(172,30), wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Para continuar, se debe \nrotar la imagen para que\nabra hacia la derecha y \nobtener los resultados.\n"), wxPoint(636,128), wxSize(216,88), 0, _T("ID_STATICTEXT3"));
    Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(620,284), wxSize(232,97), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(10,410), wxSize(784,16), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    Button3 = new wxButton(this, ID_BUTTON3, _("Guardar"), wxPoint(650,385), wxSize(164,30), 0, wxDefaultValidator, _T("ID_BUTTON3"));
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Dual_ParabolicModelingFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Dual_ParabolicModelingFrame::OnButton2Click);
    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Dual_ParabolicModelingFrame::OnPanel1Paint,0,this);
    Connect(ID_FILEPICKERCTRL1,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&Dual_ParabolicModelingFrame::OnFilePickerCtrl1FileChanged);
    Connect(ID_FILEPICKERCTRL2,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&Dual_ParabolicModelingFrame::OnFilePickerCtrl2FileChanged);
    Panel2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Dual_ParabolicModelingFrame::OnPanel2Paint,0,this);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Dual_ParabolicModelingFrame::OnButton3Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Dual_ParabolicModelingFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Dual_ParabolicModelingFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Dual_ParabolicModelingFrame::OnClose);
    //*)
}

/********************* Funciones de utilidad ************************/
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stack>
#include <utility>
#include <cmath>

using namespace std;

//Regresa vector equiespaciado de x a y
vector<double> linspace(double x, double y)   {
    vector<double> pts;
    double dist = (y-x-1)/100.;
    for(int i=0; i<100; i++)    {
        pts.push_back(x + (double)i*dist);
    }
    return pts;
}

//Regresa posición mayor o igual que x
int find_val(vector<double> vec, double x)  {
    int a=0, b=vec.size()-1;
    while(1)    {
        if(a == b)
            return a;
        if(a == b-1)    {
            if(vec[a] < x)
                return b;
            else
                return a;
        }
        int mid = (a+b)>>1;
        if(vec[mid] < x)
            a = mid;
        else if(vec[mid] > x)
            b = mid;
        else
            return mid;
    }
}

double norm(pair<int,int> p1, pair<int,int> p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) +\
                (p1.second-p2.second)*(p1.second-p2.second));
}

/********************* Clase Dual-Parabolic *************************/

class dualParabolic {
private:
    wxImage ita, sta, ref_ita, ref_sta;
    double MDCP1, MDCP2;
    double p1, p2;
    double phi1, phi2;
    int x1, y1, x2, y2;
    double tiempo;
public:
    dualParabolic(wxImage &img, wxImage &ref_img);
    ~dualParabolic()            {}
    void set_MDCP1(double val)  {MDCP1 = val;}
    void set_MDCP2(double val)  {MDCP2 = val;}
    double get_MDCP1()          {return MDCP1;}
    double get_MDCP2()          {return MDCP2;}
    void set_p1(double val)     {p1 = val;}
    void set_p2(double val)     {p2 = val;}
    double get_p1()             {return p1;}
    double get_p2()             {return p2;}
    void set_phi1(double val)   {phi1 = val;}
    void set_phi2(double val)   {phi2 = val;}
    double get_phi1()           {return phi1;}
    double get_phi2()           {return phi2;}
    void set_x1(int val)        {x1 = val;}
    void set_x2(int val)        {x2 = val;}
    int get_x1()                {return x1;}
    int get_x2()                {return x2;}
    void set_y1(int val)        {y1 = val;}
    void set_y2(int val)        {y2 = val;}
    int get_y1()                {return y1;}
    int get_y2()                {return y2;}
    void set_time(double val)   {tiempo = val;}
    double get_time()           {return tiempo;}
    pair<double,double> determine(int x0, int y0, int pmin, int pmax, bool isSTA);
    double MDCP(int x0, int y0, double phi, double p, bool isSTA);
    wxImage draw_parabola(wxImage &img);
    pair<double,double> houghParabola(vector<vector<bool>> img,\
                                      vector<pair<int,int>> pos,\
                                      int cx, int cy,\
                                      int pmin, int pmax);
};

dualParabolic::dualParabolic(wxImage &img, wxImage &ref_img)   {
    //Imagen superior
    sta = img.GetSubImage(wxRect(0, 0, img.GetWidth(), img.GetHeight()/2));
    //Imagen inferior
    ita = img.GetSubImage(wxRect(0, img.GetHeight()/2,\
                                 img.GetWidth(), img.GetHeight()/2));
    //Referencias
    //Imagen superior
    ref_sta = ref_img.GetSubImage(wxRect(0, 0, ref_img.GetWidth(), ref_img.GetHeight()/2));
    //Imagen inferior
    ref_ita = ref_img.GetSubImage(wxRect(0, ref_img.GetHeight()/2,\
                                 ref_img.GetWidth(), ref_img.GetHeight()/2));
}

pair<double,double> dualParabolic::determine(int x0, int y0, int pmin, int pmax, bool isSTA) {
    //Convertimos imagen a una binaria para trabajar
    vector<vector<bool>> img_bin;
    vector<pair<int,int>> positions;
    unsigned char *data;
    int w, h;

    if(isSTA)   {
        w = sta.GetWidth();
        h = sta.GetHeight();
        data = sta.GetData();
    }
    else    {
        w = ita.GetWidth();
        h = ita.GetHeight();
        data = ita.GetData();
    }
    for(int y=0; y<h; y++)    {
        vector<bool> row;
        for(int x=0; x<w; x++) {
            long pos = (y*w + x)*3;
            //Color Blancuzco
            if(data[pos]+data[pos+1]+data[pos+2] > 382)  {
                positions.push_back(make_pair(y,x));
                row.push_back(1);
            }
            //Negrizo
            else
                row.push_back(0);
        }
        img_bin.push_back(row);
        row.clear();
    }

    return this->houghParabola(img_bin,positions,x0,y0,pmin,pmax);

}

double dualParabolic::MDCP(int x0, int y0, double phi, double p, bool isSTA)   {
    vector<pair<int,int>> positions;
    vector<pair<int,int>> parabola;
    unsigned char *data;
    int w, h;

    if(isSTA)   {
        w = ref_sta.GetWidth();
        h = ref_sta.GetHeight();
        data = ref_sta.GetData();
    }
    else    {
        w = ref_ita.GetWidth();
        h = ref_ita.GetHeight();
        data = ref_ita.GetData();
    }
    //Encontramos posiciones a comparar
    double tol = 0.01, aux;
    for(int y=0; y<h; y++)    {
        for(int x=0; x<w; x++) {
            //Vemos si el punto pertenece a la parábola
            if(x0 <= x) {
                if(isSTA)
                    aux = y0 - sqrt(4*p*(x-x0));
                else
                    aux = y0 + sqrt(4*p*(x-x0));
                if(aux>=0 && aux<h)
                    parabola.push_back(make_pair((int)aux, x));
            }

            //Posiciones a comparar de referencia
            long pos = (y*w + x)*3;
            //Color Blancuzco
            if(data[pos]+data[pos+1]+data[pos+2] > 382)
                positions.push_back(make_pair(y,x));
        }
    }

    //MDCP
    double suma = 0.;
    for(int i=0; i<positions.size(); i++)   {
        double min_dist = 10000000.;
        for(int j=0; j<parabola.size(); j++)    {
            double nor = norm(positions[i], parabola[j]);
            if(min_dist > nor)
                min_dist = nor;
        }
        suma += min_dist;
    }
    return suma;
}

pair<double,double> dualParabolic::houghParabola(vector<vector<bool>> img,\
                                                 vector<pair<int,int>> pos,\
                                                 int cx, int cy, int pmin, int pmax)   {
    /******
    HOUGHPARABOLA - detects parabola with specific vertex in a binary image.
    Basado en el código de MATLAB de:
          Clara Isabel Sánchez
          Biomedical Engineering Group
          ETS Ingenieros de Telecomunicaciones
          University of Valladolid,Spain
          csangut@gmail.com
          August 6, 2007
    ******/

    vector<double> vector_p = linspace(-(double)pmax,(double)pmax);
    vector<double> vector_phi = linspace(0,2.*M_PI-(2.*M_PI/100.));
    vector<vector<int>> Accumulator;//= zeros([length(vector_phi),length(vector_p)]);
    for(int i=0; i<vector_phi.size(); i++)    {
        vector<int> aux;
        for(int j=0; j<vector_p.size(); j++)
            aux.push_back(0);
        Accumulator.push_back(aux);
        aux.clear();
    }
    //[y,x] = find(Imbinary);
    for(int i=0; i<pos.size(); i++) {
       for(int j=0; j<vector_phi.size(); j++)   {
           int Y = pos[i].first - cy;
           int X = pos[i].second - cx;
           double angulo = vector_phi[j];
           double numerador = ((double)Y*cos(angulo)-(double)X*sin(angulo));
           numerador *= numerador;
           double denominador = 4.*((double)X*cos(angulo)+(double)Y*sin(angulo));
           if(denominador != 0) {
                double p = numerador/denominador;
                if(p>(double)pmin && p<(double)pmax && p!=0)  {
                   int indice = find_val(vector_p, p);
                   //indice=indice(1);
                   Accumulator[j][indice]++;
                }
            }
        }
    }
    //Finding local maxima in Accumulator
    int maximo = 0, idx_phi, idx_p;
    for(int i=0; i<Accumulator.size(); i++)    {
        for(int j=0; j<Accumulator[i].size(); j++)  {
            if(maximo < Accumulator[i][j])  {
                maximo = Accumulator[i][j];
                idx_phi = i;
                idx_p = j;
            }
        }
    }

    return make_pair(vector_phi[idx_phi], vector_p[idx_p]);
}

wxImage dualParabolic::draw_parabola(wxImage &img)   {
    unsigned char *data;
    int w, h;
    w = img.GetWidth();
    h = img.GetHeight();
    data = img.GetData();

    //Parabola superior
    double tol = 0.01, aux;
    double p = this->get_p1(), phi = this->get_phi1();
    int y0 = this->get_y1();
    int x0 = this->get_x1();
    for(int x=0; x<w; x++) {
        //Vemos si el punto pertenece a la parábola
        if(x0 <= x) {
            aux = y0 - sqrt(4*p*(x-x0));
            if(aux>=0 && aux<h/2){
                //Pintamos de color rojo
                long pos = ((int)aux*w + x)*3;
                data[pos] = 255;
                data[pos+1] = 20;
                data[pos+2] = 20;
            }
        }
    }

    //Parabola inferior
    p = this->get_p2(); phi = this->get_phi2();
    y0 = this->get_y2();
    x0 = this->get_x2();
    for(int x=0; x<w; x++) {
        //Vemos si el punto pertenece a la parábola
        if(x0 <= x) {
            aux = y0+h/2 + sqrt(4*p*(x-x0));
            if(aux>=h/2 && aux<h){
                //Pintamos de color verde
                long pos = ((int)aux*w + x)*3;
                data[pos] = 20;
                data[pos+1] = 255;
                data[pos+2] = 20;
            }
        }
    }

    return img;
}

/********************* Funciones interfaz **************************/

Dual_ParabolicModelingFrame::~Dual_ParabolicModelingFrame()
{
    //(*Destroy(Dual_ParabolicModelingFrame)
    //*)
}

void Dual_ParabolicModelingFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Dual_ParabolicModelingFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Dual_ParabolicModelingFrame::OnClose(wxCloseEvent& event)
{
    Close();
}

//Rotación 180
bool rot = false;
void Dual_ParabolicModelingFrame::OnButton2Click(wxCommandEvent& event)
{
    //Cambiamos indicador de rotación
    if(rot)
        rot = false;
    else
        rot = true;

    //Desplegamos imagen SIN guardar
    wxClientDC dc(Panel1);
    wxString ruta = FilePickerCtrl1->GetPath();
    wxImage img;

    if(img.LoadFile(ruta))  {
        if(rot)
            img = img.Rotate180();
        dc.DrawBitmap(wxBitmap(img.Scale(600, 400)),0,0);
    }
}

//Algoritmo
bool determined = false;
wxImage img_determined;
void Dual_ParabolicModelingFrame::OnButton1Click(wxCommandEvent& event)
{
    wxClientDC dc(Panel1);
    wxClientDC dc2(Panel2);
    wxString ruta = FilePickerCtrl1->GetPath();
    wxImage img, ref_img;

    if(img.LoadFile(ruta))  {
        ruta = FilePickerCtrl2->GetPath();
        if(ref_img.LoadFile(ruta))  {
            if(rot) {
                img = img.Rotate180();
                ref_img = ref_img.Rotate180();
            }
            int w = img.GetWidth(), h = img.GetHeight();
            ref_img = ref_img.Scale(w, h);

            dualParabolic dp(img, ref_img);

            //Parábola correspondiente a STA
            //Buscamos parábola en el rango de los parámetros del paper
            h /= 2; //Recordar que recortamos las imagenes a la mitad
            int pmin = 15, pmax = 150;
            int xmin = 80, xmax = 215;
            int ymin = h-1, ymax = h;

            double min_MDCP = 10000000.;
            double p, phi;
            int X, Y;
            //Encontrar el mejor centro
            clock_t start = clock();
            for(int y=ymin; y<ymax; y++)  {
                for(int x=xmin; x<xmax; x++)    {
                    pair<double,double> phi_p = dp.determine(x,y,pmin,pmax,true);
                    double mdcp = dp.MDCP(x,y,phi_p.first,phi_p.second,true);
                    if(mdcp < min_MDCP) {
                        min_MDCP = mdcp;
                        phi = phi_p.first;
                        p = phi_p.second;
                        X = x; Y = y;
                    }
                }
            }
            dp.set_MDCP1(min_MDCP);
            dp.set_p1(p);
            dp.set_phi1(phi);
            dp.set_x1(X);
            dp.set_y1(Y);

            //Ahora para la ITA
            min_MDCP = 10000000.;
            ymin = 0; ymax = 1;
            //Encontrar el mejor centro
            for(int y=ymin; y<ymax; y++)  {
                for(int x=xmin; x<xmax; x++)    {
                    pair<double,double> phi_p = dp.determine(x,y,pmin,pmax,false);
                    double mdcp = dp.MDCP(x,y,phi_p.first,phi_p.second,false);
                    if(mdcp < min_MDCP) {
                        min_MDCP = mdcp;
                        phi = phi_p.first;
                        p = phi_p.second;
                        X = x; Y = y;
                    }
                }
            }
            dp.set_MDCP2(min_MDCP);
            dp.set_p2(p);
            dp.set_phi2(phi);
            dp.set_x2(X);
            dp.set_y2(Y);
            clock_t end = clock();

            dp.set_time((double)(end-start)/CLOCKS_PER_SEC);
            img = dp.draw_parabola(img);
            if(rot)
                img = img.Rotate180();

            dc.Clear();
            dc.DrawBitmap(wxBitmap(img),0,0);
            determined = true;
            img_determined = img;

            //Colocamos respuestas
            wxPaintEvent ev=1;
            OnPanel2Paint(ev);
            wxFont font(8, wxDEFAULT,wxNORMAL, wxNORMAL);
            dc2.SetFont(font);
            string word = "Tiempo = " + to_string(dp.get_time())+" s";
            wxString wxw(word.c_str(), wxConvUTF8);
            dc2.DrawText(wxw,2,0);
            if(rot)
                word = "MDCP(sta)= " + to_string(dp.get_MDCP2());
            else
                word = "MDCP(sta)= " + to_string(dp.get_MDCP1());
            wxw = word.c_str();//, wxConvUTF8;
            dc2.DrawText(wxw,2,18);
            if(rot)
                word = "MDCP(ita)= " + to_string(dp.get_MDCP1());
            else
                word = "MDCP(ita)= " + to_string(dp.get_MDCP2());
            wxw = word.c_str();//, wxConvUTF8;
            dc2.DrawText(wxw,2,36);
            word = "(y-"+to_string(dp.get_y1())+")^2=(4)";
            word = word+to_string(dp.get_p1())+"(x-"+to_string(dp.get_x1())+")";
            wxw = word.c_str();//, wxConvUTF8;
            dc2.DrawText(wxw,2,54);
            word = "(y-"+to_string(dp.get_y2()+h)+")^2=(4)";
            word = word+to_string(dp.get_p2())+"(x-"+to_string(dp.get_x2())+")";
            wxw = word.c_str();//, wxConvUTF8;
            dc2.DrawText(wxw,2,74);
        }
    }

}

//Cuando se selecciona un archivo, desplegar en el PANEL PRICIPAL
void Dual_ParabolicModelingFrame::OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event)
{
    int width = 600, height = 400;
    wxClientDC dc(Panel1);
    wxString ruta = FilePickerCtrl1->GetPath();
    wxImage img;

    if(img.LoadFile(ruta))
        dc.DrawBitmap(wxBitmap(img.Scale(width, height)),0,0);
    rot = false;
}

//Cuando se selecciona un archivo, desplegar en el PANEL AUXILIAR
void Dual_ParabolicModelingFrame::OnFilePickerCtrl2FileChanged(wxFileDirPickerEvent& event)
{
    int width = 232, height = 97;
    wxClientDC dc(Panel2);
    wxString ruta = FilePickerCtrl2->GetPath();
    wxImage img;

    if(img.LoadFile(ruta))
        dc.DrawBitmap(wxBitmap(img.Scale(width, height)),0,0);
    rot = false;
}

void Dual_ParabolicModelingFrame::OnPanel1Paint(wxPaintEvent& event)
{
    int width = 600, height = 400;
    wxPaintDC dc(Panel1);

    //Pintamos el panel
    dc.SetPen(wxPen(*wxBLACK,1));
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.DrawRectangle(0, 0, width, height);
}
void Dual_ParabolicModelingFrame::OnPanel2Paint(wxPaintEvent& event)
{
    int width = 232, height = 97;
    wxPaintDC dc(Panel2);

    //Pintamos el panel
    dc.SetPen(wxPen(*wxBLACK,1));
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.DrawRectangle(0, 0, width, height);
}

//Guardar imagen con parábola
void Dual_ParabolicModelingFrame::OnButton3Click(wxCommandEvent& event)
{
    //Solo se guardará si ya se corrió el programa
    if(determined)  {
        wxFileDialog dial(this, wxT("Guardar imagen como..."),\
                          wxEmptyString, wxEmptyString,\
                          wxT("PNG files (*.png)|*.png|BMP files (*.bmp)|*.bmp"),\
                          wxFD_SAVE);

        if(dial.ShowModal() == wxID_OK) {
            wxString ext = wxT(".bmp");
            if(dial.GetFilterIndex() == 0)
                ext = wxT(".png");
            img_determined.SaveFile(dial.GetPath()+ext);
            determined = false;
        }

    }
}
