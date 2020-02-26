#include<bits/stdc++.h>

using namespace std;

string split ( string a, char c) {
    string x;
    for(int i = 0;i <a.size();i++){
        if(a[i] == c)continue;
        x.push_back(a[i]);
    }
    return x;
}


struct DSU {
    vector <int> P, R;
    DSU (int n) {
        P.resize(n), R.resize(n);
        for (int i = 0; i < n; i++) {
            P[i] = i, R[i] = 1;
        }
    }

    int find(int x) {return x == P[x] ? x : P[x] = find(P[x]);}

    bool unionS (int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;

        if (R[y] > R[x]) swap(x, y);
        R[x] += R[y];
        P[y] = x;
        return true;
    }
};

bool condicional(bool,bool);
bool evaluar(bool,bool,char);

int main(){
	string input;
	cin >> input;
	semantica(input);
}

void semantica(string input){
	vector<char>ar;
    bitset<27> alf;
    for(char i: input){
        if(i >='a' && i<='z'){
            ar.emplace_back(i);
        }
    }
    for(char i : ar){
        cout << "Valor para "<< i << endl;
		bool x;
		cin >> x;
        alf[i-'a'] = x;
    }
    input = split(input,' ');
    string simbolos = "~^V>";
    DSU dsu(ar.size());
    for(int i = 0;i <input.size();i++){
        if(input[i] == '~'){
            alf[input[i+1]-'a'].flip();
        }
    }
    for(int i = 1;i < simbolos.size();i++){
        for(int j = 0;j < input.size(); j++){
            if(input[j] == simbolos[i]){
				bool pre = alf[dsu.find(input[j-1]-'a')];
                bool post = alf[dsu.find(input[j+1]-'a')];
				dsu.unionS(input[j-1]-'a',input[j+1]-'a');
				int now = dsu.find(input[j-1]-'a');
				alf[now] = evaluar(pre,post,simbolo[i]);
            }
        }
    }
	cout << alf[dsu.find(ar[0]-'a')] << endl;
}

bool evaluar(bool pre, bool post, char simbolo) {
	bool resp;
	switch(simbolo){
		case '^':
			resp = pre && post;
			break;
		case 'V':
			resp = pre || post;
			break;
		case '>':
			resp = condicional(pre, post);	
			break;
	}
	return resp;
}

bool condicional(bool a, bool b){
    if(a == true && b == false) return false;
    return true;
}
