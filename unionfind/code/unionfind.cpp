#include <bits/stdc++.h>
using namespace std;
class UnionFind {
    private:
        
        // The number of elements in this union find
        int size;

        // Used to track the size of each of the component    
        vector<int> sz;
        
        // id[i] points to the parent of i, if id[i] = i then i is a root node
        vector<int> id;
        
        // Tracks the number of components in the union find
        int numOfComponents;
    public:
        UnionFind(int size) {
            if (size <= 0) throw invalid_argument("Size <= 0 is not allowed");
            this->size = numOfComponents = size;
            sz.resize(size);
            id.resize(size);
            for (int i = 0; i < size; i++) {
                id[i] = i; // Link to itself (self root)
                sz[i] = 1; // Each component is originally of size one
            }
        }

        // Find which component/set 'p' belongs to, takes amortized constant time.
        int find(int p) {
            int root = p;

            // Find the root
            while(root != id[root]) root = id[root];

            // Compress the path leading back to the root.
            while(p != root) {
                int next = id[p];
                id[p] = root;
                p = next;
            }
            
            return root;
        }

        // recursive find
        int findRec(int p) {
            if (p == id[p]) return p;
            return id[p] = findRec(id[p]);
        }

        // Return whether or not the elements 'p' and 'q' are in the same components/set
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // return the size of the components/set 'p' belongs to
        int componentSize(int p) {
            return sz[find(p)];
        }

        // Returns the current number of elements in the union find
        int size() {
            return size;
        }

        // Returns the number of remaining components/sets
        int components() {
            return numOfComponents;
        }

        // Unify the components/sets containing elements 'p' and 'q'
        void unify(int p, int q) {
            // These elements are already in the same group!
            if (isConnected(p, q)) return;

            int root1 = find(p);
            int root2 = find(q);

            // Merge smaller component/set into the larger one.
            if (sz[root1] < sz[root2]) {
                sz[root2] += sz[root1];
                id[root1] = root2;
                sz[root1] = 0;
            } else {
                sz[root1] += sz[root2];
                id[root2] = root1;
                sz[root2] = 0;
            }

            // Since the roots found are different we know that the
            // number of components/sets has decreased by one
            numOfComponents--;
        }
};