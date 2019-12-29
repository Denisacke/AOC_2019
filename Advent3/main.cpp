#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("input.txt");
bool a[14001][14001];
int positions[14001][14001], positions1[14001][14001];
int sum = 0, sum1 = 0;
int main(){
    char instr = 1;
    int x = 7200, y = 7200;
    int x2 = 7200, y2 = 7200;
    char c = ',';

    int k;
    /*string line;
    while(!fin.eof()){
        getline(fin, line);

        k++;
    }
    cout << k << '\n';
    cout << line;*/

    while(c == ','){
        fin >> instr;
        fin >> k;
        fin >> c;
        cout << sum << " " << k << " " << instr << '\n';
        /*if(instr == 'L' && k == 212){
            cout << c << '\n';
            break;
        }*/
        if(instr == 'R'){
            for(int i = x + 1; i <= x + k; i++){
                sum = sum + 1;
                positions[y][i] = sum;
                a[y][i] = 1;
            }

            x += k;
        }
        else
            if(instr == 'L'){
                for(int i = x - 1; i >= x - k; i--){
                    sum = sum + 1;
                    positions[y][i] = sum;
                    a[y][i] = 1;
                }

                x -= k;
            }
            else
                if(instr == 'D'){
                    for(int i = y + 1; i <= y + k; i++){
                        sum = sum + 1;
                        positions[i][x] = sum;
                        a[i][x] = 1;
                    }

                    y += k;
                }
                else
                    if(instr == 'U'){
                        for(int i = y - 1; i >= y - k; i--){
                            sum = sum + 1;
                            positions[i][x] = sum;
                            a[i][x] = 1;
                        }
                        y -= k;
                    }

    }
    cout << "I got here\n";
    instr = c;
    c = ',';
    int meet = 0;
    while(c == ',' && !fin.eof()){
        fin >> k;
        fin >> c;
        cout << sum1 << " " << k << " " << instr << " " << x2 << " " << y2 << '\n';
        if(instr == 'R'){
            for(int i = x2 + 1; i <= x2 + k; i++){
                    a[y2][i] = 1;
                sum1++;
                positions1[y2][i] = sum1;
            }
            x2 += k;
        }
        else
            if(instr == 'L'){
                for(int i = x2 - 1; i >= x2 - k; i--){
                    sum1++;
                    positions1[y2][i] = sum1;
                    a[y2][i] = 1;
                }


                x2 -= k;
            }
            else
                if(instr == 'D'){
                    for(int i = y2 + 1; i <= y2 + k; i++){
                        a[i][x2] = 1;
                        sum1++;
                        positions1[i][x2] = sum1;
                    }


                    y2 += k;
                }
                else
                    if(instr == 'U'){
                        for(int i = y2 - 1; i >= y2 - k; i--){
                            a[i][x2] = 1;
                            sum1++;
                            positions1[i][x2] = sum1;
                        }


                        y2 -= k;
                    }
            fin >> instr;


    }
   /* for(int i = 0; i < meet; i++)
        cout << cross[i].y << " " << cross[i].x << '\n';
    int Min = 100000000;
    for(int i = 0; i < meet; i++)
        if(abs(cross[i].x - 8000) + abs(cross[i].y - 8000) < Min)
            Min = abs(cross[i].x - 8000) + abs(cross[i].y - 8000);
    cout << Min;*/
    ///for(int i = 0; i < index; i++)
    ///    cout << positions[i].y << " " << positions[i].x << " " << positions[i].sum << '\n';
   /* for(int i = 0; i < index1; i++)
        cout << positions1[i].y << " " << positions1[i].x << " " << positions1[i].sum << '\n';
    int Min = 1000000000;
    for(int i = 0; i < index; i++){
        for(int j = 0; j < index1; j++){
            if(positions[i].x == positions1[j].x && positions[i].y == positions1[j].y){

                if(positions[i].sum + positions[j].sum < Min)
                    Min = positions[i].sum + positions[j].sum;
            }
        }
    }

    cout << Min;*/
    int Min = 1000000000;
    for(int i = 0; i < 12001; i++){
        for(int j = 0; j < 12001; j++){
            if(positions1[i][j] && positions[i][j])
                if(positions1[i][j] + positions[i][j] < Min)
                    Min = positions1[i][j] + positions[i][j];
        }
    }
    cout << Min;
    return 0;
}
