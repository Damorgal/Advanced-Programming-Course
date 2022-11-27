#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stack>
#include <utility>

using namespace std;

//col1 debe ser menor que col2
#define col1 0
#define col2 255

string output_file = "";

vector< vector<int> > getImgMatrix(char *file)  {
    ifstream img(file);
    if(!img) {
        printf("%s : Error al abrir el archivo.\n", file);
        exit(1);
    }
    string line;
    //Leemos la primera linea P2
    getline(img, line);
    while(line[0] == '#')
        getline(img, line);
    if(line != "P2")    {
        printf("Error, la imagen no es formato pgm (P2)\n");
        exit(1);
    }
    
    //Leemos ancho y alto
    int ancho, alto;
    string word;
    getline(img, line);
    while(line[0] == '#')
        getline(img, line);
    stringstream s(line); 
    getline(s, word, ' ');
    ancho = stoi(word);
    getline(s, word, ' ');
    alto = stoi(word);
    
    //Leemos valor máximo
    getline(img, line);
    while(line[0] == '#')
        getline(img, line);
    //Aquí podemos hacer algo si nos
    //interesa el valor máximo (por ahora no).
    
    //Leemos la matriz
    int n = ancho*alto;
    vector< vector<int> > mat;
    vector<int> aux;
    for(unsigned long int i=1, j=1; i<=n; i++, j++)  {
        getline(img, line);
        while(line[0] == '#')
            getline(img, line);
        stringstream s(line); 
        getline(s, word);
        aux.push_back(stoi(word));
        if(j%ancho == 0)    {
            j = 0;
            mat.push_back(aux);
            aux.clear();
        }
    }
    //Cerramos archivo
    img.close();
    
    //Regresamos la matriz con los datos de imagen
    return mat;
}

void verify(vector< vector<int> > *mat)  {
    //Si un color nos es el definido, lo truncaremos al más cercano
    int decision = (col1+col2)>>1;
    int ancho = (*mat)[0].size();
    int alto = mat->size();
    for(int i=0; i<alto; i++)   
        for(int j=0; j<ancho; j++)  
            if((*mat)[i][j] != col1 || (*mat)[i][j] != col2)
                (*mat)[i][j] <= decision ? (*mat)[i][j] = col1 : (*mat)[i][j] = col2;
    return;
}

void generateMaxMinImg(vector< vector<int> > *mat, int cmin, int cmax)    {
    int ancho = (*mat)[0].size();
    int alto = mat->size();
    
    //Colocamos información general de la imagen
    ofstream img(output_file);
    img << "P2\n#Imagen generada por Diego Moreno para la tarea 11 PA.\n";
    img << "#Formato PGM (P2) que contiene las componentes de longitud mínima y máxima\n";
    img << ancho << " " << alto << "\n255\n";
    
    //Escribimos la imagen
    for(int i=0; i<alto; i++)  { 
        for(int j=0; j<ancho; j++)  {
            if((*mat)[i][j] == cmin || (*mat)[i][j] == cmax)
                img << col2 << endl;
            else
                img << col1 << endl;
        }
    }
    
    //Cerramos la imagen
    img.close();
}

