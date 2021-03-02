
/*
By Arpit
*/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    char a[20],b[20];
    char sum[20],c_[20];
    int i;
    
	cout<<"Enter first binary string\n";
    cin>>a;
    cout<<"Enter second binary string\n";
    cin>>b;
    
	if(strlen(a)==strlen(b))
    {
        char c='0';
        int length=strlen(a);
        
		for(i=length-1;i>=0;i--)
        {
            if(a[i]=='0' && b[i]=='0' && c=='0')
            {
                sum[i]='0';
                c='0';
            }
            else if(a[i]=='0' && b[i]=='0' && c=='1')
            {
                sum[i]='1';
                c='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && c=='0')
            {
                sum[i]='1';
                c='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && c=='1')
            {
                sum[i]='0';
                c='1';
 
            }
            else if(a[i]=='1' && b[i]=='0' && c=='0')
            {
                sum[i]='1';
                c='0';
 
            }
            else if(a[i]=='1' && b[i]=='0' && c=='1')
            {
                sum[i]='0';
                c='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && c=='0')
            {
                sum[i]='0';
                c='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && c=='1')
            {
                sum[i]='1';
                c='1';
 
            }
            else
                break;
        }
        cout<<"\nSum="<<c<<sum;
 
        for(i=0;i<length;i++)
        {
            if(sum[i]=='0')
                c_[i]='1';
            else
                c_[i]='0';
        }
        
		if(c=='1')
            c='0';
        else{
            c='1';}
     
	    cout<<"\nChecksum="<<c<<c_;
    }
    else{
        cout<<"\nWrong input strings";}
        
    return 0;
}
