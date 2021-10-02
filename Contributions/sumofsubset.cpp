#include <bits/stdc++.h>
using namespace std;
static int total_nodes;
void printsub(int A[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<" "<< A[i];
    }
    cout<<"\n";
}
int comparator(const void *pLhs, const void *pRhs)
{
    int *lhs = (int *)pLhs;
    int *rhs = (int *)pRhs;
    return *lhs > *rhs;
}
void subsum(int s[], int t[],
                int s_size, int t_size,
                int sum, int ite,
                int const target_sum)
{
    total_nodes++;
    if( target_sum == sum )
    {
       
        printsub(t, t_size);
       
        if( ite + 1 < s_size && sum - s[ite] + s[ite + 1] <= target_sum )
        {
           
            
            subsum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        }
        return;
    }
    else
    {
       
        
        if( ite < s_size && sum + s[ite] <= target_sum )
        {
          
            for( int i = ite; i < s_size; i++ )
            {
                t[t_size] = s[i];
                if( sum + s[i] <= target_sum )
                {
                   
                   
                    subsum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
                }
            }
        }
    }
}
 

void gensub(int s[], int size, int target_sum)
{
    int *tuplet_vector = (int *)malloc(size * sizeof(int));
    int total = 0;
 
   
    qsort(s, size, sizeof(int), &comparator);
    for( int i = 0; i < size; i++ )
    {
        total += s[i];
    }
    if( s[0] <= target_sum && total >= target_sum )
    {
        subsum(s, tuplet_vector, size, 0, 0, 0, target_sum);
    }
    free(tuplet_vector);
}
 
// Driver code
int main()
{
    int weights[100];
    int n=0;
    int target = 0;
    cout<<"Enter the total elements \n";
    cin>>n;
    cout<<"Enter the array elements \n";
    for(int i=0;i<n;i++)
    cin>>weights[i];
    cout<<"Enter the target sum \n";
    cin>>target;
    cout<<"The Subsets are \n";
    gensub(weights,n, target);
    cout << "Nodes generated " << total_nodes;
    return 0;
}
