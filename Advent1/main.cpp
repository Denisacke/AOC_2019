#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
int x;
int sum;
int main(){

    while(fin >> x){
        double d = x;
        while(d >= 0){
            d = d / 3;
            d = floor(d);
            d -= 2;
            if(d >= 0)
                sum += d;
        }

    }
    cout << sum;
    return 0;
}
