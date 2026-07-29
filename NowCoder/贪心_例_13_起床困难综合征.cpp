#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct opt{
    string op;
    int t;
    //vector<int> bit_t;  
    // not need to store the bit representation
    // can compute it on the fly when needed
};
int bitwise_operation(const string& op, int a, int b) {
    if (op == "AND") return a & b;
    if (op == "OR") return a | b;
    if (op == "XOR") return a ^ b;
    return 0; // default case, should not happen
}
int get_best_bit(vector<opt> &a,int n,int pos)
{
    int result1=1;
    int result0=0;
    
    for(int i=0;i<n;i++){
        string op = a[i].op;
        int t = a[i].t;

        if (op == "AND") {
            result1 &= (t >> pos) & 1;
            result0 &= (t >> pos) & 1;
        } else if (op == "OR") {
            result1 |= (t >> pos) & 1;
            result0 |= (t >> pos) & 1;
        } else if (op == "XOR") {
            result1 ^= (t >> pos) & 1;
            result0 ^= (t >> pos) & 1;
        }
    }
    if(result1>result0) return 1;
    else return 0; 
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<opt> a;
    // store the operations and their corresponding values
    for(int i=0;i<n;i++){
        string op;
        int t;
        cin>>op>>t;
        opt o;
        o.op = op;
        o.t = t; 
        a.push_back(o);
    }
    // 基本思路，遍历每个m_i, 遍历每个 a_i, 求解最终结果并比较
    // but overtime absolutely
    
    int x=0;
    for(int i=30;i>=0;i--){// better from 30->0
        int best_bit = get_best_bit(a,n,i);
        if((x+(best_bit<<i))>m) continue;
        // judeg if x + best_bit<<pos is  over m, 
        // we could not set this bit to 1

        x |= (best_bit << i);
    }
    for(int i=0;i<n;i++){
        string op = a[i].op;
        int t = a[i].t;
        switch(op[0]){
            case 'A':
                x &= t;
                break;
            case 'O':
                x |= t;
                break;
            case 'X':
                x ^= t;
                break;
        }
    }
    cout<<x<<endl;
    return 0;
}