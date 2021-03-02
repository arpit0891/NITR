

/*
By Arpit
*/
// use dijkastras to make adjacency matrix then used belman ford to find the shift 
#include<bits/stdc++.h>
using namespace std;
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
struct node
{
    unsigned dist[30];
    unsigned from[30];
}route[15];
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
	int m=-1;
	int num=-1;
	int s=-1;
	int x[n+1][n+2];
	int i=-1,j=0;
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
		cout<<x[i][j]<<" ";
		if (x[i][j]<1000) cout<<" ";
		if (x[i][j]<100) cout<<" ";
		if (x[i][j]<10) cout<<" ";

		}
		cout<<endl;
	}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            route[i].dist[j] = x[i][j];
            route[i].from[j] = j;
        }
    }

    int flag;
    do {
        flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if ((route[i].dist[j]) > (route[i].dist[k] + route[k].dist[j])) {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);

    for (int i = 0; i < n; i++) {
        cout << "\nFor Router : " << i + 1 << endl;
        cout << "Destination\t via \t\tDistance" << endl;
        for (int j = 0; j < n; j++){
            printf("%d\t\t %d\t\t%d \n", j+1, route[i].from[j]+1, route[i].dist[j]);}
    }

}
void adjacency_matrix(){
		int n;
	int e;
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
	// cout << endl;
	dijkstra(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}

int main(){
	//file_i_o();
	adjacency_matrix();
	}
