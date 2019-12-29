#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;
ifstream fin("input.txt");
char a[2001][2001];
struct{
int x, y;
}pos[10001], sum[10001][10001], position;
int main(){
    char c[2001];
    int k = 0;
    int indexi = 0;
    while(fin >> c){
        strcpy(a[indexi], c);
        indexi++;
        if(fin.eof())
            break;
    }
    for(int i = 0; i < indexi; i++){
        for(int j = 0; j < indexi; j++)
            if(a[i][j] == '#'){
                pos[k].x = j;
                pos[k].y = i;
                k++;
            }
    }
    for(int i = 0; i < k; i++)
        cout << pos[i].x << " " << pos[i].y << '\n';
    cout << '\n';
    int counter = 0, Max = -1;
    for(int i = 0; i < k; i++){
        cout << "Asteroid " << i << " with positions " << pos[i].x << " " << pos[i].y << '\n';
        for(int j = 0; j < k; j++){
            sum[i][j].x = (pos[i].x + pos[j].x);
            sum[i][j].y = (pos[i].y + pos[j].y) / 2;
            cout << sum[i][j].x << " " << sum[i][j].y << '\n';
        }
        cout << "\n";
    }
    for(int i = 0; i < k; i++){
        counter = 0;
        for(int j = 0; j < k; j++){
            bool OK = 1;
            for(int l = 1; l < k; l++){
                if(abs(pos[l].x - pos[j].x) == abs(pos[i].x - pos[j].x) && abs(pos[l].y - pos[j].y) == abs(pos[i].y - pos[j].y)){
                    OK = 0;
                    break;
                }
            }
            if(OK)
                counter++;
        }
        cout << counter << '\n';
        if(counter > Max)
            Max = counter;
    }
    /*for(int i = 0; i < k; i++){
        counter = 0;
        for(int j = 0; j < k; j++){
            bool OK = 1;
            for(int l = j; l < k; l++)
                if((pos[l].x == sum[i][j].x) && (pos[l].y == sum[i][j].y) && (abs(pos[l].x - pos[i].x + pos[l].y - pos[i].y) != 1)){
                    cout << i << " not linked with " << l << '\n';
                    OK = 0;
                    break;
                }
            if(OK){
                cout << "Asteroid " << i << " is linked with asteroid " << j << '\n';
                counter++;
            }

        }
        cout << counter << "\n\n";
        if(counter > Max){
            position.x = pos[i].x;
            position.y = pos[i].y;
            Max = counter;
        }

    }*/
    cout << Max << " " << position.x << " " << position.y;
    return 0;
}
