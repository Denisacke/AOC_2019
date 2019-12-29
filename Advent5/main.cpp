#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
int v[100001];
int main(){
    int x;
    char c;
    int k = 0;
    while(fin >> x){
        fin >> c;
        v[k] = x;
        k++;
    }
    int var;
    int increment = 0;
    cout << k << '\n';
    for(int i = 0; i < k;){
        cout << v[i] << " " << i << '\n';
        if(v[i] == 1){
            v[v[i + 3]] = v[v[i + 1]] + v[v[i + 2]];
            increment += 4;
        }
        else
            if(v[i] == 2){
                v[v[i + 3]] = v[v[i + 1]] * v[v[i + 2]];
                increment += 4;
            }
            else
                if(v[i] == 3){
                    cout << "Input!\n";
                    cin >> var;
                    v[v[i + 1]] = var;
                    increment += 2;
                }
            else
                if(v[i] == 4){
                    cout << "Output is " << v[v[i + 1]] << '\n';
                    increment += 2;
                }
                else
                    if(v[i] == 5){
                        if(v[v[i + 1]])
                            increment = v[v[i + 2]];
                    }
                    else
                        if(v[i] == 6){
                            if(!v[v[i + 1]])
                                increment = v[v[i + 2]];
                        }
                        else
                            if(v[i] == 7){
                                if(v[v[i + 1]] < v[v[i + 2]])
                                    v[v[i + 3]] = 1;
                                else
                                    v[v[i + 3]] = 0;
                                increment += 4;
                            }
                            else
                                if(v[i] == 8){
                                    if(v[v[i + 1]] == v[v[i + 2]])
                                        v[v[i + 3]] = 1;
                                    else
                                        v[v[i + 3]] = 0;
                                    increment += 4;
                                }
                                else
                                    if(v[i] == 99){
                                        ///cout << v[0] << " " << v[v[1]];
                                        return 0;
                                    }
                                    else
                                        if(v[i] == 0){
                                            cout << "Success\n";
                                            increment++;
                                        }
                                        else
                                            if(v[i] >= 100){
                                                int aux = v[i];
                                                int instruction[1];
                                                int p[5], index = 0;
                                                for(int j = 0; j < 5; j++)
                                                    p[j] = 0;
                                                instruction[0] = aux % 10;
                                                aux /= 10;
                                                instruction[1] = aux % 10;
                                                aux /= 10;
                                                while(aux){
                                                    p[index] = aux % 10;
                                                    index++;
                                                    aux /= 10;
                                                }
                                                if(instruction[0] == 1 && instruction[1] == 0){
                                                    increment += 4;
                                                    int sum = 0;
                                                    for(int j = 0; j < 2; j++){
                                                        if(p[j] == 0)
                                                            sum += v[v[i + j + 1]];
                                                        else
                                                            sum += v[i + j + 1];
                                                    }
                                                    v[v[i + 3]] = sum;
                                                }
                                                else
                                                    if(!instruction[1] && !instruction[0]){
                                                        cout << "Success\n";
                                                        increment++;
                                                    }
                                                    else
                                                        if(instruction[1] == 0 && instruction[0] == 2){
                                                            increment += 4;
                                                            int sum = 1;
                                                            for(int j = 0; j < 2; j++){
                                                                if(p[j] == 0)
                                                                    sum *= v[v[i + j + 1]];
                                                                else
                                                                    sum *= v[i + j + 1];
                                                            }
                                                            v[v[i + 3]] = sum;
                                                        }
                                                        else
                                                            if(instruction[1] == 9 && instruction[0] == 9){
                                                                cout << "Program terminated!\n";
                                                                return 0;
                                                            }
                                                        else
                                                            if(instruction[1] == 0 && instruction[0] == 4){
                                                                if(p[0] == 0)
                                                                    cout << "Output is " << v[v[i + 1]] << '\n';
                                                                else
                                                                    cout << "Output is " << v[i + 1] << '\n';
                                                                increment += 2;
                                                            }
                                                        else
                                                            if(instruction[1] == 0 && instruction[0] == 5){
                                                                if(p[0] == 0){
                                                                    if(v[v[i + 1]]){
                                                                        if(p[1] == 0)
                                                                            increment = v[v[i + 2]];
                                                                        else
                                                                            increment = v[i + 2];
                                                                    }
                                                                    else
                                                                        increment += 3;
                                                                }
                                                                else{
                                                                    if(v[i + 1]){
                                                                        if(p[1] == 0)
                                                                            increment = v[v[i + 2]];
                                                                        else
                                                                            increment = v[i + 2];
                                                                    }
                                                                    else
                                                                        increment += 3;
                                                                }
                                                                ///cout << "increment is " << increment << '\n';
                                                            }
                                                        else
                                                            if(instruction[1] == 0 && instruction[0] == 6){
                                                                 if(p[0] == 0){
                                                                    if(!v[v[i + 1]]){
                                                                        if(p[1] == 0)
                                                                            increment = v[v[i + 2]];
                                                                        else
                                                                            increment = v[i + 2];
                                                                    }
                                                                    else
                                                                        increment += 3;
                                                                }
                                                                else{
                                                                    if(!v[i + 1]){
                                                                        if(p[1] == 0)
                                                                            increment = v[v[i + 2]];
                                                                        else
                                                                            increment = v[i + 2];
                                                                    }
                                                                    else
                                                                        increment += 3;
                                                                }
                                                            }
                                                        else
                                                            if(instruction[1] == 0 && instruction[0] == 7){
                                                                int a, b;
                                                                if(p[0] == 1)
                                                                    a = v[i + 1];
                                                                else
                                                                    a = v[v[i + 1]];

                                                                if(p[1] == 1)
                                                                    b = v[i + 2];
                                                                else
                                                                    b = v[v[i + 2]];

                                                                if(a < b)
                                                                    v[v[i + 3]] = 1;
                                                                else
                                                                    v[v[i + 3]] = 0;


                                                                increment += 4;
                                                            }
                                                        else
                                                            if(instruction[1] == 0 && instruction[0] == 8){
                                                                int a, b;
                                                                if(p[0] == 1)
                                                                    a = v[i + 1];
                                                                else
                                                                    a = v[v[i + 1]];

                                                                if(p[1] == 1)
                                                                    b = v[i + 2];
                                                                else
                                                                    b = v[v[i + 2]];

                                                                if(a == b)
                                                                    v[v[i + 3]] = 1;
                                                                else
                                                                    v[v[i + 3]] = 0;
                                                                increment += 4;
                                                            }
                                            }
                i = increment;
    }
    return 0;
}
