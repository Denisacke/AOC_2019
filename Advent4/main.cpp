#include <iostream>
using namespace std;
int range = 805915 - 347312;
int duplicates[100];
int main(){
    int k = 0;
    bool duplicate = 0;
    bool increase = 1;
    int duplicateNumber;
    for(int i = 347312; i <= 805915; i++){
        int x = i;
        int y = x;
        duplicate = 0;
        increase = 1;
        duplicateNumber = 0;
        for(int j = 0; j < 100; j++)
            duplicates[j] = 0;
        int aux = x % 10;
        x /= 10;
        while(x){
            if(x % 10 == aux){
                duplicates[duplicateNumber]++;
                duplicate = 1;
            }
            else
                duplicateNumber++;
            if(x % 10 > aux){
                increase = 0;
                break;
            }
            aux = x % 10;
            x /= 10;
        }
        if(duplicate && increase){
            bool OK = 0;
            for(int j = 0; j <= duplicateNumber; j++)
                if(duplicates[j] == 1){
                    OK = 1;
                    break;
                }
            if(OK){
                cout << y << '\n';
                k++;
            }

        }

    }
    cout << k;
    return 0;
}
