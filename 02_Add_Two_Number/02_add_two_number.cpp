#include <iostream>
using namespace std;

// 定義 ListNode 結構
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 相加兩個鏈結串列
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0); // 虛擬頭節點
    ListNode* current = dummyHead;
    int carry = 0;

    // 逐位相加
    while (l1 != nullptr || l2 != nullptr || carry > 0) {
        int sum = carry; // 先加上前一次的進位

        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10; // 計算新的進位
        current->next = new ListNode(sum % 10); // 取餘數作為當前節點的值
        current = current->next;
    }

    return dummyHead->next; // 返回結果的頭節點
}

// 輸出鏈結串列
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// 測試
int main() {
    // 創建測試數據 l1 = [2,4,3] (代表 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // 創建測試數據 l2 = [5,6,4] (代表 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // 相加兩個鏈結串列
    ListNode* result = addTwoNumbers(l1, l2);

    // 輸出結果
    printList(result); // 應該輸出：7 0 8（代表 807）

    return 0;
}
