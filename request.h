
#include <iostream>
#include "generateIP.h"

using namespace std;


/**
 * @brief A request struct that contains inIP, outIP and the time required to process 
 * 
 * 
 */
struct request
{
    string inIP;//!<@brief inIP it calls the generateIP() function
    string outIP;//!<@brief outIP it calls the generateIP() function
    int time;//!<@brief the total time reuired to process the request

};
