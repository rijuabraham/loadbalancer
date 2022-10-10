

#include <iostream>
#include "request.cpp"
#include "generateIP.cpp"
#include <queue>
using namespace std;

class webServer {

    public:
        int status = 0; //0 - avail, 1 - busy
        string id = "";
        
    
        void processreq(request req) {

            this->status = 1;
            
            cout<<this->id<<" Processed request: "<<req.inIP<<" to "<<generateIP()<<endl;

            this->status = 0 ;

        }

        
    

    






};
