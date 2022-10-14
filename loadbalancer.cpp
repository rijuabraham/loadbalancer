
#include <iostream>
// #include "request.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generateIP.cpp"
#include "webserver.cpp"
#include <queue>
#include <vector>
#include<cstdio>

using namespace std;


class loadBalancer {

    queue<webServer> webservers;
    queue<request*> requestqueue;
    vector<webServer> busyservers;

    public:
    int time = 10000;
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

        // printq(webservers);
        cout<<"starting webserver Size: "<<webservers.size()<<endl;
    }

    void setuprequests(int num) {//setting up the request queue
        maxwebserverq = num;
        for (int i = 0; i < maxwebserverq; i++)
        {
            request* tempreq = new request;

            requestqueue.push(tempreq);
            

        }    
        

        // this->printq(requestqueue);
        cout<<"starting request size: "<<requestqueue.size()<<endl;
    }
    void printq(queue<request*> q){//print function for debugging


        while (!q.empty()){
		cout<<(q.front())<<" "<<(q.front())->time<<" "<<(q.front())->inIP<<endl;
		q.pop();
        }

    }

    void start () {

        
        
        int remtime;
        for (int currtime = 0; currtime < time; currtime++)
        {
             
            cout<<"\nTime is: "<<currtime<<endl;


            //Adding random requests
            if (rand() % 2 == 0){
                request* tempreq = new request;
                cout<<"Adding random request with inIP "<<tempreq->inIP<<"...\n";
                requestqueue.push(tempreq);
            }



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

            else if (requestqueue.empty() && busyservers.size() <= 0){
                cout<<"All request processed!!!!!!!\n";
                cout<<"Ending webserver size: "<<webservers.size()<<endl;
                cout<<"Ending requestqueue size: "<<requestqueue.size()<<endl;
                cout<<"Ending clock cycle: "<<currtime<<endl;
                break;
            }
            webServer::updateservers(currtime,busyservers,webservers);

            remtime = currtime;
        }

        if (busyservers.size() > 0) {cout<<"Ran out of time reminin servers are busy with requests\n";}
        for (int i = 0; i < busyservers.size(); i++)
        {
            
            cout<<busyservers.at(i).id<<" ";
        }
        cout<<endl;
        cout<<"Ending webserver size: "<<webservers.size()<<endl;
        cout<<"Ending requestqueue size: "<<requestqueue.size()<<endl;
        cout<<"Ending clock cycle: "<<remtime<<endl;
     
        
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


    freopen("result.txt","w",stdout);//couting to files Source: https://stackoverflow.com/questions/10150468/how-to-redirect-cin-and-cout-to-files
    srand(time(NULL));

    loadBalancer mybalancer;

    // mybalancer.time = 100;
    // cout<<rand()%rand()<<endl;

    mybalancer.setupservers(10);
    mybalancer.setuprequests(20);
    mybalancer.time = 10000;
    mybalancer.start();
    
    return 0;
}