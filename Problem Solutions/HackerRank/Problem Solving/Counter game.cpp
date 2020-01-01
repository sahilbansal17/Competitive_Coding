#include <bits/stdc++.h>

using namespace std;
int check_count(long n)
{
    int one=0,zera=0;
    long a;
    a=n;
    while(n!=0)
    {
        if(n&1==1)
        {
            one++;
        }
        n=n>>1;
    }
    n=a;
    while(a!=0)
    {
        if(a&1==1)
        {
            break;
        }
        else
        {
            zera++;
        }
        a=a>>1;
    }
    //cout<<zera<<" "<<one<<" "<<z;
    if(one==1)
        return zera;
    else
        return zera+one-1;

}
string counterGame(long n) {
    int c;
    c=check_count(n);
    if(c%2!=0)
    {
        return "Louise";
    }
    else if(c%2==0)
    {
        return "Richard";
    }

return "loise";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
