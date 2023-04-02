void insert(stack<int>& s,int x){
    // Base Case
    if(s.size()==0 || s.top()<=x){
        s.push(x);
        return;
    }
    // The element will not be in top position, so popping the top element and checking further where it can be placed
    int val=s.top();
    s.pop();
    insert(s,x);

    // Inserting the previously popped element, kind of Bakctracking i guess
    s.push(val);
}

void sortStack(stack<int> &s)
{
    // Already sorted
    if(s.size()==1){
        return;
    }

    int x=s.top();
    s.pop(); // Popping the top element and sorting the remaining part
    sortStack(s);

    // Inserting that element in its correct position in the sorted stack
    insert(s,x);
    
}