#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
int a[1001][1001], v[10001], aux[10001];
int main(){
    int x;
    char c;
    int column = 0, row = 0;
    int k = 0;
    int coun = 0;
    while(fin >> x){
        fin >> c;
        aux[k] = x;
        v[k++] = x;
    }
   /* v[1] = 0;
    v[2] = 0;
    while(v[1] != 100){
        v[0] = 1;
        for(int i = 3; i < k; i++)
            v[i] = aux[i];
        cout << v[1] << " " << v[2] << '\n';
        for(int i = 0; i < k; i += 4){
            if(v[i] == 1){
                v[v[i + 3]] = v[v[i + 1]] + v[v[i + 2]];
            }
            else
                if(v[i] == 2){
                    v[v[i + 3]] = v[v[i + 1]] * v[v[i + 2]];
                }
                else
                    if(v[i] == 99){
                        if(v[0] == 19690720){
                            cout << v[1] << " " << v[2];
                            return 0;
                        }
                       /// cout << v[0] << '\n';
                        coun++;
                        break;
                    }
        }
            v[2]++;
            if(v[2] == 100){
                v[2] = 0;
                v[1]++;
            }
            if(v[1] == 100){
                cout << "Program doesn't work :(";
                return 0;
            }
           /// cout << v[1] << " " << v[2] << '\n';
        }*/
   /// cout << v[1] << " " << v[2];   12490719

    for(int i = 0; i < k; i += 4){
        if(v[i] == 1){
            v[v[i + 3]] = v[v[i + 1]] + v[v[i + 2]];
        }
        else
            if(v[i] == 2){
                v[v[i + 3]] = v[v[i + 1]] * v[v[i + 2]];
            }
            else
                if(v[i] == 99){
                    cout << v[0] << " " << v[v[1]];
                    return 0;
                }
                else
                    cout << "wrong input";
    }


    return 0;
}
