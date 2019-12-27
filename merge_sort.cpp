#include <iostream>
using namespace std;
int n, a[100], t[100], i;
void merge(int* l, int* r)
{
    if(r-l<=1) return;
    int* m = l + (r-l)/2;
    merge(l, m);
    merge(m, r);
    int i, j, ls=m-l, rs=r-m;
    for(i=0; i!=ls;++i)
        *(t+i) = *(l+i);
    for(i=0; i!=ls && j!=rs; l++)
    {
        if(*(t+i)<=*(m+j))
        {
            *l = *(t+i);
            i++;
        }
        else
        {
            *l = *(m+j);
            j++;
        }
    }
    for(; i!=ls; i++, l++)
        *l = *(t+i);
}
int main()
{
    scanf("%d",&n);
    for(i=0;i!=n;++i)
        scanf("%d",&a[i]);
    merge(a, a+n);
    for(i=0;i!=n;++i)
        printf("%d ",a[i]);
}
