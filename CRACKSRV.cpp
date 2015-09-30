#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,m,i,p,q,te,count;
    //a is the string containing fibbionacci numbers together , k is the string to be searched for
    cin>>t;
    while(t--)
    {
        string a="01",k="";
        p=0;
        q=1;
        cin>>m;
        cin>>k;
        count=0;
        if(m==0) {a="0";}
        for(i=2;i<=m;i++)
        {

          ostringstream temp;
          te=p+q;
          p=q;
          q=te;
          temp<<q;
          a.append(temp.str());
          //  ostringstream temp; //Redeclaring it every time,or else it keeps adding up -_-
           // temp<<p;
            //a.append(temp.str());
            //te=p;
            //p=q;
            //q+=te;
        }

       //cout<<a<<" balle \n";
        for(size_t o=a.find(k) ; o!=string::npos ; o=a.find(k,k.length()+o)) { count++; } //Check how many times it occurs
        cout<<count<<"\n";
    }
    return 0;
}
