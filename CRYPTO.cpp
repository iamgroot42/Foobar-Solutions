#include<iostream>

using namespace std;

//Algorithm is right,but running only one time
int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i,j,k,l,temp,itr,freq[26];
    char b[26],surd[26];
    cin>>t;
    while(t--)
    {
        cin>>n;

        char a[n];
        for(i=0;i<26;i++) {freq[i]=0;}
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            freq[a[i]-'a']++;
        }
        itr=0;
        for(i=0;i<26;i++)
        {
            if(freq[i]!=0) {itr++;} // To get number of distinct alphabets in word
        }
        for(i=0;i<26;i++)cin>>b[i];


        //Storing frequencies wise all da alphabets in da hood -_-
        for(i=0;i<itr;i++)
        {
            temp=0;
            for(j=0;j<26;j++)
            {
                if(freq[j]>freq[temp])
                {
                    temp=j;
                }


            }
            surd[i]=temp+'a';
            freq[temp]=0;
	           // cout<<surd[i]; // Problem fixed
        }

        char answer[n];

for(i=0;i<itr;i++)
{
	for(k=0;k<n;k++)
	{
		if(a[k]==surd[i])
		{
			answer[k]=b[i];
		}
	}
}

       for(i=0;i<n;i++)cout<<answer[i];
        cout<<"\n";

    }
    return 0;
}