unsigned long int mark(vector< vector<int> > *mat, int posx, int posy, int k) {
    /* Función que marca la componente usando 8 vecinos señalando con el entero k */
    stack< pair<int,int> > s;
    s.push(make_pair(posx, posy));
    int ancho = (*mat)[0].size();
    int alto = mat->size();
    int i, j;
    (*mat)[posx][posy] = k;
    unsigned long int tam = 1;
    while(!s.empty())   {
        //Quitamos elemento
        i = s.top().first;
        j = s.top().second;
        s.pop();
        
        //Posiciones validas
        //Arriba
        if(i-1 >= 0)    {
            //Esquina superior izquierda
            if(j-1 >= 0) 
                if((*mat)[i-1][j-1] == col2)    {
                    (*mat)[i-1][j-1] = k;
                    s.push(make_pair(i-1,j-1));
                    tam++;
                }
            //Medio superior
            if((*mat)[i-1][j] == col2)  {
                (*mat)[i-1][j] = k;
                s.push(make_pair(i-1,j));
                tam++;
            }
            //Esquina superior derecha
            if(j+1 < ancho)
                if((*mat)[i-1][j+1] == col2)    {
                    (*mat)[i-1][j+1] = k;
                    s.push(make_pair(i-1,j+1));
                    tam++;
                }
        }
        //Enmedio
        //Medio izquierda
        if(j-1 >= 0) 
            if((*mat)[i][j-1] == col2)  {
                (*mat)[i][j-1] = k;
                s.push(make_pair(i,j-1));
                tam++;
            }
        //Medio derecha
        if(j+1 < ancho) 
            if((*mat)[i][j+1] == col2)    {
                (*mat)[i][j+1] = k;
                s.push(make_pair(i,j+1));
                tam++;
            }
        //Abajo
        if(i+1 < alto)    {
            //Esquina inferior izquierda
            if(j-1 >= 0) 
                if((*mat)[i+1][j-1] == col2)    {
                    (*mat)[i+1][j-1] = k;
                    s.push(make_pair(i+1,j-1));
                    tam++;
                }
            //Medio inferior
            if((*mat)[i+1][j] == col2)  {
                (*mat)[i+1][j] = k;
                s.push(make_pair(i+1,j));
                tam++;
            }
            //Esquina inferior derecha
            if(j+1 < ancho) 
                if((*mat)[i+1][j+1] == col2)    {
                    (*mat)[i+1][j+1] = k;
                    s.push(make_pair(i+1,j+1));
                    tam++;
                }
        }
    }
    return tam;
}

void connectedComponents(vector< vector<int> > *mat)    {
    int maximo, minimo, comp=-1, comp_max=-1, comp_min=-1;
    int ancho = (*mat)[0].size();
    int alto = mat->size();
    unsigned long int tam;
    map <int, int> comp_sizes;
    //Contamos tiempo del algoritmo
    clock_t start = clock();
    for(int i=0; i<alto; i++)  { 
        for(int j=0; j<ancho; j++)  {
            if((*mat)[i][j] == col2)    {
                tam = mark(mat, i, j, comp);
                //La primera vez
                if(comp == -1) 
                    maximo = minimo = tam;
                else    {
                    if(tam > maximo)    {
                        maximo = tam;
                        comp_max = comp;
                    }
                    else if(tam < minimo)   {
                        minimo = tam;
                        comp_min = comp;
                    }
                }
                //Guardamos en mapa de componentes
                comp_sizes[comp] = tam;
                //Cambiamos de componente
                comp--;
            }
        }
    }
    //Terminamos el tiempo
    clock_t end = clock();

    //Aquí ya tenemos toda la información, ahora solo imprimir y generar imagen
    //Imprimimos lo solicitado
    cout << "El número de componentes conexas es: " << comp_sizes.size() << endl;
    cout << "El tiempo realizado por el algoritmo: " << (double)(end-start)/CLOCKS_PER_SEC << " s\n";
    cout << "Los tamaños de cada componenete son:\n";
    int comp_num = 1;
    for(auto it=comp_sizes.begin(); it!=comp_sizes.end(); it++) 
        cout << "Componenete " << comp_num++ << ": " << it->second << endl;
    
    //Guardamos una nueva imagen con los elementos máximos y mínimos
    cout << "Generando imagen con las componentes de menor y mayor tamaño : ("\
         << minimo << ", " << maximo << ") ...\n"; 
    generateMaxMinImg(mat, comp_min, comp_max);
    cout << "Listo.\n";
    
    return;
}

int main(int narg, char *varg[])  {
    if(narg < 3)    {
        printf("Error, debes dar como argumento el nombre de la imagen.pgm de entrada y de salida\n");
        exit(1);
    }
    
    //Matriz de la imagen
    vector< vector<int> > imgMat = getImgMatrix(varg[1]);
    
    //Verificamos si todos los pixeles son blanco y negros
    verify(&imgMat);
    
    //Colocamos global el nombre del archivo de salida
    output_file = varg[2];
    
    //Lanzamos algoritmo y resultados 
    connectedComponents(&imgMat);
    
    return 0;
}
