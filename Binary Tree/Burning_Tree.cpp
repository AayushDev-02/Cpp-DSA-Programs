// create mapping and return target node (step 1 and step 2)
    Node* createParentMapping(Node* root, int target, map<Node*,Node*> &nodeToParent){
        
        Node* result = NULL;
        
        // level order traversal
        queue<Node*> q;
        q.push(root);
        
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                result = front;
            }
            
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        
        return result;
        
    }
    
    // burns the tree - (step 3)
    int burnTree(Node* root, map<Node*,Node*> &nodeToParent){
        
        map<Node*,bool> visited;
        queue<Node*>q;
        
        q.push(root);
        visited[root] = true;
        
        int ans = 0;
        
        while(!q.empty()){
            
            bool flag= false; // to keep status of addition in the queue
            int size = q.size();
            
            for(int i=0; i<size; i++){
                // process neighbouring node
                Node* front = q.front();
                q.pop();
                
                // left
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left] = true;
                    flag = true;
                }
                
                // right
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right] = true;
                    flag = true;
                }  
                
                // parent
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                    flag = true;
                }
            }
            
            if(flag == true){
                ans++;
            }
        }
        
        return ans;
    }
    
  
    int minTime(Node* root, int target) 
    {
        // ALGO: 
        // Step 1 : Create nodeToParent Mapping
        // Step 2: find Target Node
        // Step 3: burn the tree in min time
        
        int ans = 0;
        
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        ans = burnTree(targetNode, nodeToParent);
        
        return ans;
        
    }