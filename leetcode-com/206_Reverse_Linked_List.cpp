#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
    
    
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;

    while(cur){
        ListNode* next = cur->next;
        cur->next=prev;
        prev=cur,cur=next;
    }
    return prev;
}
int n,m;
string s,ss;

int main() {

}

