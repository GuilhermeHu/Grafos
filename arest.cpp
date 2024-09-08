#include <bits/stdc++.h>
using namespace std;


bool bfs(vector<vector<int>> v){
    int n = v.size();

    vector<int> vis(n,0);
    queue<int> fila;
    fila.push(0); vis[0] = 1;
    while(!fila.empty()){
        int k = fila.front();
        fila.pop();
        for(int i : v[k]){
            if (vis[i]==0){
                fila.push(i);
                vis[i] = 1;
            }
        }
    }

    for(int i = 0; i<n; i++){
        if (vis[i]==0) return false;
    }
    return true;
}


int main (){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, ans = 0; cin >> n;

    int a = (n*(n-1))/2; //a = numero de arestas num grafo completo

    long long k = pow(2,a); //permutações possiveis de se fazer considerando arestas ativas e não ativas

    bitset<1000000> bt;

    //cria as permutações entre vertices
    vector<pair<int,int>> pares;
    for(int i = 0; i<n; i++){
        for (int j = i+1; j<n; j++){
            pares.push_back({i+1,j+1});
        }
    }
    // for(int i = 0; i<pares.size(); i++){
    //     cout << pares[i].first << " " << pares[i].second << endl;
    // }

    //codifica as permutações em um map de acordo com um valor inteiro
    map<int,pair<int,int>> dic;
    for(int i = 0; i<a; i++){
        dic.insert({i, pares[i]});
    }

    // soma +1 no vetor binario, e verificação se vetor está dentro dos requisitos
    for (int i = 0; i < k; i++){
        
        //soma +1 no bitset
        uint64_t addValue = 1;
        uint64_t currentValue = bt.to_ullong();
        currentValue += addValue;
        bt = bitset<1000000>(currentValue);


        if(bt.count() != n-1) continue; // grafo com n-1 vertices ativos = arvore ou grafo ciclo (não conexo)
        else{
            vector<vector<int>> vec(n);
            for (int j=0; j<a; j++){
                if (bt[j]){
                    int x = dic[j].first; int y = dic[j].second;
                    vec[x-1].push_back(y-1); 
                    vec[y-1].push_back(x-1);    
                }
            }

            // //PRINT DA MATRIZ DE ADJ. ->  para ver os casos
            // for (int _=0; _<n; _++){
            //     for (int __=0; __<vec[_].size(); __++){
            //         cout << vec[_][__] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;

            if (bfs(vec)) ans++;
        
        }
    }

    cout << ans << endl;
    return 0;
}

// g++ arest.cpp -o arest -O3
// ./arest.exe
