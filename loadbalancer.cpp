
#include <iostream>
// #include "request.cpp"
#include "generateIP.cpp"
#include "webserver.cpp"
#include <queue>
using namespace std;


class loadBalancer {

    queue<webServer> webservers;
    queue<request*> requestqueue;
    int time = 100;
    int maxwebserverq = 0;

    public:
    void setupservers (int num){//setting up all the required servers

        
        webServer* serverobjects= new webServer[num]; 

        for (int i = 0; i < num; i++)
        {
            // serverobjects[i].id = i;
            webservers.push(serverobjects[i]);
            cout<<*(&(serverobjects[i]).id)<<endl;       
        }

        
    }

    void setuprequests(int num) {//setting up the request queue
        maxwebserverq = num;
        for (int i = 0; i < maxwebserverq; i++)
        {
            request* tempreq = new request;

            requestqueue.push(tempreq);

        }    

        this->printq(requestqueue);
    }
    void printq(queue<request*> q){//print function for debugging


        while (!q.empty()){
		cout<<(q.front())<<" "<<(q.front())->time<<" "<<(q.front())->inIP<<endl;
		q.pop();
        }

    }

    void start () {

        // int num_rand_req = rand() % requestqueue.size();
        // for (int i = 0; i < num_rand_req; i++)// creating random request
        // {
            
        // }
        
        while ((!requestqueue.empty()) && time > 0 )    
        {
            
        
            request currreq = *(requestqueue.front());
            requestqueue.pop();
            webServer currserver = webservers.front();

            currserver.processreq(currreq,webservers);
            time--;

        }
    }
    



};


int main () {


    loadBalancer mybalancer;

    // mybalancer.time = 100;
    mybalancer.setupservers(10);
    mybalancer.setuprequests(10);
    mybalancer.start();
    
    return 0;
}