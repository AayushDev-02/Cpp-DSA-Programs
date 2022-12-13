vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	if(root == NULL){
    	    return ans;
    	}
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	bool leftToRight = true;
    	
    	while(!q.empty()){
    	    int size = q.size();
    	    
    	    vector<int> temp(size);
    	    
    	   // Level Process
    	   for(int i=0; i<size; i++){
    	       Node* front = q.front();
    	       q.pop();
    	       
    	       //normal insert or reverse insert
    	       int index = leftToRight ? i : size-i-1;
    	       
    	       temp[index] = front->data;
    	       
    	       if(front->left){
    	           q.push(front->left); 
    	       }
    	       if(front->right){
    	           q.push(front->right); 
    	       }
    	       
    	   }
    	   
    	   //direction change karni h
    	   leftToRight = !leftToRight;
    	   
    	   for(auto i: temp){
    	       ans.push_back(i);
    	   }
    	    
    	}
    	
    	return ans;
    }