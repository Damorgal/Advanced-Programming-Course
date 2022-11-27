#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include<fstream>
#include <sstream>

using namespace std;

int main(int narg, char *varg[])  {
    
    // map declaration 
    map<int,string> mymap; 
      
    // mapping integers to strings 
    mymap[1] = "Hi"; 
    mymap[2] = "This"; 
    mymap[3] = "is"; 
    mymap[4] = "GeeksForGeeks"; 
      
    // using operator[] to print string  
    // mapped to integer 4 
    mymap.insert({10,"ASd"});
    auto it = mymap.find(14);
    if(it == mymap.end())
    cout << "hsdf";
    
    vector<int> v(5);
    v.push_back(2);
    v.push_back(1);
    cout<<v[5]<<" "<<v[6]<<endl<<endl<<endl;
    
    string s="Hi";
    map<string,int> mapa;
    mapa["hola"] = 3;
    mapa["hola"]+=3;
    cout<<mapa["hola"]<<" "<<s<<" "<<(mapa["gas"])<<endl;
    return 0;
}
