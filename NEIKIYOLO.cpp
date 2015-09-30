#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,k,q,l,done,i,lallu;
    long kid;
    string temp,first,second;
    first="Help";
    cin>>t;
    while(t--)
    {
        cin>>k>>q;
        vector<long> a(k);
        l=lallu=0;
        while(q--)
        {
            cin>>temp;
            l=l%k; // Instead of using circular queue, simply overwrite the latest element with the newest one..no need to maintain order :-p
            done=0;
            cin>>kid;
            if(first==temp)
            {

                a[l]=kid;
                l++;
                lallu++;

            }
            else{
                     if(floor(log2(kid))==log2(kid)) //If power of 2,obviously he does not remember
                     {
                         cout<<"No\n";

                         continue;

                     }
            if(lallu<k) // If number of present elements is lesser or greater than total possible size of memory buffer
            {

                    for(i=0;i<lallu;i++)
                    {
                        if(a[i]==kid)
                        {
                            cout<<"Yes\n";
                            done=1;
                            break;
                        }
                    }
            }
            else{
                    for(i=0;i<k;i++)
                    {
                        if(a[i]==kid)
                        {
                            cout<<"Yes\n";
                            done=1;
                            break;
                        }
                    }

            }

                    if(!done)
                    {
                        cout<<"No\n";
                    }
                }



            }
        }
    return 0;

}
