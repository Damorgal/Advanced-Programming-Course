/***************************************************************
 * Name:      interfazMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    DiegoMoreno ()
 * Created:   2020-11-27
 * Copyright: DiegoMoreno ()
 * License:
 **************************************************************/

#include "interfazMain.h"
#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include <wx/settings.h>
#include <cairo/cairo.h>
#include <wx/filepicker.h>

//(InternalHeaders(interfazFrame)
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

//(*IdInit(interfazFrame)
const long interfazFrame::ID_BUTTON1 = wxNewId();
const long interfazFrame::ID_BUTTON2 = wxNewId();
const long interfazFrame::ID_PANEL1 = wxNewId();
const long interfazFrame::ID_FILEPICKERCTRL1 = wxNewId();
const long interfazFrame::ID_TEXTCTRL1 = wxNewId();
const long interfazFrame::ID_STATICTEXT1 = wxNewId();
const long interfazFrame::ID_STATICTEXT2 = wxNewId();
const long interfazFrame::ID_STATICTEXT3 = wxNewId();
const long interfazFrame::ID_STATICTEXT4 = wxNewId();
const long interfazFrame::ID_STATICTEXT5 = wxNewId();
const long interfazFrame::ID_TEXTCTRL2 = wxNewId();
const long interfazFrame::ID_TEXTCTRL3 = wxNewId();
const long interfazFrame::ID_TEXTCTRL4 = wxNewId();
const long interfazFrame::ID_PANEL2 = wxNewId();
const long interfazFrame::ID_STATICLINE1 = wxNewId();
const long interfazFrame::ID_MENUITEM1 = wxNewId();
const long interfazFrame::idMenuAbout = wxNewId();
const long interfazFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(interfazFrame,wxFrame)
    //(*EventTable(interfazFrame)
    //*)
END_EVENT_TABLE()

interfazFrame::interfazFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(interfazFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(807,437));
    SetForegroundColour(wxColour(255,255,255));
    Button1 = new wxButton(this, ID_BUTTON1, _("Entrenar"), wxPoint(392,344), wxSize(320,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    Button2 = new wxButton(this, ID_BUTTON2, _("Salir"), wxPoint(715,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    Button2->SetBackgroundColour(wxColour(255,255,255));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(8,8), wxSize(376,368), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FilePickerCtrl1 = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, wxEmptyString, wxEmptyString, wxPoint(568,184), wxSize(232,32), wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    FilePickerCtrl1->SetForegroundColour(wxColour(255,255,255));
    FilePickerCtrl1->SetBackgroundColour(wxColour(255,255,255));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("3"), wxPoint(624,224), wxSize(176,16), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Cantidad de capas ocultas:"), wxPoint(392,220), wxSize(224,22), 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColour(0,0,0));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Seleccionar archivo:"), wxPoint(392,189), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText2->SetForegroundColour(wxColour(0,0,0));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Tamagnos:"), wxPoint(392,252), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText3->SetForegroundColour(wxColour(0,0,0));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Epocas:"), wxPoint(392,285), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText4->SetForegroundColour(wxColour(0,0,0));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Razon de aprendizaje:"), wxPoint(392,315), wxSize(187,24), 0, _T("ID_STATICTEXT5"));
    StaticText5->SetForegroundColour(wxColour(0,0,0));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("0.01"), wxPoint(592,320), wxSize(208,16), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("5000"), wxPoint(472,288), wxSize(328,16), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, _("3 3 3"), wxPoint(496,256), wxSize(304,16), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(392,8), wxSize(408,160), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(392,160), wxSize(408,32), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&interfazFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&interfazFrame::OnButton2Click);
    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&interfazFrame::OnPanel1Paint,0,this);
    Connect(ID_FILEPICKERCTRL1,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&interfazFrame::OnFilePickerCtrl1FileChanged);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&interfazFrame::OnTextCtrlCapasText);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&interfazFrame::OnTextCtrlRazonText);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&interfazFrame::OnTextCtrlEpocasText);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&interfazFrame::OnTextCtrlTamagnosText);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&interfazFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&interfazFrame::OnAbout);
    //*)
}

/*********************** Funciones de la NNM *******************************/

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

