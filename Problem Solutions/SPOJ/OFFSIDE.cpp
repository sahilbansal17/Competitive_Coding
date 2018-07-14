#include<algorithm>
#include <iostream>
using namespace std;

int main(void){
    int a,d;cin>>a>>d;
	while(a!=0 & d!=0)//taking input until they are both 0
	{
	    //int a,d;cin>>a>>d;
	    //if(a!=0 & d!=0)
	    {
	        int attack[a];for(int i=0;i<a;i++)cin>>attack[i];//attacking players
	        int defend[d];for(int i=0;i<d;i++)cin>>defend[i];//defending players
	        sort(attack,attack+a);
	        sort(defend,defend+d);
	        if(attack[0]<defend[1])//checking if any attacking player is closer than 2 defending players
	            cout<<"Y"<<endl;
	        else
	            cout<<"N"<<endl;
	    }
	    //else;
	    cin>>a>>d;
	}
	return 0;
}
