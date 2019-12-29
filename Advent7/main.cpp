#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
int v[100001], aux[100001];
int perm[200][200];
int counter;
int test[] = {5, 6, 7, 8, 9};
void permute(int v[], int l, int r)  {
    // Base case
    if (l == r){
        for(int i = 0; i < 5; i++)
            perm[counter][i] = v[i];
        counter++;
    }

    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(v[l], v[i]);

            // Recursion called
            permute(v, l+1, r);

            //backtrack
            swap(v[l], v[i]);
        }
    }
}
int main(){
    int x;
    char c;
    int k = 0;
    while(fin >> x){
        fin >> c;
        v[k] = x;
        k++;
    }
    permute(test, 0, 4);
    for(int i = 0; i < k; i++)
        aux[i] = v[i];
    int var = 0, Max = -1;
    int increment = 0;
    int indexi = 0, indexj = 0;
    int exch = 0;
    while(indexi != counter){
        if(indexj == 5){
            var = 0;
            indexi++;
            indexj = 0;
        }
        for(int i = 0; i < k; i++)
            v[i] = aux[i];
        increment = 0;
        exch = 0;
        bool Halt = 0;
        for(int i = 0; i < k;){
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
                    cout << "Input! ";
                    if(!exch){
                        exch = 1;
                        v[v[i + 1]] = perm[indexi][indexj];
                        indexj++;
                    }
                    else
                        v[v[i + 1]] = var;
                    increment += 2;
                    cout << v[v[i + 1]] << '\n';
                }
            else
                if(v[i] == 4){
                    var = v[v[i + 1]];
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
                                        cout << indexi << " " << indexj << '\n';
                                        ///cout << v[0] << " " << v[v[1]];
                                        break;
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
                if(var > Max)
                    Max = var;
                i = increment;
    }
    }
    cout << Max;
    return 0;
}
