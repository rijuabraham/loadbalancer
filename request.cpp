
#include <iostream>

using namespace std;

struct request
{
    string inIP = generateIP();
    string outIP = generateIP();
    int time = rand() % 10 +1;

};
