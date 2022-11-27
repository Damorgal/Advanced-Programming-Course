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

double delta_bp; 

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
        deltas.push_back(delta*grad);
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
    double lrate = .01;
    for(int i=1; (i==1 || total_error[total_error.size()-1]!=0) && i<=epochs && \
        (i<3||total_error[total_error.size()-1]!=total_error[total_error.size()-2]); i++)    {
        cout << "Epoch "<<i<<":\n";
        clock_t start = clock();
        total_error.push_back(0.);
        error.push_back(0.);
        pred.clear();
        for(int k=0; k<(int)ytrain.size(); k++) {
            double prediction = forward_propagation(xtrain[k]);
            pred.push_back(prediction);
            error[i-1] = (ytrain[k] - prediction);//*(ytrain[k] - prediction)/2;
            total_error[i-1] += fabs(error[i-1]);
            //Derivada de la función Sigmoid
            //int sgn = ytrain[k] - prediction < 0 ? -1 : 1;
            double delta = error[i-1] * prediction * (1.-prediction);
            backward_propagation(lrate, delta);
        }
        clock_t end = clock();
        cout<<"Error total = "<<total_error[i-1]<<endl;
        cout << "Tiempo de época: " << (double)(end-start)/CLOCKS_PER_SEC << " s\n\n";
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

int main(int num_args, char ** args){ 
    srand(time(nullptr)); 
    dataset data(args[1]); 
    int num_layers = atoi(args[2]); 
    vector<int> layer_sizes; 
    //Agregamos el primer tamaño que serán la cantidad de datos de entrada
    layer_sizes.push_back((int)data.x[0].size());
    layer_sizes.push_back((int)data.x[0].size());
    for(int i=0; i <num_layers; i++) 
        layer_sizes.push_back(atoi(args[3+i]));  
    //Agregamos el tamaño de la capa de salida
    layer_sizes.push_back(1);
    
    //Ejemplo de lectura correcta
    /*
    for(int i=34; i<40; i++)  {
        for(int j=0; j<data.x[i].size(); j++)
            cout << data.x[i][j] << " ";
        cout<<data.y[i]<<endl;
    }
    */

    //Contamos tiempo del algoritmo
    clock_t start = clock();
    neuralnetwork nn(num_layers+1, layer_sizes); 
    vector<double> errors = nn.train(5000, data.x, data.y); 
    
    //Terminamos el tiempo
    clock_t end = clock();
    cout<<"El error del entrenamiento: " <<errors[errors.size()-1]<<endl;
    cout << "El tiempo total del entrenamiento: " << (double)(end-start)/CLOCKS_PER_SEC << " s\n";
    errors.clear(); 
    
    return 0; 
}
