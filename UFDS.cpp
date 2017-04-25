#Union Find Disjoint Set

#include <bits/stdc++.h>

using namespace std;

typedef vector<int>vi;

class UnionFind{
	private:
		vi p, rank, setSize;
		int numSets;
	public:
		UnionFind(int N){
			setSize.assign(N,1); numSets=N; rank.assign(N,0);
			p.assign(N,0); for(int i=0; i<N;i++) p[i]=i; }
			int findSet(int i) { return (p[i]==i) ? i: (p[i]=findSet(p[i]));}
			bool isSameSet(int i, int j) { return findSet(i)==findSet(j);}
			void unionSet(int i, int j){
				if (!isSameSet(i,j)){ numSets--;
					int x=findSet(i), y=findSet(j);
					//rank to keep the tree short
					if(rank[x]>rank[y]){p[y]=x; setSize[x] += setSize[y];}
					else {p[x]=y; setSize[y] += setSize[x];
						if (rank[x]==rank[y]) rank[y]++;} } }
			int numDisjointSets() {return numSets;}
			int sizeOfSet(int i) {return setSize[findSet(i)];}
		};


int main()
{
	//create 5 disjoint sets initially
	UnionFind UF(5);
	cout<<UF.numDisjointSets()<<endl;
	UF.unionSet(0,1);
	UF.unionSet(2,3);
	UF.unionSet(4,3);
	cout<<UF.numDisjointSets()<<endl;
	cout<<UF.isSameSet(4,3)<<endl;
	for (int i = 0; i < 5; i++) // findSet will return 1 for {0, 1} and 3 for {2, 3, 4}
    cout<< i <<" "<< UF.findSet(i)<<" "<<i<<" "<<UF.sizeOfSet(i)<<endl;
	return 0;
}
