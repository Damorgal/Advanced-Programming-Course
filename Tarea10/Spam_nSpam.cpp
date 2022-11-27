#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include<fstream>
#include <sstream>
#include <time.h>

using namespace std;

#define training_size 4250
#define validation_size 750
#define total_size 5000
string sPred;

map<string,long double> frequency(vector< map<string,int> > *set, vector<string> *enc) {
    map<string, long double> data;
    unsigned long long int total=0;
    //Contamos el número total de palabras y de cada categoría
    for(int i=0; i<set->size(); i++)   {
        //for(auto itr = (*set)[i].begin(); itr!=(*set)[i].end() && itr->first!=sPred; itr++)   {
        for(int j=1; j<enc->size()-1; j++)  {
            if(i == 0) 
                data[(*enc)[j]] = (*set)[i][(*enc)[j]];
                //data.insert({itr->first, itr->second});
            else
                data[(*enc)[j]] += (*set)[i][(*enc)[j]];
                //data[itr->first] += itr->second;
            
            //total += itr->second;
            total += (*set)[i][(*enc)[j]];
        }
    }
    //Convertimos a valores entre 0 y 1
    //for(auto itr = data.begin(); itr!=data.end(); itr++)  
    for(int j=1; j<enc->size()-1; j++)
        data[(*enc)[j]] /= total;
        //data[itr->first] /= total;
    //data.insert({"Total", total});
    return data;
}

void intersection(map<string,long double> *spam, map<string,long double> *notSpam, vector<string> *enc)    {
    //for(auto itr=spam->begin(); itr!=spam->end(); itr++)    {
    for(int j=1; j<enc->size()-1; j++) {
        //if((*spam)[itr->first] == 0.0 || (*notSpam)[itr->first] == 0.0)   {
        if((*spam)[(*enc)[j]] * (*notSpam)[(*enc)[j]] == 0.0)   {
                //spam->erase(itr->first);
                //notSpam->erase(itr->first);
                spam->erase((*enc)[j]);
                notSpam->erase((*enc)[j]);
        }
    }
}

vector<bool> predict(vector<map<string,int>> *set, map<string,long double> *spam, map<string,long double> *notSpam, vector<string> *enc)   {
    //No importa cuantas veces aparezca una palabra, solo que aparezca
    long double probSpam=1.0, probNotSpam=1.0;
    vector<bool> pred;
    for(int i=0; i<set->size(); i++)  {
        //for(auto itr=(*set)[i].begin(); itr!=(*set)[i].end() && itr->first!=sPred; itr++)    {
        for(int j=1; j<enc->size()-1; j++) {
            //if((*set)[i][itr->first] != 0)  {
            if((*set)[i][(*enc)[j]] != 0)  {
                //auto it = spam->find(itr->first);
                //auto it = spam->find((*enc)[j]);
                //if(it != spam->end())   {
                if((*spam)[(*enc)[j]] != 0.0 && (*notSpam)[(*enc)[j]] !=0.0)  {
                    //probSpam *= (*spam)[itr->first];
                    //probNotSpam *= (*notSpam)[itr->first];
                    probSpam *= (*spam)[(*enc)[j]];
                    probNotSpam *= (*notSpam)[(*enc)[j]];
                }
            }
        }
        if(probSpam < probNotSpam)
            pred.push_back(0);
        else
            pred.push_back(1);
    }
    return pred;
}

void metrics(vector<map<string,int>> *set, vector<bool> *pred)  {
    int tp=0, fp=0, fn=0, tn=0;
    for(int i=0; i<pred->size(); i++) {
        if((*set)[i][sPred] == 1)    {
            if((*pred)[i] == 1)
                tp++;
            else
                fp++;
        }
        else    {
            if((*pred)[i] == 0)
                tn++;
            else
                fn++;
        }
    }
    cout<<"\nConfusion Matrix:\n";
    cout<<"       Spam |noSpam\n"<<"  Spam |"<<tp<<"  | "<<fp<<endl;
    cout<<"no Spam|"<<fn<<"  | "<<tn<<endl;
    
    cout<<"\nAccuracy = "<< (tp+tn)/((float)(tp+tn+fp+fn))<< endl;
    cout<<"\nPrecision = "<< (tp)/((float)(tp+fp))<< endl;
    cout<<"\nSensitivity = "<< (tp)/((float)(tp+fn))<< endl;
    cout<<"\nSpecificity = "<< (tn)/((float)(tn+fp))<< endl;
    cout<<"\nF1 Score = "<< 2*(tp)/((float)(tp+fp))*(tp)/((float)(tp+fn))/((tp)/((float)(tp+fp))+(tp)/((float)(tp+fn)))<< endl;
    
}

