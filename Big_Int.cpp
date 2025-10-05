#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class BigInt{
    private:
        string num;   // Stores number as string
        int sign;   // +1 for positive, -1 for negative


        // Remove leading zeros like "00123" → "123"
        void removeLeadingZeroes(){
            int i=0;

            while(i<num.size()-1 && num[i]=='0'){
                i++;
            }

            num=num.substr(i);
            if(num =="0") sign=1;    // Ensure -0 becomes +0
        }


        // Compare absolute values of two BigInts
        static int compareAbs(const BigInt&a, const BigInt&b){
            if(a.num.size()!=b.num.size()){
                return a.num.size() > b.num.size() ? 1 : -1;
            }

            else if(a.num == b.num) return 0;

            return a.num > b.num ? 1 : -1;
        }


        // Add two positive number strings
        static string addStrings(const string&a, const string&b){
            int carry=0;
            string result;
            int i=a.size()-1, j=b.size()-1;

            while(i>=0 || j>=0 || carry){
                int sum=carry;
                if(i>=0) sum+=(a[i]-'0');
                if(j>=0) sum+=(b[j]-'0');
                result+=(sum%10 +'0');
                carry=sum/10;
                i--;
                j--;
            }

            reverse(result.begin(),result.end());
            return result;
        }


        // Subtract two positive strings (assumes |a| >= |b|)
        static string subStrings(const string&a, const string&b){
            int borrow=0;
            string result;
            int i=a.size()-1, j=b.size()-1;
            while(i>=0){
                int diff=(a[i]-'0')-borrow;
                if(j>=0) diff=diff-(b[j]-'0');
                if(diff<0){
                    diff+=10;
                    borrow=1;
                }
                else borrow=0;
                result+=(diff+'0');
                i--;
                if(j>=0)j--;
            }

            while(result.size()>1 && result.back()=='0') result.pop_back();
            reverse(result.begin(),result.end());
            return result;
        }


    public:

        // Constructors
        BigInt(){
            num="0";
            sign=1;
        }

        BigInt(string s){
            if(s[0]=='-'){
                num=s.substr(1);
                sign=-1;
            }
            else if(s[0]=='+'){
                num=s.substr(1);
                sign=1;
            }
            else{
                num=s;
                sign=1;
            }
            removeLeadingZeroes();
        }


        // Input/Output
        void read(){
            cout<<"Enter the number: ";
            string s;
            cin>>s;
            *this = BigInt(s);
        }


        void print(){
            if(sign==-1) cout<<"-";
            cout<<num<<endl;
        }


        // Arithmetic operators
        BigInt operator+(const BigInt& other) const{
            BigInt res;
            if(sign == other.sign){
                res.num = addStrings(num,other.num);
                res.sign = sign;
            }
            else{
                int cmp = compareAbs(*this,other);
                if(cmp == 0) res = BigInt("0");
                else if(cmp>0){
                    res.num = subStrings(num,other.num);
                    res.sign = sign;
                }
                else{
                    res.num = subStrings(other.num,num);
                    res.sign = other.sign;
                }
            }
            res.removeLeadingZeroes();
            return res;
        }


        // Subtraction: a - b = a + (-b)
        BigInt operator-(const BigInt&other) const{
            BigInt temp=other;
            temp.sign*=-1;
            return *this+temp;
        }


        // Multiplication
        BigInt operator*(const BigInt&other) const{
            if(num == "0" || other.num == "0") {
                return BigInt("0");
            }
            BigInt res;
            int len1=num.size();
            int len2=other.num.size();
            vector<int>result(len1+len2,0);
            for(int i=len1-1;i>=0;i--){
                for(int j=len2-1;j>=0;j--){
                    int product = (num[i]-'0')*(other.num[j]-'0');
                    int sum=product+result[i+j+1];
                    result[i+j+1]=sum%10;
                    result[i+j]=sum/10;
                }
            }
            string s;
            int i=0;
            while(i<result.size() && result[i]==0)i++;
            while(i<result.size()){
                s+=(result[i]+'0');
                i++;
            }
            res.num = s;
            res.sign = sign*other.sign;
            return res;
        }
};


int main(){
    BigInt a,b,res;
    int choice;

    while(1){
        cout<<"1.Addition"<<endl;
        cout<<"2.Subtraction"<<endl;
        cout<<"3.Multiplication"<<endl;
        cout<<"4.Exit"<<endl;
        cin>>choice;

        if(choice==4) break;

        a.read();
        b.read();

        switch(choice){
            case 1:
                res=a+b;
                cout<<"Addition result: ";
                res.print();
                break;
            case 2:
                res=a-b;
                cout<<"Subtraction result: ";
                res.print();
                break;
            case 3:
                res=a*b;
                cout<<"Multiplication result: ";
                res.print();
                break;
            default:
                cout<<"Your choice is invalid";
        }
    }
    return 0;
}