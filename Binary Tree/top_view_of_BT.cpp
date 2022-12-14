vector<int> topView(Node *root)
    {
        
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        map<int,int> topNode;           //first int denotes -> hd and second denotes -> node data
        queue< pair<Node*, int> > q;    //the int in pair denotes -> hd
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            // if one value is present for a HD, then do not map 
            if(topNode.find(hd) == topNode.end() ){
                topNode[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, hd-1));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));
            }
            
        }
        
        for(auto i: topNode){
            ans.push_back(i.second);
        }
        
        return ans;
    }
