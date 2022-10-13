

#include <iostream>
#include "request.cpp"
// #include "generateIP.cpp"
#include <queue>
#include <vector>
using namespace std;

class webServer {

    public:
        int status = 0; //0 - avail, 1 - busy
        int id = -1;
        int returntime = -1;
        request* currreq;
        queue<webServer> runningServers;
        
    
        void processreq (int currtime) {

            cout<<"Time: "<<currtime<<" Server id: "<<this->id<<" processed "<<this->currreq->inIP<<
            " to "<<this->currreq->outIP<<endl;
            
            


        }

        void checkifcomplete (vector<webServer>& busyservers, int currtime, queue<webServer>& readyservers){

            for (int i = 0; i < busyservers.size(); i++)
            {
                
            }
            
        
            

            
        }


        void printq(queue<webServer> q,int currtime){//print function for debugging

            cout<<"\n\n"<<"*****************FROM WEBSERVER - Ready************\n\n";

        
            while (!q.empty()){
            cout<<"Time is: "<<currtime<<" "<<&(q.front())<<" "<<q.front().id<<" return time is "<<" "<<q.front().returntime<<endl;
            q.pop();
            }
            cout<<endl;

        }
        void printq(vector<webServer> serverlist,int currtime){//print function for debugging

            cout<<"\n\n"<<"*****************FROM WEBSERVERL************\n\n";


            for (int i = 0; i < serverlist.size(); i++)
            {
                cout<<"Time is: "<<currtime<<" "<<&(serverlist.at(i))<<" "<<serverlist.at(i).id<<" return time is "<<" "<<serverlist.at(i).returntime<<endl;
            }

    }


    

    






};
