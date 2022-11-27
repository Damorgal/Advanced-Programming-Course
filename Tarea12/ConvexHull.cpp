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
#include <cmath>

using namespace std;

//col1 debe ser menor que col2
//col3 es color de la línea
#define col1 0
#define col2 255
#define col3 120

string output_file = "";

/*********************** Clases ******************************/

class point {
private: 
    int x,y;
public:
    point(void) {x=0; y=0;}
    point(int p1, int p2) {
        x = p1;
        y = p2;
    }
    int getx() {return x;}
    int gety() {return y;}
    void print()    {cout << "(" << x << ", " << y << ")\n";}
};

class line    {
private:
    point a,b;
public:
    line(point p1, point p2)    {
        a = p1;
        b = p2;
    }
    line(int p1x, int p1y, int p2x, int p2y)    {
        a = point(p1x, p1y);
        b = point(p2x, p2y);
    }
    void draw(vector< vector<int> > *mat);
};

//Dibuja una línea usando el algoritmo de Bresenham
void line::draw(vector<vector<int> >* mat) {
    int x,y,dx,dy,dx1,dy1,px,py,xe,ye;
    dx = b.getx()-a.getx(); 
    dy = b.gety()-a.gety(); 
    dx1 = fabs(dx); 
    dy1 = fabs(dy); 
    px = 2*dy1-dx1; 
    py = 2*dx1-dy1; 
    if(dy1 <= dx1)    { 
        if(dx >= 0) { 
            x = a.getx(); 
            y = a.gety(); 
            xe = b.getx(); 
        } 
        else    { 
            x = b.getx(); 
            y = b.gety(); 
            xe = a.getx(); 
        } 
        
        //Pintamos el pixel inicial
        (*mat)[x][y] = col3;
        
        //Pintamos la línea
        for(int i=0; x<xe; i++) { 
            x++; 
            if(px < 0) 
                px += 2*dy1; 
            else    { 
                if((dx<0 && dy<0) || (dx>0 && dy>0)) 
                    y++; 
                else 
                    y--; 
                px += 2*(dy1-dx1); 
            }  
            //Pintamos el pixel
            (*mat)[x][y] = col3;
        } 
    } 
    else    { 
        if(dy >= 0) { 
            x = a.getx(); 
            y = a.gety(); 
            ye = b.gety(); 
        } 
        else    { 
            x = b.getx(); 
            y = b.gety(); 
            ye = a.gety(); 
        } 
        //Pintamos el pixel
        (*mat)[x][y] = col3;
        
        //Pintamos línea
        for(int i=0; y<ye; i++)   { 
            y++; 
            if(py <= 0) 
                py += 2*dx1; 
            else    { 
                if((dx<0 && dy<0) || (dx>0 && dy>0)) 
                    x++;
                else 
                    x--;
                py += 2*(dx1-dy1); 
            } 
            //Pintamos el pixel
            (*mat)[x][y] = col3;
        } 
    } 
}

//La clase consiste en una vector de puntos donde puntos consecutivos son una línea
class convexHull    {
private:
    vector<point> ch;
public:
    void add(point p)   {ch.push_back(p); return;}
    void draw(vector< vector<int> > *mat);
    point last()    {return ch[ch.size()-1];}
    void print();
};

void convexHull::print()    {
    cout << "Puntos que conforman la Convex Hull:\n";
    for(int i=0; i<ch.size(); i++)
        ch[i].print();
}

void convexHull::draw(vector< vector<int> > *mat) {
    for(int i=1; i<ch.size(); i++)  {
        line l(ch[i-1], ch[i]);
        l.draw(mat);
    }
}

