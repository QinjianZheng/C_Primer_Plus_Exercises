#include "stack.h"

void InitializeStack(Stack * s) {
    InitializeList(s);
}
bool StackIsEmpty(Stack * s) {
    return ListIsEmpty(s);
}
bool StackIsFull(Stack * s) {
    return ListIsFull(s);
}
bool Push(Item item, Stack * s) {
    return AddItemHead(item, s);
}
bool Pop(Item * item, Stack * s) {
    return DeleteItemHead(item, s);
}