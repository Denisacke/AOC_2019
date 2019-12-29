#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("input.txt");
struct object{
    char name[10];
    object* prev;
};
///string s;
char s[1001];
object* Obj[10001];
object* root;
object* previous[10001];
object* previous1[10001];
int main(){
    int k = 0;
    while(!fin.eof()){
        fin >> s;
        if(fin.eof())
            break;
        char *p = strtok(s, ")");
        ///cout << p << ")";
        int pos = -1, pos1 = -1;
        bool OK = 0;
        for(int i = 0; i < k; i++)
            if(strcmp(Obj[i]->name, p) == 0){
                OK = 1;
                pos = i;
                break;
            }
        if(!OK){
            Obj[k] = new object;
            strcpy(Obj[k]->name, p);
            pos = k;
            k++;
        }
        if(strcmp("COM", Obj[pos]->name) == 0)
            root = Obj[pos];
        p = strtok(NULL, "\0");
        ///cout << p << '\n';
        OK = 0;
        for(int i = 0; i < k; i++)
            if(strcmp(Obj[i]->name, p) == 0){
                OK = 1;
                pos1 = i;
                break;
            }
        if(!OK){
            Obj[k] = new object;
            strcpy(Obj[k]->name, p);
            pos1 = k;
            k++;
        }
        Obj[pos1]->prev = Obj[pos];

    }
    int index = 0, index1 = 0;
    for(int i = 0; i < k; i++)
        if(strcmp(Obj[i]->name, "YOU") == 0){
            object* aux = Obj[i];
            while(aux->prev != root){
                previous[index] = aux;
                index++;
                aux = aux->prev;
            }
            previous[index] = root;
    }
    for(int i = 0; i < k; i++)
        if(strcmp(Obj[i]->name, "SAN") == 0){
            object* aux = Obj[i];
            while(aux->prev != root){
                previous1[index1] = aux;
                index1++;
                aux = aux->prev;
            }
            previous1[index1] = root;
    }
    for(int i = 0; i <= index; i++)
        cout << previous[i]->name << '\n';
    int sum = 0;
    bool OK = 0;
    for(int i = 1; i <= index; i++){
        for(int j = 1; j <= index1; j++){
            if(strcmp(previous[i]->name, previous1[j]->name) == 0){
                sum = i + j - 2;
                OK = 1;
                break;
            }
        }
        if(OK)
            break;
    }

    cout << sum;
    return 0;
}
