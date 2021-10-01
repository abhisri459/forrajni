#include<bits/stdc++.h>
using namespace std;

class TreeHeight
{
  int n;             
  vector<int> parent;

public:
  void read() {
    cin>>n;
    parent.resize(n);
    for (int i = 0; i < n; i++)
      cin>>parent[i];
  }
  
  int compute_height() {
	int maxHeight = 0;
	vector<int> heights;
	for (int i=0; i<parent.size(); i++) 
		heights.push_back(0);
	for (int vertex = 0; vertex < n; vertex++) {
		if (heights[vertex] != 0)
			continue;
		int height = 0;
		for (int i = vertex; i != -1; i = parent[i]) {
			if (heights[i] != 0) {
				height += heights[i];   
				break;
			}
			height++;
		}
		maxHeight = std::max(maxHeight, height);
		for (int i = vertex; i != -1; i = parent[i]) {
			if (heights[i] != 0)
				break;
			heights[i] = height--;
		}
	}
	return maxHeight;
  }

  int old_compute_height() {
    int maxHeight = 0;
    for (int vertex = 0; vertex < n; vertex++) {
      int height = 0;
      for (int i = vertex; i != -1; i = parent[i])
        height++;
      maxHeight = max(maxHeight, height);
    }
    return maxHeight;
  }
};

int main() {
  TreeHeight tree;
  tree.read();
  cout<<tree.compute_height();
}
