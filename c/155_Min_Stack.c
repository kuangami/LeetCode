// 155. Min Stack
/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *
 * Example:
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * Tags: Stack Design
 *
 * Similar Problems: (H) Sliding Window Maximum
 *
 * Author: Xinyue Zhang
 */

#define MAX_STACK_SIZE 1000

typedef struct {
    int top;
    int mintop;
    int data[MAX_STACK_SIZE];
    int min[MAX_STACK_SIZE];
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *s;
    s = (MinStack *) malloc (sizeof(MinStack));
    s->top = 0;
    s->mintop = 0;
    return s;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top == MAX_STACK_SIZE) return NULL;
    if(obj->mintop == 0 || x <= obj->min[obj->mintop - 1]) obj->min[obj->mintop++] = x;
    obj->data[obj->top++] = x;
}

void minStackPop(MinStack* obj) {
    if(obj->min[obj->mintop - 1] == obj->data[obj->top - 1]) obj->mintop--; 
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->mintop - 1];
}

void minStackFree(MinStack* obj) {
    free(obj);
    obj = NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
