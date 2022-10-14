
#ifndef webserver_h
#define memory_h

#include <iostream>
#include "request.cpp"
// #include "generateIP.cpp"
#include <queue>
#include <vector>
using namespace std;



/**
 * @brief A webserver class with required attributes to process requests
 * 
 * 
 */

class webServer {

    public:
    


        int status = 0;//!<@brief to check idf the webserver is busy or available
        int id = -1;//!<unique id for the webserver
        int returntime = -1; //!<time when server will be done with the request if busy
        request* currreq; //!< stores the request that te server is processing
        


        //! 
        /*! This function prints out the time and in and out IP of the requests
        
        \param currtime the current time 

        */
         
        void processreq (int currtime) ;
    

        //!
        /*!It takes in busyservers and avaialable queue of webservers and it checks if any server is ready if so it processes it by calling processreq() and updates it by adding it to the available webserver queue.
            \param currtime the current time 
            \param busyservers a vector of all the busy servers
            \param webservers a queue of all the avaiallble servers
        */
     


        
        
        static void updateservers(int currtime, vector<webServer>& busyservers, queue<webServer>& webservers);

     
        



};

#endif



