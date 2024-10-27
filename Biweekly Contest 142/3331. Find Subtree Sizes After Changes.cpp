class Solution {
private:
    vector<int> parentNodes; 
    string characters; 
    vector<int> updatedParent; 
    vector<vector<int>> children; 
    vector<int> subtreeSizes; 

    void determineNewParent(int node) {
        int currentParent = parentNodes[node];
        while (currentParent != -1 && characters[currentParent] != characters[node]) {
            currentParent = parentNodes[currentParent];
        }
        updatedParent[node] = (currentParent != -1) ? currentParent : parentNodes[node];
    }

    int calculateSubtreeSize(int node) {
        int size = 1; 
        for (int childNode : children[node]) {
            size += calculateSubtreeSize(childNode); 
        }
        subtreeSizes[node] = size; 
        return size; 
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        parentNodes = parent; 
        characters = s; 
        int nodeCount = parent.size(); 
        updatedParent.resize(nodeCount, -1); 
        subtreeSizes.resize(nodeCount, 0); 
        children.resize(nodeCount); 

        for (int i = 0; i < nodeCount; i++) {
            determineNewParent(i); 
        }

        for (int node = 0; node < nodeCount; node++) {
            int newParent = updatedParent[node]; 
            if (newParent != -1) {
                children[newParent].push_back(node); 
            }
        }

        calculateSubtreeSize(0); 
        return subtreeSizes; 
    }
};
