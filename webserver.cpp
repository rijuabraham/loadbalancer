

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

        static void updateservers(int currtime, vector<webServer>& busyservers, queue<webServer>& webservers){

        vector<webServer> temp_busyservers;
        // printq(webservers);
        // printlst(busyservers);
        for (int i = 0; i < busyservers.size(); i++)
        {
            if (currtime == busyservers.at(i).returntime){
                // cout<<"Time: "<<currtime<<" server id: "<<busyservers.at(i).id<<" is done since return time is "<<busyservers.at(i).returntime<<endl;
                busyservers.at(i).processreq(currtime);
                webservers.push(busyservers.at(i));
            }
            else{
                temp_busyservers.push_back(busyservers.at(i));
            }

        }
        
        busyservers = temp_busyservers;

    }


    

    






};
