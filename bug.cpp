#include<iostream>
#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;


int solutionUtil(vector<vector<int> > &table,int A[],int n,int amt)
{
    if (amt==0)
    {
        cout<<"set 1"<<endl;
        table[n][amt]=1;
        return 1;
    }
    if (amt<0)
    {
        cout<<"set 0"<<endl;
        table[n][amt]=0;
        return 0;
    }
    if (n<=0 && amt>=1)
    {
        cout<<"set 0"<<endl;
        table[n][amt]=0;
        return 0;
    }
    else if (table[n][amt]!=-1)
    {
        cout<<"WHY IS IT COMING HERE???? TABLE INIT TO -1"<<endl;
        cout<<"value : "<<table[n][amt]<<endl;
        return table[n][amt];
    }
    else
    {
        int ans = solutionUtil(table,A,n-1,amt)+solutionUtil(table,A,n,amt-A[n-1]);
        cout<<"LLOLOLOL"<<ans<<endl;
        table[n][amt]=ans;
        return ans;
    }
}

void solution(int A[],int n,int amt)
{
    vector<vector<int> > table(n+1,vector<int>(amt));
    for (int i=0;i<n+1;i++)
    {
        for (int j=0;j<amt;j++)
        {
            table[i][j]=-1;
        }
    }
    cout<<"\nparams : n : "<<n<<" amt : "<<amt<<endl;
    int ans = solutionUtil(table,A,n,amt);
    
    //table printing : prints -1 for each
    
    for (int i=0;i<n+1;i++)
    {
        for (int j=0;j<amt;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<ans<<endl;
}

int main()
 {
	//code
	
	int T,x,n,k,amt;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int A[n];
	    for (int i=0;i<n;i++)
	    {
	        cin>>A[i];
	    }
	    cin>>amt;
	    solution(A,n,amt);
	    
	}
	return 0;
}
