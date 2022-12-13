#include<iostream>
#include<vector>
using namespace std;

typedef vector< vector<int> > Matrix;
struct suma {
	int numerosf[10];
	int numerosc[10];
};

bool menor(int n, const Matrix& M1, int i, int j, vector<suma>& v2) {
	int contf = 0, contc = 0, k = n;
	bool cert = false;
	while (k >= 0) {
		contf += v2[i].numerosf[k];
		contc += v2[j].numerosc[k];
		--k;
	}
	if (contf > contc) {
		cert = true;
	}
	return cert;
}

int main () {
	int fila;
	cin >> fila;
	if (fila != 0) {
		Matrix M1(fila, vector<int>(fila,0));
		fila = M1.size();
			vector<suma> v2(fila);
			for  (int i = 0; i < fila; ++i) {
				for (int j = 0; j < fila; ++j) {
					cin >> M1[i][j];
					++v2[i].numerosf[M1[i][j]];
					++v2[j].numerosc[M1[i][j]];
					}
				}
			for (int i = 0; i < fila; ++i) {
				for (int j = 0; j < fila; ++j) {
					if (j == fila-1) {
						cout << menor(M1[i][j], M1, i, j, v2);
					} else cout << menor(M1[i][j],M1, i, j, v2) << " ";
				}
				cout << endl;
			}
	}	
}