double delta_bp;
double lrate;

double dot(vector<double> x, vector<double> y)  {
    double suma = 0.;
    for(int i=0; i<(int)x.size(); i++)
        suma += x[i]*y[i];
    return suma;
}

class neuron    {
private:
    double value;
    double act_value;
    vector<double> wgts;
    double grad;
public:
    neuron(int input_size)  {
        for(int i=0; i<input_size; i++)
            wgts.push_back(rand()/static_cast<double>(RAND_MAX));
        return;
    }
    ~neuron()   {
        wgts.clear();
        return;
    }
    double get_value()  {
        return this->value;
    }
    vector<double> get_weights()    {
        return this->wgts;
    }
    double get_act_value()  {
        return this->act_value;
    }
    double get_grad()  {
        return this->grad;
    }
    void set_value(double val)  {
        this->value = val;
        return;
    }
    void set_grad(double val)  {
        this->grad = val;
        return;
    }
    void forward_propagation(vector<double> &input);
    vector<double> backward_propagation(double lrate,vector<double> vals);
};

void neuron::forward_propagation(vector<double> &input) {
    //Función de propagación con activación Sigmoid
    double bias = wgts[0];
    value = dot(wgts, input) + bias;
    value = 1./(1. + exp(-value));
    act_value = value < 0.5 ? 0. : 1.;
}

vector<double> neuron::backward_propagation(double lrate,vector<double> vals)    {
    if(vals.size() != wgts.size())
        cout<<"Error de dimensión en back propagation\n";
    vector<double> deltas;
    for(int i=0; i<(int)wgts.size(); i++) {
        double delta = lrate * grad * vals[i];
        deltas.push_back(delta);
        wgts[i] += delta;
    }
    return deltas;//grad*value*(1.-value);
}

class layer {
private:
    vector<neuron> neurons;
public:
    layer(int input_size, int output_size);
    ~layer()    {
        /*for(int i=0; i<neurons.size(); i++)
            neurons[i].~neuron();
            */
        neurons.clear();
    }
    int get_size()  {
        return neurons.size();
    }
    void set_grad_neuron(double val, int idx)   {
        neurons[idx].set_grad(val);
    }
    double get_value_neuron(int idx)    {
        return neurons[idx].get_value();
    }
    void sum_grad_neuron(double val, int idx)   {
        neurons[idx].set_grad(val + neurons[idx].get_grad());
    }
    vector<double> get_values() {
        vector<double> vals;
        for(int i=0; i<neurons.size(); i++)
            vals.push_back(neurons[i].get_value());
        return vals;
    }
    vector<double> get_weights_neuron(int idx) {
        return neurons[idx].get_weights();
    }
    vector<double> forward_propagation(vector<double> &input);
    void backward_propagation(double lrate,layer back);
};

layer::layer(int input_size, int output_size)   {
    for(int i=0; i<output_size; i++)
        neurons.push_back(neuron(input_size));
    return;
}

vector<double> layer::forward_propagation(vector<double> &input)    {
    for(int i=0; i<(int)neurons.size(); i++)
        neurons[i].forward_propagation(input);
    vector<double> output;
    for(int i=0; i<(int)neurons.size(); i++)
        output.push_back(neurons[i].get_value());
    return output;
}

void layer::backward_propagation(double lrate, layer back)    {
    vector<double> errores_new;
    for(int i=0; i<(int)neurons.size(); i++)  {
        errores_new =neurons[i].backward_propagation(lrate, back.get_values());
        for(int j=0; j<back.get_size(); j++) {
            if(i == 0)
                back.set_grad_neuron(errores_new[j],j);//*back.get_value_neuron(j),j);
            else
                back.sum_grad_neuron(errores_new[j],j);//*back.get_value_neuron(j),j);
        }
        errores_new.clear();
    }
    /*
    for(int i=0; i<errores_new.size(); i++)    {
        for(int j=0; j<back.get_size(); j++) {
            if(i == 0)
                back.set_grad_neuron(errores_new[i]*back.get_value_neuron(j),j);
            else
                back.sum_grad_neuron(errores_new[i]*back.get_value_neuron(j),j);
        }
    }*/

    /*double suma = 0.;
    for(int i=0; i<errores_new.size(); i++)
        suma += errores_new[i];
    delta_bp = suma;*/
    errores_new.clear();
    return;
}

