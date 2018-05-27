/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        map<RandomListNode*, RandomListNode*> mapping;
        RandomListNode* it = head;

        while (it != NULL) {
            RandomListNode* newNode = new RandomListNode(it->label);
            mapping.insert(pair<RandomListNode*, RandomListNode*>(it, newNode));
            it = it->next;
        }

        it = head;

        while (it != NULL) {
            RandomListNode* it_copy = mapping.at(it);

            if (it->next != NULL) {
                it_copy->next = mapping.at(it->next);
            }

            if (it->random != NULL) {
                it_copy->random = mapping.at(it->random);
            }

            it = it->next;
        }


        return mapping.at(head);
    }
};
