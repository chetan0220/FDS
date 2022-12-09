#include <bits/stdc++.h>
using namespace std;
int main()
{
    string word ;
    cout<<"Enter string to be reversed : ";
    cin >> word;
    // Two pointer approach 
    int start = 0 , end = word.size() - 1;
    while(start <= end)
    {
        swap(word[start], word[end]);
        start++;
        end--;
    }
    cout<<"Reversed string : " << word;
    return 0;
}
/*
    Time Complexity = O(n)  where n is the size of string
*/
