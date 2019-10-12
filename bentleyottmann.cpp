#include<bits/stdc++>
#define x second
#define y first
typedef pair<int,int >point;
struct event 
{
    point p1,p2;
    int type;
    event() {};
    event(point p1,point p2, int type) : p1(p1), p2(p2),type(type) {};
};
int n,e;
event events[MAX];
bool compare(event a, event b) 
{ 
    return a.p1.x<b.p1.x; 
}
set<point >s;
void hv_intersection()
{
    for (int i=0;i<e;++i)
        {
                event c = events[i];
                if (c.type==0) s.insert(c.p1);//insert starting point of line segment into set
                else if (c.type==1) s.erase(c.p2);//remove starting point of line segment from set, equivalent to removing line segment
                else
                {
                        for (typeof(s.begin()) it=s.lower_bound(make_pair(c.p1.y,-1));it!=s.end() && it->y<=c.p2.y; it++)
                                printf("%d, %d\n", events[i].p1.x, it->y);//intersections
                }
        }
}
int main () 
{
    scanf("%d", &n);
    int p1x,p1y,p2x,p2y;
        for (int i=0;i<n;++i) 
        {
                scanf("%d %d %d %d", &p1x, &p1y,&p2x, &p2y);
        if(p1x==p2x)               
        {
            events[e++]=event(make_pair(p1y,p1x),make_pair(p2y,p2x),2);
        }
        else                
        {
         
            events[e++]=event(make_pair(p1y,p1x),make_pair(p2y,p2x),0);
            events[e++]=event(make_pair(p2y,p2x),make_pair(p1y,p1x),1);
        }
        }
    sort(events, events+e,compare);//on x coordinate
    hv_intersection();
    return 0;
}
