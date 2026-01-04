class Solution {
public:
    bool extraSpace(ListNode* head){
        unordered_map<ListNode*, bool> visited;
        ListNode* temp = head;

        while (temp) {
            if (visited[temp]) {
                return true;  
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }

    bool optimiseSol(ListNode* head){
        if(!head) return false;

        ListNode* toto = head;
        ListNode* rabi = head;

        while(rabi && rabi->next){
            toto = toto->next;
            rabi = rabi->next->next;

            if(toto == rabi) return true;
        }
        return false;
    }

    bool hasCycle(ListNode *head) {
        // return extraSpace(head);
        return optimiseSol(head);
    }
};