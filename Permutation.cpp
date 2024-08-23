#include <bits/stdc++.h>
using namespace std;
#include <windows.h>

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    vector<int> vec = {2,4,8,10,12};

    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    double executionTimes[6];

    for (int i = 0; i < 6; ++i) {

        vector<int> vetor(vec[i]);
        for (int j = 0; j < vec[i]; ++j) {
            vetor[j] = j+1;
        }

        LARGE_INTEGER start, end;
        double executionTime;

        QueryPerformanceCounter(&start);

        do{
            for (int a : vetor) cout << a << " ";
            cout<< "\n";
        }while(next_permutation(vetor.begin(),vetor.end()));

        QueryPerformanceCounter(&end);

        cout << "\n";

        // Calcula o tempo de execução em segundos
        executionTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

        executionTimes[i] = executionTime;

        printf("Tempo de execucao do ciclo %d: %f segundos\n", i + 1, executionTime);
    }
    cout << "\n";
    for (int i = 0; i < 6; ++i) {
        cout << (i+1)*2  << " -  " <<  executionTimes[i] << "\n";
    }

    return 0;
}
// g++ a.cpp
//  ./a.exe
