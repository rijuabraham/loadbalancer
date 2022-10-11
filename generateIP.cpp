

#include <iostream>
#include <random>
#include <string> 

using namespace std;


string generateIP (){

    string IP = "";

    for (int i = 0; i < 3; i++)
    {
        int val = rand() % 255;
        IP+= to_string(val);
        if (i < 2){
            IP+=".";
        }  
    }
    

    return IP;

}