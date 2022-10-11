
#include <iostream>

using namespace std;

struct request
{
    string inIP = generateIP();
    int time = rand() % 5 +1;

};
