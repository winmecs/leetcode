#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int  overflow_flag = 0, add_1 , add_2, add_result;
    struct  ListNode *result_head = NULL, *result_tail = NULL;


    while (l1 != NULL || l2 != NULL){
        struct ListNode *newnode = new ListNode(0);
        if(l1) {
            add_1 = l1->val;
            l1 = l1->next;
        } else{
            add_1 = 0;
        }

        if(l2) {
            add_2 = l2->val;
            l2 = l2->next;
        } else{
            add_2 = 0;
        }

        add_result = add_1 + add_2 + overflow_flag;

        if ((add_result >= 10)) {
            newnode->val = add_result - 10;
            overflow_flag = add_result / 10;
        } else{
            newnode->val = add_result;
            overflow_flag = 0;
        }

        if(!result_head) {
            result_head = newnode;
            result_tail = newnode;
            continue;
        }

        result_tail->next = newnode;
        result_tail = newnode;
    }

    if(overflow_flag){
        struct ListNode *newnode = new ListNode( overflow_flag);
        result_tail->next = newnode;
    }

    return  result_head;
}

int main(int argc, char const *argv[])
{
    struct ListNode *l1, *l2;
    l1 = new ListNode(1);
//    l1->next = new ListNode(9);
//    l1->next->next= new ListNode(3);

    l2 = new ListNode(9);
    l2->next = new ListNode(9); 
    l2->next->next = new ListNode(9);

    struct ListNode *result =  addTwoNumbers(l1, l2);

    while (result ){
        cout<< result->val << "->";
        result = result->next;
    }


    return 0;
}