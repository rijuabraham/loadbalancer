
#include <iostream>
// #include "request.cpp"
// #include "generateIP.cpp"
#include "webserver.cpp"
#include <queue>
using namespace std;


class loadBalancer {

    queue<webServer> webservers;
    queue<request> requestqueue;
    int maxwebserverq = 0;

    public:
    void setupservers (int num){

        maxwebserverq = num * 2;
        webServer* serverobjects= new webServer[num]; 

        for (int i = 0; i < num; i++)
        {
            serverobjects[i].id = i;
            webservers.push(serverobjects[i]);
            cout<<&(serverobjects[i])<<endl;       
        }

        
    void setuprequests(int num)

    }



};


int main () {


    loadBalancer mybalancer;

    mybalancer.setupservers(10);
    return 0;
}