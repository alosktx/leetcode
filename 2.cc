/*
 * @Author: tangxiao
 * @Date: 2023-01-27 22:34:40
 * @LastEditTime: 2023-01-28 09:19:33
 * @LastEditors: tangxiao
 * @Copyright: 2022 FT. All right reserved.
 * @Description: Do not edit
 */
#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r = new ListNode();
        ListNode* re = r;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = l1 != nullptr ? l1->val : 0;
            int v2 = l2 != nullptr ? l2->val : 0;
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
            ListNode* t = new ListNode();
            t->val = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry) / 10;
            r->next = t;
            r = r->next;
        }
        re = re->next;
        return re;
    }
};

void PrintList(ListNode* l) {
    ListNode* t = l;
    while (t != nullptr) {
        std::cout << t->val << " ";
        t = t->next;
    }
    std::cout << "\n";
}

void InitList(ListNode* l, std::string s) {
    ListNode* t = l;
    for (int i = 0; i < s.length() - 1; i++) {
        t->val = s[i] - '0';
        t->next = new ListNode();
        t = t->next;
    }
    t->val = s[s.length() - 1] - '0';
}

int main(int argc, char const* argv[]) {
    // std::string s1 = "9999999";
    // std::string s2 = "9999";
    std::string s1 = "243";
    std::string s2 = "564";
    std::cout << s1.length() << " " << s1[0] << std::endl;
    ListNode* l1 = new ListNode();
    ListNode* l2 = new ListNode();
    PrintList(l1);
    PrintList(l2);
    InitList(l1, s1);
    InitList(l2, s2);
    PrintList(l1);
    PrintList(l2);

    Solution solu;
    ListNode* l3 = solu.addTwoNumbers(l1, l2);
    PrintList(l3);
    return 0;
}
