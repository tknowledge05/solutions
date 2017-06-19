#include <iostream>
#include <vector>
using namespace std;
char input[30][31];
bool toggle[30][31];
bool grid[30][30];
int firstpos[30];
int N;
int counter;
int delta[5][2] = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};
void print() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) printf("%d",grid[i][j]);
        printf("\n");
    }
    printf("\n");
}
void push(int x, int y, bool print) {
    counter++;
    if (print) printf("%d %d\n",x+1,y+1);
    for (int i=0; i<5; i++) {
        int tx = x+delta[i][0];
        int ty = y+delta[i][1];
        if (tx>=0 && ty>=0 && tx<N && ty<N) grid[tx][ty]=!grid[tx][ty];
    }
}
void solve(bool print) {
    for (int i=1; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (grid[i-1][j]) {
                push(i,j,print);
            }
        }
    }
}
void print2() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<=N; j++) printf("%d",toggle[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main() {
    int T; scanf("%d",&T); while (T--) {
        scanf("%d",&N);
        for (int i=0; i<N; i++) scanf("%s",input[i]);
        
        for (int i=0; i<N; i++) {
            memset(grid,false,30*30*sizeof(bool));
            push(0,i,false);
            solve(false);
            for (int j=0; j<N; j++) {toggle[i][j]=grid[N-1][j];}
        }
        
        for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) grid[i][j]=input[i][j]=='1';
        solve(false);
        
        for (int i=0; i<N; i++) toggle[i][N]=grid[N-1][i];
        
        // solve this matrix
      
        for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) grid[i][j]=input[i][j]=='1';        
        
        for (int i=0; i<N; i++) {
            // do we have an entry in rows [i,N) which has i,i == 1
            int j=i;
            while (j<N && toggle[j][i]==0) j++;
            if (j==N) continue;
            // swap this with row i
            for (int k=0; k<=N; k++) {
                bool temp = toggle[i][k];
                toggle[i][k] = toggle[j][k];
                toggle[j][k] = temp;
            }
            // eliminate other rows
            for (int k=j+1; k<N; k++) {
                if (toggle[k][i]) {
                    for (int l=i; l<=N; l++) {
                        toggle[k][l]^=toggle[i][l];
                    }
                }
            }
            // cancel out higher rows
            for (int k=0; k<i; k++) {
                if (toggle[k][i]) {
                    for (int l=i; l<=N; l++) toggle[k][l]^=toggle[i][l];
                }
            }
        }
        counter=0;
        for (int i=0; i<N; i++) {
            if (toggle[i][i] && toggle[i][N]) push(0,i,false);
        }
        solve(false);
 
        for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) grid[i][j]=input[i][j]=='1'; 
        
        printf("%d\n",counter);
        
        for (int i=0; i<N; i++) {
            if (toggle[i][i] && toggle[i][N]) push(0,i,true);
        }
        solve(true);
        // now just need a combination of toggle which adds to that
        for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) assert(grid[i][j]==0);
        //print();
    }
}
 