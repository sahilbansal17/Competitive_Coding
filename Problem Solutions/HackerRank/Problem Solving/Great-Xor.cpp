#include <bits/stdc++.h>

using namespace std;

// Complete the theGreatXor function below.
long theGreatXor(long x) {
long result,num=0,a;
    int s,o=0,z=0;
    a=x;
    while(x!=0)
    {
        if(x&1==1)
            o++;
        else
            z++;
        x=x>>1;
    }
    s=o+z;
    while(s!=0)
    {
        num=num+pow(2,s-1);
        s--;
    }
    result=num^a;
    return result;
    return x;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = theGreatXor(x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
