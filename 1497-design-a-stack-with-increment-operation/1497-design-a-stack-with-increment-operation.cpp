class CustomStack {
    int size;
int *a;
int top=-1;
public:

    CustomStack(int maxSize) {
        size=maxSize;
        a=new int[size];
    }
    
    void push(int x) {
        if(top==size-1)return;
        else
    a[++top]=x;
    }
    
    int pop() {
        if(top==-1)return -1;
        else
        return a[top--];
    }
    
    void increment(int k, int val) {
        if(top<k){
            for(int i=0;i<=top;i++)
                a[i]+=val;
        }
        else
        {
            for(int i=0;i<k;i++)
                a[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