class neuralnetwork {
private:
  vector<layer> layers;
public:
    neuralnetwork(int num_layers, vector<int> sizes)   {
        for(int i=0; i<=num_layers; i++){

            layer aux = layer(sizes[i], sizes[i+1]);

            layers.push_back(aux);

        }
    }
    ~neuralnetwork()    {
        /*for(int i=0; i<layers.size(); i++)
            layers[i].~layer();
            */
        layers.clear();
        return;
    }
    int get_size()  {
        return layers.size();
    }
    vector<layer> get_layers() {
        return layers;
    }
    double forward_propagation(vector<double> &input);
    void backward_propagation(double lrate, double error);
    vector<double> train(int epochs, vector<vector<double>> &xtrain, vector<double> &ytrain);
} ;

double neuralnetwork::forward_propagation(vector<double> &input)    {
    vector<double> output_layer = input;
    for(int i=0; i<(int)layers.size(); i++) {
        output_layer = layers[i].forward_propagation(output_layer);
    }
    //La predicción está ahora en la última output_layer
    return output_layer[0];
}

void neuralnetwork::backward_propagation(double lrate, double error)   {
    layers[layers.size()-1].set_grad_neuron(error, 0);
    for(int i=(int)layers.size()-1; i>0; i--)
        layers[i].backward_propagation(lrate,layers[i-1]);
    return;
}

vector<double> neuralnetwork::train(int epochs, vector<vector<double>> &xtrain, vector<double> &ytrain)    {
    vector<double> error;
    vector<double> total_error;
    vector<double> pred;
    //double lrate = 3.8;
    for(int i=1; (i==1 || total_error[total_error.size()-1]!=0) && i<=epochs && \
        (i<3||total_error[total_error.size()-1]!=total_error[total_error.size()-2]); i++)    {
        //cout << "Epoch "<<i<<":\n";
        clock_t start = clock();
        total_error.push_back(0.);
        error.push_back(0.);
        pred.clear();
        for(int k=0; k<(int)ytrain.size(); k++) {
            double prediction = forward_propagation(xtrain[k]);
            pred.push_back(prediction);
            error[i-1] = (ytrain[k] - prediction)*(ytrain[k] - prediction)/2;
            total_error[i-1] += fabs(error[i-1]);
            //Derivada de la función Sigmoid
            int sgn = ytrain[k] - prediction < 0 ? -1 : 1;
            double delta = sgn*error[i-1] * prediction * (1.-prediction);
            backward_propagation(lrate, delta);
        }
        clock_t end = clock();
        //cout<<"Error total = "<<total_error[i-1]<<endl;
        //cout << "Tiempo de época: " << (double)(end-start)/CLOCKS_PER_SEC << " s\n\n";
    }
    //cout<<"Y"<<'\t'<<"pred\n";
    //for(int i=0; i<ytrain.size(); i++)
      //  cout<<ytrain[i]<<"\t"<<pred[i]<<endl;

    return total_error;
}


struct dataset {
    vector<vector<double>> x;
    vector<double> y;
    dataset(string file) {
        //Leemos ancho y alto
        int ancho=0, alto=0;
        ifstream img(file);
        if(!img) {
            cout << "Error al abrir el archivo: "<< file<<endl;
            exit(1);
        }
        string line, word;
        //Leemos la primera linea Nombres
        getline(img, line);
        stringstream s(line);
        while(getline(s, word, '\t'))
            ancho++;

        //Leemos la matriz
        vector<double> aux;
        while(getline(img, line))  {
            stringstream s(line);
            //Agregamos el Bias
            aux.push_back(1.);
            for(int i=0; i<ancho; i++)  {
                getline(s, word, '\t');
                if(i != ancho-1)
                    aux.push_back((double)stof(word));
                else
                    y.push_back((double)stof(word));
            }
            x.push_back(aux);
            aux.clear();
        }
        //Cerramos archivo
        img.close();
    }
    ~dataset()  {
        for(int i=0; i<(int)x.size(); i++)
            x[i].clear();
        x.clear();
    }
} ;

/**************Funciones de interfaz*******************/

