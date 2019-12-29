#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("input.txt");
char a[101][150001];
char c[150001];
char s[150001];
int main(){
    int indexi = 0, indexj = 0;
    fin >> c;
    bool OK = 0;
    int i;
    for(i = 0; c[i] != '\0'; i++){
        a[indexi][indexj] = c[i];
        if(indexj != 149)
            indexj++;
        else{
            indexj = 0;
            indexi++;
            if(indexi == 101){
                ///cout << i << '\n';
                break;
            }

        }
    }
    for(int i = 0; i < 150; i++){
        int Min = '3';
        for(int j = 0; j < 100; j++){
            if(a[j][i] != '2' && Min == '3')
                Min = a[j][i];
        }
        s[i] = Min;
    }
    for(int i = 0; i < 150; i++)
        if(s[i] == '1')
            cout << '#';
        else
            cout << ' ';
    /*int Min = 100000000;
    int pos;
    int k;
    for(int i = 0; i < 100; i++){
        k = 0;
        for(int j = 0; j < 150; j++){
            if(a[i][j] == '0')
                k++;
        }
        if(k < Min){
            Min = k;
            pos = i;
        }
    }
    int d1 = 0, d2 = 0;
    for(int j = 0; j < 150; j++)
        if(a[pos][j] == '1')
            d1++;
        else
            if(a[pos][j] == '2')
                d2++;
    cout << d1 * d2;*/
    return 0;
}