/*********************** Funciones *****************************/

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
    for( long int i=1, j=1; i<=n; i++, j++)  {
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

void generateImg(vector< vector<int> > *mat, convexHull *ch)    {
    int ancho = (*mat)[0].size();
    int alto = mat->size();
    
    //Agregamos las lineas del convex hull
    ch->draw(mat);
    
    //Colocamos información general de la imagen
    ofstream img(output_file);
    img << "P2\n#Imagen generada por Diego Moreno para la tarea 12 PA. (Convex Hull).\n";
    img << "#Formato PGM (P2) que contiene las componentes de longitud mínima y máxima\n";
    img << ancho << " " << alto << "\n255\n";
    
    //Escribimos la imagen
    for(int i=0; i<alto; i++)  { 
        for(int j=0; j<ancho; j++)  {
            img << (*mat)[i][j] << endl;
        }
    }
    
    //Cerramos la imagen
    img.close();
}

//Función que encuentra el contorno de las componentes conexas
//También encuentra los "hoyos" de la figura, sin embargo no es
//perjudicial para el fin de la convex hull.
vector<point> contour(vector< vector<int> > *mat)   {
     int ancho = (*mat)[0].size();
     int alto = mat->size();
    vector<point> pts;
    for(int i=0; i<alto; i++)    {
        for(int j=0; j<ancho; j++)  {
            if((*mat)[i][j] == col2)  {
                if((i==0) || (j==0) ||\
                (i>0 && (*mat)[i-1][j]==col1) ||\
                (j>0 && (*mat)[i][j-1]==col1) ||\
                (i+1<alto && (*mat)[i+1][j]==col1) ||\
                (j+1<ancho && (*mat)[i][j+1]==col1))    {
                    pts.push_back(point(i,j));
                }
            }
        }
    }
    return pts;
}

//Funcion de comparación por coordenada y de puntos
bool comparePointY(point a, point b)    {
    //En caso de empate, ordenar por x
    if(a.gety() < b.gety())
        return true;
    else if(a.gety() == b.gety())
        return (a.getx() < b.getx());
    else
        return false;
}

bool isEqual(point a, point b)  {
    return (a.getx()==b.getx() && a.gety()==b.gety());
}

void findConvexHull(vector< vector<int> > *mat)    {
    //Contamos tiempo del algoritmo
    clock_t start = clock();
    //Pasamos matriz a vector de puntos O(n*m) y nos qedamos con el contorno
    //Esto reducirá drásticamente el número de operaciones
    vector<point> pts = contour(mat);
    
    //Primero encontramos el mínimo en y (x en caso de empate) y máximo.
    //Es decir, usaremos la técnica izquierda-derecha
    point pmin=pts[0], pmax=pts[0];
    int idxmin=0, idxmax=0;
    for(int i=1; i<pts.size(); i++) {
        if(comparePointY(pts[i],pmin))  {
            pmin = pts[i];
            idxmin = i;
        }
        else if(comparePointY(pmax,pts[i])) {
            pmax = pts[i];
            idxmax = i;
        }
    }
    
    convexHull chull;
    chull.add(pmin);
    
    //Encontramos los puntos con ángulo menor hasta llegar al máximo
    int lastidx = idxmin;
    double aux, minangle;
    while(!isEqual(pmax, chull.last()))  {
        //Buscamos entre todos los puntos
        minangle = 7.0; //Mayor a 2pi necesario
        for(int i=0; i<pts.size(); i++) {
            if(i != lastidx)    {
                //Los angulos de busqueda serán entre [0,2pi] buscando el menor
                if(pts[i].gety() == pts[lastidx].gety())    {
                    if(pts[i].getx()-pts[lastidx].getx() > 0)
                        aux = 0.0;
                    else
                        aux = -(double)M_PI;
                }
                else
                    aux = atan2((double)(pts[i].gety()-pts[lastidx].gety()), \
                                (double)(pts[i].getx()-pts[lastidx].getx()));
                //Debemos hacer la trasformación al [0,2pi]
                if(aux < 0.0)
                    aux = 2.0*M_PI + aux;
                //Ponemos "<=" para que se salte los puntos colineales
                if(aux <= minangle)  {
                    minangle = aux;
                    idxmin = i;
                }
            }
        }
        //Agregamos el punto a la convex hull
        lastidx = idxmin;
        chull.add(pts[lastidx]);
    }
    
    //Lo mismo pero ahora de derecha a izquierda
    while(!isEqual(pmin, chull.last()))  {
        //Buscamos entre todos los puntos
        minangle = 4.0; //Mayor a pi necesario
        for(int i=0; i<pts.size(); i++) {
            if(i != lastidx)    {
                //Los angulos de busqueda serán entre [-pi,pi] buscando el menor
                if(pts[i].gety() == pts[lastidx].gety())    {
                    if(pts[i].getx()-pts[lastidx].getx() > 0)
                        aux = 0.0;
                    else
                        aux = -(double)M_PI;
                }
                else
                    aux = atan2((double)(pts[i].gety()-pts[lastidx].gety()), \
                                (double)(pts[i].getx()-pts[lastidx].getx()));
                //Ponemos solo menor para que se salte los colineales
                if(aux < minangle)  {
                    minangle = aux;
                    idxmin = i;
                }
            }
        }
        //Agregamos el punto a la convex hull
        lastidx = idxmin;
        chull.add(pts[lastidx]);
    }
    //Terminamos el tiempo
    clock_t end = clock();

    //Aquí ya tenemos toda la información, ahora solo imprimir y generar imagen
    //Imprimimos lo solicitado
    cout << "El tiempo realizado por el algoritmo: " << (double)(end-start)/CLOCKS_PER_SEC << " s\n";
    //Los puntos de la envolvente convexa
    chull.print();
    
    //Guardamos una nueva imagen con los elementos máximos y mínimos
    cout << "Generando imagen con la convex hull...\n"; 
    generateImg(mat, &chull);
    cout << "Listo.\n";
    
    return;
}

int main(int narg, char *varg[])  {
    if(narg < 2)    {
        printf("Error, debes dar como argumento el nombre de la imagen.pgm de entrada y (opcional) de salida \n");
        exit(1);
    }
    
    //Matriz de la imagen
    vector< vector<int> > imgMat = getImgMatrix(varg[1]);
    
    //Verificamos si todos los pixeles son blanco y negros
    verify(&imgMat);
    
    //Colocamos global el nombre del archivo de salida
    output_file = narg > 2 ? varg[2] : "output_" + string(varg[1]);
    
    //Lanzamos algoritmo y resultados 
    findConvexHull(&imgMat);
    
    return 0;
}