interfazFrame::~interfazFrame()
{
    //(*Destroy(interfazFrame)
    //*)
}

void interfazFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void interfazFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void interfazFrame::OnButton2Click(wxCommandEvent& event)
{
    Close();
}

void interfazFrame::OnTextCtrlCapasText(wxCommandEvent& event)
{/*
    wxTextCtrl *nl = new wxTextCtrl(this,ID_TEXTCTRL1);
    wxString ruta = nl->GetLineText(0);
    num_layers = stoi(string(ruta));
    */
}

void interfazFrame::OnTextCtrlTamagnosText(wxCommandEvent& event)
{/*
    wxTextCtrl *nl = new wxTextCtrl(this,ID_TEXTCTRL4);
    wxString ruta = nl->GetLineText(0);
    string line = string(ruta), word;
    stringstream s(line);

    for(int i=0; i<num_layers; i++)  {
        getline(s, word, ' ');
        layer_sizes.push_back(stoi(word));
    }*/
}

void interfazFrame::OnTextCtrlEpocasText(wxCommandEvent& event)
{/*
    wxTextCtrl *nl = new wxTextCtrl(this,ID_TEXTCTRL3);
    wxString ruta = nl->GetLineText(0);
    epoch = stoi(string(ruta));*/
}

void interfazFrame::OnTextCtrlRazonText(wxCommandEvent& event)
{/*
    wxTextCtrl *nl = new wxTextCtrl(this,ID_TEXTCTRL2);
    wxString ruta = nl->GetLineText(0);
    lrate = (double)stof(string(ruta));*/
}

void interfazFrame::OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event)
{/*
    wxFileDialog *fdialog = new wxFileDialog(this);
    wxString ruta;
    if(fdialog->ShowModal() == wxID_OK) {
        ruta = fdialog->GetPath();*/
        wxString ruta = FilePickerCtrl1->GetPath();
        dataset data(string(ruta.mb_str()));
    //}
}

void interfazFrame::OnPanel1Paint(wxPaintEvent& event)
{
    int width = 376, height = 368;
    int origenX = 25, origenY = height-25;
    int margen = 20;
    int ejeX = width-margen-origenX, ejeY = origenY-margen;
    wxPaintDC dc(Panel1);

    //Pintamos el panel
    dc.SetPen(wxPen(*wxBLACK,1));
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.DrawRectangle(0, 0, width, height);

    //Los ejes
    dc.SetPen(wxPen(*wxRED,3));
    dc.DrawLine(origenX,margen, origenX,origenY);
    dc.DrawLine(origenX,origenY, width-margen,origenY);

    //Pintamos líneas de guía y labels
    dc.SetPen(wxPen(*wxLIGHT_GREY,1));
    int num_lines = 10;
    int x = ejeX/num_lines, y = ejeY/num_lines;
    for(int i=1; i<=num_lines; i++)  {
        //Lineas
        dc.DrawLine(origenX+x*i,margen, origenX+x*i,origenY);
        dc.DrawLine(origenX,origenY-y*i, width-margen,origenY-y*i);
        //Labels
        string s = to_string((float)i/num_lines), num;
        num.push_back(s[0]); num.push_back(s[1]); num.push_back(s[2]);
        wxString word = wxString(num);
        dc.DrawText(word, 0,origenY-y*i-10);
        word = wxString(to_string(origenX+x*i));
        dc.DrawText(word, origenX+x*i-12,origenY+2);
    }
    //El origen
    wxString word = wxString(to_string(0));
    dc.DrawText(word, origenX/2-5,origenY);

}

