
/*
By Arpit
*/

#include<bits/stdc++.h>
#include<string.h>
#include<stdio.h>
using namespace std;
vector<vector<int>> x(16,vector<int>(16,0));
		int n;
	int e;
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
int findMinVertex(int* distance, bool* visited, int n){

	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == -1 ||  distance[i] < distance[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}


void dijkstra(int** edges, int n){
	int m=0;
	int num=0;
	int s=0;
    
	//int x[n+2][n+2];
	int i=0,j=0;
		for (int k=0;k<n;k++){
	int* distance = new int[n];
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		distance[i] = INT_MAX;
		visited[i] = false;
	}


	distance[k] = 0;

	for(int i = 0; i < n - 1; i++){
		int minVertex = findMinVertex(distance, visited, n);
		visited[minVertex] = true;
		for(int j = 0; j < n; j++){	
			if(edges[minVertex][j] != 0 && !visited[j]){
				int dist = distance[minVertex] + edges[minVertex][j];
				if(dist < distance[j]){
					distance[j] = dist;
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		
		x[i][j]=distance[i];
		
		if (i!=j){
			// assuming we are not calculating latency for itself
			//=>either a swith or a controller
			s=s+distance[i];
			num++;
		}
		//cout << i+1 << " " << distance[i] << endl;
	}
	j++;
	delete [] visited;
	delete [] distance;
	//cout<<"\n\n";

	


}

for(int i=0;i<n;i++){
	for (int j=0;j<n;j++){
		m=max(m,x[i][j]);
		// cout<<x[i][j]<<" ";
		// if (x[i][j]<1000) cout<<" ";
		// if (x[i][j]<100) cout<<" ";
		// if (x[i][j]<10) cout<<" ";

		}
		cout<<endl;
	}
float av,worst;
av=((float)s/(float)(num*4));
worst=(float)(m)/(float)(2);
cout<<"";
// cout<<"Average latency = "<<av<<"x 10^(-5) ms"<<"\n";
// cout<<"Worst latency = "<<worst<<"x 10^(-5) ms"<<"\n";
cout<<"\n";
}
void adjacency_matrix(){

	cin >> n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f-1][s-1] = weight;
		edges[s-1][f-1] = weight;
	}
	cout << endl;
	dijkstra(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}
vector <int> m;
void combo(int N, int K)
{	vector<int> mx;
int mi=1e8;
    string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

	int z=K;
	int nn=n;
	int matchange=0;
    // print integers and permute bitmask
    do { 
		int ma=0;
		for (int j=0;j<n;j++){
			int mini=1e8;
			int c =K-1;

        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {	
            if (bitmask[i]){ 
				mini=min(mini,x[i][j]);
				
				if (c) c--;
				else {
					ma=max(ma,mini);
					//cout<<mini<<" ";
				}
				}
        }

		
		}
		matchange++;
       // cout << endl;
		 if (matchange%nn==n-z+1){
			 mi=min(mi,ma);
			//cout<<"\n";
			z=z+1;
			matchange=0;
			if (z>n) {
				nn=nn-1;
				z=K;
			}
		 }
		 
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
	//cout<<(float)mi/2<<"\n";
}
 
int main(int argc, char const *argv[]) {
	file_i_o();
	adjacency_matrix();
    for (int i=1;i<14;i++){
       combo(14,i);
    }
}