int main(int narg, char *varg[])  {
    if(narg < 2)    {
        cout << "Error, introduce la dirección del fichero.cvs\n";
        exit(1);
    }
    
    
    //Archivo donde guardamos si ya se crearon los archivos
    //de entrenamiento y test para no volverlos a crear
    //fstream indicator;
    string line, word;
    //indicator.open("indicator.txt");
    //indicator >> word;
    //bool ind = stoi(word);
    if(narg == 2)    {
        //indicator << "1" << endl;
        //Leemos el archivo
        ifstream lectura;
        lectura.open(varg[1]);
    
        //Archivo de entrenamiento
        ofstream training;
        training.open("training_file.csv");
        
        //Archivo de validación
        ofstream validation;
        validation.open("validation_file.csv");
        
        //Copiamos encabezados
        getline(lectura, line);
        training << line << "\n";
        validation << line << "\n";
        
        //Dividimos en 85% entrenamiento y 15% validacion
        //Como son 5000 datos: 4250 y 750 respectivamente
        vector<bool> arr(total_size, false);
        int aux;
        srand(time(NULL));
        for(int i=0; i<validation_size; i++)    {
            aux = rand()%total_size;
            if(arr[aux] == false)
                arr[aux] = true;
            else
                i--;
        }
        int pos = 0;
        while(!lectura.eof())   {
            getline(lectura, line);
            if(arr[pos])
                validation << line << "\n";
            else
                training << line << "\n";
            pos++;
        }
        arr.clear();
        lectura.close();
        training.close();
        validation.close();
    }
    //indicator.close();
    
    //Archivo de entrenamiento
    ifstream training;
    
    //Archivo de validación
    ifstream validation;
    
    if(narg == 2) {
        training.open("training_file.csv");
        validation.open("validation_file.csv");
    }
    else {
        training.open(varg[1]);
        validation.open(varg[2]);
    }
    
    //Lo guardaremos en un vector de mapas para acceder fácilmente a la palabra
    vector< map<string,int> > training_set;
    vector< map<string,int> > validation_set;
    
    //Encabezados
    vector<string> encabezados;
    getline(training, line);
    getline(validation, line);
    stringstream s(line); 
    encabezados.clear();
    while (getline(s, word, ',')) 
        encabezados.push_back(word); 
    
    //Guardamos en vector training
    //string temp;
    int pos;
    while(!training.eof())  {
        getline(training, line);
        stringstream s(line); 
        map<string,int> mapa;
        getline(s, word, ',');
        pos = 0;
        while(getline(s, word, ',')) 
            mapa[encabezados[++pos]] = stoi(word); 
        training_set.push_back(mapa);
        mapa.clear();
    }

    //Guardamos en vector validation
    while(!validation.eof())  {
        getline(validation, line);
        stringstream s(line); 
        map<string,int> mapa;
        getline(s, word, ',');
        pos = 0;
        while(getline(s, word, ',')) 
            mapa[encabezados[++pos]] = stoi(word); 
        validation_set.push_back(mapa);
        mapa.clear();
    }
    //Cerramos archivos
    training.close();
    validation.close();
    
    //Trabajamos con los vectores de datos de entrenamiento
    //(1)
    //Obtenemos los diccionarios
    int idx_pred = encabezados.size()-1;
    sPred = encabezados[idx_pred];
    vector< map<string,int> > spam, notSpam;
    for(int i=0; i<training_set.size(); i++)   {
            if(training_set[i][sPred] == 1)
                spam.push_back(training_set[i]);
            else
                notSpam.push_back(training_set[i]);
    }
    
    //(2)
    //Obtenemos el vector de frecuencias de los datos spam
    map<string,long double> frec_spam = frequency(&spam, &encabezados);
    spam.clear();
    //Obtenemos el vector de frecuencias de los datos no spam
    map<string,long double> frec_notSpam = frequency(&notSpam, &encabezados);
    notSpam.clear();
    
    //(3)
    //Realizamos intersección para evitar palabras con frecuencia 0
    intersection(&frec_spam, &frec_notSpam, &encabezados);
    
    //(4)
    //Realizamos el test
    //Predicciones
    vector<bool> pred = predict(&validation_set, &frec_spam, &frec_notSpam, &encabezados);
    
    //Reportamos primero la matriz de confusión
    metrics(&validation_set, &pred);
    
    return 0;
}