//training
void interfazFrame::OnButton1Click(wxCommandEvent& event)
{
    wxPaintDC dc(Panel1), dc2(Panel2);
    dc.Clear(); dc2.Clear();
    wxPaintEvent ev=1;
    OnPanel1Paint(ev);
    srand(time(nullptr));
    wxString ruta = FilePickerCtrl1->GetPath();
    dataset data(string(ruta.mb_str()));

    //int num_layers = atoi(args[2]);
    ruta = TextCtrl1->GetLineText(0);
    int num_layers = wxAtoi(ruta);


    //vector<int> layer_sizes;
    ruta = TextCtrl4->GetLineText(0);
    string line = string(ruta.mb_str()), word;
    stringstream s(line);

    vector<int> layer_sizes;
    layer_sizes.push_back((int)data.x[0].size());
    layer_sizes.push_back((int)data.x[0].size());
    for(int i=0; i<num_layers; i++)  {
        getline(s, word, ' ');
        layer_sizes.push_back(stoi(word));
    }
    layer_sizes.push_back(1);

    //epocas
    ruta = TextCtrl3->GetLineText(0);
    int epoch = wxAtoi(ruta);

    //razon aprendizaje
    ruta = TextCtrl2->GetLineText(0);
    lrate = wxAtof(ruta);

    //Ejemplo de lectura correcta
    /*
    for(int i=34; i<40; i++)  {
        for(int j=0; j<data.x[i].size(); j++)
            cout << data.x[i][j] << " ";
        cout<<data.y[i]<<endl;
    }
    */

    neuralnetwork nn(++num_layers, layer_sizes);
    vector<double> errors = nn.train(epoch, data.x, data.y);
    /*vector<double> errors;
    for(int i=0; i<300; i++)  {
        errors.push_back(40-i*.2);
    }*/

    //cout<<"El error del entrenamiento: " <<errors[errors.size()-1]<<endl;
    //cout << "El tiempo total del entrenamiento: " << (double)(end-start)/CLOCKS_PER_SEC << " s\n";

    //Graficamos la curva de error de aprendizaje
    int width = 376, height = 368;
    int origenX = 25, origenY = height-25;
    int margen = 20, step = 2;
    int ejeX = width-margen-origenX, ejeY = origenY-margen;
    dc.SetPen(wxPen(*wxBLUE,1));
    for(int i=0; i<errors.size()-2; i++)  {
        //Lineas
        dc.DrawLine(origenX+i+step,origenY-(int)(ejeY*errors[i]/100.),\
                    origenX+i+1+step,origenY-(int)(ejeY*errors[i+1]/100.));
    }
    errors.clear();

    //Dibujamos los pesos
    width = 408; height = 160;
    origenX = 10; origenY = height-20;
    margen = 20;
    ejeX = width-margen-origenX; ejeY = origenY-margen;

    //Para visualizar mejor los pesos, encontramos el mínimo y máximo
    //para normalizar el grosor de la línea del peso
    double maxw, minw;
    for(int i=1; i<(int)nn.get_size(); i++) {
        for(int j=0; j<nn.get_layers()[i].get_size(); j++)  {
            vector<double> w = nn.get_layers()[i].get_weights_neuron(j);
            if(i==1 && j==0)
                maxw = minw = w[0];
            for(int k=0; k<w.size(); k++)   {
                if(w[k] > maxw)
                    maxw = w[k];
                if(w[k] < minw)
                    minw = w[k];
            }
        }
    }
    //Una manera de normalizar
    /*
    double tras = -minw;
    double scale = maxw-minw;
    */
    //Otra manera
    double tras = 0;
    double scale = max(abs(minw), maxw);

    //Dibjamos las líneas
    int x = ejeX/(int)nn.get_size();
    for(int i=0; i<(int)nn.get_size(); i++) {
        int num_n = nn.get_layers()[i].get_size();
        int y = ejeY/(num_n);
        for(int j=1; j<=num_n; j++)  {
            dc2.SetPen(wxPen(*wxBLACK,1));
            dc2.SetBrush(*wxBLUE_BRUSH);
            dc2.DrawCircle(origenX+x/2+i*x,origenY+y/2-j*y, 6);
            if(i > 0)   {
                vector<double> w = nn.get_layers()[i].get_weights_neuron(j-1);
                int num_n_ant = nn.get_layers()[i-1].get_size();
                int y2 = ejeY/(num_n_ant);
                for(int k=1; k<=w.size(); k++)   {
                    dc2.SetPen(wxPen(*wxGREEN,(int)((abs(w[k-1])+tras)/scale*10/1.5)));
                    dc2.DrawLine(origenX+x/2+(i-1)*x,origenY+y2/2-k*y2,\
                                 origenX+x/2+i*x,origenY+y/2-j*y);
                }
            }
        }
    }
}
