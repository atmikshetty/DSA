#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
#include<bits/stdc++.h>



Node *sortLL(Node *head)
{
    Write your code here.
	// Brute Force O(N2 + NlogN)
	if(head == NULL || head->next == NULL) return head;
	Node* temp = head;
	vector<int> ans;
	while(temp!=NULL){
		ans.push_back(temp->data);
		temp = temp->next;
	}
	sort(ans.begin(),ans.end());
	temp = head;
	for(int i=0;i<ans.size();i++){
		temp->data = ans[i];
		temp = temp -> next;
	}
	return head;


}
