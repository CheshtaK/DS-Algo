#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

struct Stack{
    int size;
    int top;
    Node* *array;
};

Stack *createStack(int size){
    Stack *stack = new Stack;
    stack->size = size;
    stack->top = -1;
    stack->array = new Node*;
    return stack;
}

int isFull(Stack *stack){
    return stack->top - 1 == stack->size;
}

int isEmpty(Stack *stack){
    return stack->top == -1;
}

void push(Stack *stack, Node *node){
    if(isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

Node *pop(Stack *stack){
    if(isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

bool pairPresent(Node *root, int target){
    Stack *s1 = createStack(100);
    Stack *s2 = createStack(100);

    bool done1 = false, done2 = false;
    int val1 = 0, val2 = 0;
    Node *curr1 = root, *curr2 = root;

    while(1){
        while(done1 == false){
            if(curr1 != NULL){
                push(s1, curr1);
                curr1 = curr1 -> left;
            }
            else{
                if(isEmpty(s1))
                    done1 = 1;
                else{
                    curr1 = pop(s1);
                    val1 = curr1 -> val;
                    curr1 = curr1 -> right;
                    done1 = 1;
                }
            }
        }

        while(done2 == false){
            if(curr2 != NULL){
                push(s2, curr2);
                curr2 = curr2 -> right;
            }
            else{
                if(isEmpty(s2))
                    done2 = 1;
                else{
                    curr2 = pop(s2);
                    val2 = curr2 -> val;
                    curr2 = curr2 -> left;
                    done2 = 1;
                }
            }
        }

        if((val1 != val2) && (val1 + val2) == target){
            cout<<val1<<","<<val2<<endl;
            return true;
        }
        else if((val1 + val2) < target)
            done1 = false;
        else if((val1 + val2) > target)
            done2 = false;

        if(val1 >= val2)
            return false;
    }
}

Node *newNode(int val){
    Node *temp = new Node;
    temp->val = val;
    temp->right = temp->left = NULL;
    return temp;
}



int main()
{
    Node *root = newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);

    int target = 33;
    if(pairPresent(root, target) == false)
        cout<<"No such value";

    return 0;
}
