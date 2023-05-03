class Solution{
    public:
    // You need to complete this function
long long steps=0;
void TOH(int n, int a, int b, int c){
    if(n==1)
    {
        steps++;
        cout<<"move disk "<<n<<" from rod "<<a<<" to rod "<<b<<endl;
        return;
    }
    else{
        TOH(n-1,a,c,b);
        steps++;
        cout<<"move disk "<<n<<" from rod "<<a<<" to rod "<<b<<endl;
        TOH(n-1,c,b,a);
    }
}
    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        TOH(N,from,to,aux);
        return steps;
    }

};
