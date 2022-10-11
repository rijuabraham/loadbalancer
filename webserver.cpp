

#include <iostream>
#include "request.cpp"
// #include "generateIP.cpp"
#include <queue>
using namespace std;

class webServer {

    public:
        int status = 0; //0 - avail, 1 - busy
        string id = "h";
        
    
        void processreq(request req, queue<webServer> webq) {

            webServer currserver = webq.front();
            currserver.status = 1;
            webq.pop();

            this->status = 1;

            
            cout<<currserver.id<<" Processed request: "<<req.inIP<<" to "<<generateIP()<<" for "<<req.time<<endl;

            this->status = 0 ;
            webq.push(currserver);


        }


    

    






};
