#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;
int main() {
    time_t t;
    time(&t);
    cout<<t<<endl;
    sleep(5);
    time(&t);
    cout<<t<<endl;
    return 0;
}
