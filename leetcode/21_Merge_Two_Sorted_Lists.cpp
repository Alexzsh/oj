#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n,m;
string s,ss;
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;


    ListNode* head;
    ListNode* tail;


    if(l1->val <= l2->val) {
        head = l1, l1 = l1->next; 
    } else {
        head = l2, l2 = l2->next; 
    }


    tail = head;

    while(l1 && l2) {            
        if(l1->val <= l2->val) {
            tail->next = l1, l1 = l1->next; 
        } else {
            tail->next = l2, l2 = l2->next; 
        }


        tail = tail->next;
    }


    tail->next = l1 ? l1 : l2;


    return head;
}
int main() {

}
