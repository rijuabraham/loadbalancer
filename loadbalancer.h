
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


/*! \mainpage Loadbalancer
 *
 * \section intro_sec Introduction
 *
 * A loadbalancer that manages requestsqueue and webservers and process the request accordingly
 *
 */

/**
 * @brief A loadbalancer class also the main class with required attributes to keep track of the webservers and the request queue
 * 
 * 
 */


class loadBalancer {

    public:
    queue<webServer> webservers;//!<@brief Keeps track of all webservers
    queue<request*> requestqueue;//!<@brief pointer queue of all requests
    vector<webServer> busyservers;//!<@brief a vector of all busy webservers processing requests

    int time = 1000;//!<@brief clock cycle
    
    
    public:


    //! 
    /*! It sets up the required number of servers pointers this is done using a for loop 

     \param num the number of required servers

    */
    void setupservers (int num);


    //! 
    /*! It sets up the required number of servers pointers done using a for loop
     \param num the number of required requests

    */
    void setuprequests(int num);
    
    //! 
    /*! It starts the clock if  requestqueue is not empty  it takes the request and it gives it to the avaialble webserver for processing 
    and it calls updateservers() to update the servers and check if the servers are done yet if so print it out.
     

    */
    void start ();

    




};