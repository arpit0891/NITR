
/*
By Arpit
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll xx;
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	//#ifndef ONLINE_JUDGE
	    //freopen("input.txt", "r", stdin);
	    //freopen("output.txt", "w", stdout);
	//#endif
}
ll findMinVertex(ll* distance, bool* visited, ll n){

	ll minVertex = -1;
	for(ll i = 0; i < n; i++){
		if(!visited[i] && (minVertex == -1 ||  distance[i] < distance[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}


void dijkstra(ll** edges, ll n){
	ll m=-1;
	ll num=-1;
	ll s=-1;
	ll x[n+1][n+2];
	ll i=-1,j=0;
		for (ll k=0;k<n;k++){
	ll* distance = new ll[n];
	bool* visited = new bool[n];
	for(ll i = 0; i < n; i++){
		distance[i] = INT_MAX;
		visited[i] = false;
	}


	distance[k] = 0;


	for(ll i = 0; i < n - 1; i++){
		ll minVertex = findMinVertex(distance, visited, n);
		visited[minVertex] = true;
		for(ll j = 0; j < n; j++){	
			if(edges[minVertex][j] != 0 && !visited[j]){
				ll dist = distance[minVertex] + edges[minVertex][j];
				if(dist < distance[j]){
					distance[j] = dist;
				}
			}
		}
	}

	for(ll i = 0; i < n; i++){
		
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


for(ll i=0;i<n;i++){
	for (ll j=0;j<n;j++){
        if (x[i][j]<1e6){
		cout<<x[i][j]<<" ";
		if (x[i][j]<1000) cout<<" ";
		if (x[i][j]<100) cout<<" ";
		if (x[i][j]<10) cout<<" ";
        }
        else{
            cout<<"OFF  ";
        }
		}
		cout<<endl;
	}


}
void adjacency_matrix(){
	ll n;
	ll e;
   
    cout<<"Enter the node you want to eleminate: \n";
    cin>>xx;
	cin >> n >> e;
	ll** edges = new ll*[n];
	for (ll i = 0; i < n; i++) {
		edges[i] = new ll[n];
		for (ll j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (ll i = 0; i < e; i++) {
		ll f, s, weight;

		cin >> f >> s >> weight;
        if (f==xx || s==xx) weight=1e9;
		edges[f-1][s-1] = weight;
		edges[s-1][f-1] = weight;
	}
	// cout << endl;
	dijkstra(edges, n);

	for (ll i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}
int main() {
	//file_i_o();
	adjacency_matrix();
}



