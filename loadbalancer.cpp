
#include <iostream>
// #include "request.cpp"
#include "generateIP.cpp"
#include "webserver.cpp"
#include <queue>
#include <vector>
using namespace std;


class loadBalancer {

    queue<webServer> webservers;
    queue<request*> requestqueue;
    vector<webServer> busyservers;

    int time = 27;
    int maxwebserverq = 0;
    
    public:
    void setupservers (int num){//setting up all the required servers

        
        webServer* serverobjects= new webServer[num]; 

        for (int i = 0; i < num; i++)
        {
            // serverobjects[i].id = i;
            *(&(serverobjects[i]).id) = (i);
            webservers.push(serverobjects[i]);
            // cout<<&(serverobjects[i])<<*(&(serverobjects[i]).id)<<endl;       
        }
        delete[] serverobjects;

        printq(webservers);
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
        
        // int i = 0;
        // while ((!requestqueue.empty()) && time > 0)    
        // {
            
        
        //     request currreq = *(requestqueue.front());
        //     requestqueue.pop();


        //     webServer currserver = webservers.front();
        //     webservers.pop();

        //     currserver.processreq(currreq,busyservers,  i,webservers );
        //     // webservers.push(currserver);
            
        //     time--;
        //     i++;

            

        // ///////////////For loop


        for (int currtime = 0; currtime < time; currtime++)
        {
            
            if (!requestqueue.empty()){//we have requests

                if (!webservers.empty()){//we have servers avaialble

                    webServer currwebserver =  webservers.front();
                    request* currrequest = requestqueue.front();

                    currwebserver.returntime = currtime + currrequest->time;
                    currwebserver.currreq = currrequest;
                    busyservers.push_back(currwebserver);

                    webservers.pop();
                    requestqueue.pop();

                }
                

                
                
            }
            updateservers(currtime);
        }
        for (int i = 0; i < busyservers.size(); i++)
        {
            cout<<busyservers.at(i).id<<endl;
        }
        
        





        
        // printq(webservers);
        // printlst(busyservers);
        
    }

    void updateservers(int currtime){

        vector<webServer> temp_busyservers;
        // printq(webservers);
        // printlst(busyservers);
        for (int i = 0; i < busyservers.size(); i++)
        {
            if (currtime == busyservers.at(i).returntime){
                cout<<"Time: "<<currtime<<" server id: "<<busyservers.at(i).id<<" is done since return time is "<<busyservers.at(i).returntime<<endl;
                busyservers.at(i).processreq(currtime);
                webservers.push(busyservers.at(i));
            }
            else{
                temp_busyservers.push_back(busyservers.at(i));
            }

        }
        
        busyservers = temp_busyservers;

    }

    void printq(queue<webServer> q){//print function for debugging

        cout<<"\n\n"<<"*****************FROM LOADBALANCER Ready************\n\n";
        while (!q.empty()){
		cout<<&(q.front())<<" "<<q.front().id<<" "<<endl;
		q.pop();
        }
        cout<<endl;
    }

    void printlst(vector<webServer> serverlist){

        cout<<"\n\n"<<"*****************FROM LOADBALANCER Busy************\n\n";
        for (int i = 0; i < serverlist.size(); i++)
            {
                cout<<serverlist.at(i).id<<" return time is "<<" "<<serverlist.at(i).returntime<<endl;
            }
    }



};


int main () {


    loadBalancer mybalancer;

    // mybalancer.time = 100;
    mybalancer.setupservers(10);
    mybalancer.setuprequests(20);
    mybalancer.start();
    
    return 0;
}