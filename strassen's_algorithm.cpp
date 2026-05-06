#include <iostream>
using namespace std;
void add(int A[][8], int B[][8], int C[][8], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}
void sub(int A[][8], int B[][8], int C[][8], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}
void strassen(int A[][8], int B[][8], int C[][8], int n) {
    if (n == 2) { // base case 
        int A11=A[0][0], A12=A[0][1], A21=A[1][0], A22=A[1][1];
        int B11=B[0][0], B12=B[0][1], B21=B[1][0], B22=B[1][1];
        int P=(A11+A22)*(B11+B22);
        int Q=(A21+A22)*B11;
        int R=A11*(B12-B22);
        int S=A22*(B21-B11);
        int T=(A11+A12)*B22;
        int U=(A21-A11)*(B11+B12);
        int V=(A12-A22)*(B21+B22);
        C[0][0]=P+S-T+V;
        C[0][1]=R+T;
        C[1][0]=Q+S;
        C[1][1]=P+R-Q+U;
        return;
    }
    int k = n / 2;
    int A11[8][8], A12[8][8], A21[8][8], A22[8][8];
    int B11[8][8], B12[8][8], B21[8][8], B22[8][8];
    int M1[8][8], M2[8][8], M3[8][8], M4[8][8];
    int M5[8][8], M6[8][8], M7[8][8];
    int T1[8][8], T2[8][8];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+k];
            A21[i][j]=A[i+k][j];
            A22[i][j]=A[i+k][j+k];
            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+k];
            B21[i][j]=B[i+k][j];
            B22[i][j]=B[i+k][j+k];
        }
    add(A11,A22,T1,k); add(B11,B22,T2,k); strassen(T1,T2,M1,k);
    add(A21,A22,T1,k); strassen(T1,B11,M2,k);
    sub(B12,B22,T2,k); strassen(A11,T2,M3,k);
    sub(B21,B11,T2,k); strassen(A22,T2,M4,k);
    add(A11,A12,T1,k); strassen(T1,B22,M5,k);
    sub(A21,A11,T1,k); add(B11,B12,T2,k); strassen(T1,T2,M6,k);
    sub(A12,A22,T1,k); add(B21,B22,T2,k); strassen(T1,T2,M7,k);
    int C11[8][8], C12[8][8], C21[8][8], C22[8][8];
    add(M1,M4,T1,k); sub(T1,M5,T2,k); add(T2,M7,C11,k);
    add(M3,M5,C12,k);
    add(M2,M4,C21,k);
    add(M1,M3,T1,k); sub(T1,M2,T2,k); add(T2,M6,C22,k);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j]=C11[i][j];
            C[i][j+k]=C12[i][j];
            C[i+k][j]=C21[i][j];
            C[i+k][j+k]=C22[i][j];
        }
}
int main() {
    int n = 4; // must be power of 2 and <= 8
    int A[8][8] = {{1,2,3,4},{5,6,7,8},{9,1,2,3},{4,5,6,7}};
    int B[8][8] = {{1,0,2,1},{3,1,0,2},{4,2,1,3},{1,0,0,1}};
    int C[8][8];
    strassen(A,B,C,n);
    cout << "Result:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }
}
