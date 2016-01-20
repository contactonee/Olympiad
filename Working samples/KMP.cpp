#include <iostream>
#include <string>
#include <vector>
using namespace std;
int p[2222];
int main()
{
	string s;
	cin >> s;
	int n = (int)s.size();
    for(int i=1;i<n;i++)
    {
        int j=p[i-1];
        while (j>0&&s[i]!=s[j])
            j=p[j-1];
        if(s[i]==s[j]) ++j;
        p[i]=j;
    }
	for(int i=0;i<n;i++)
		cout<<p[i]<<" ";
	return 0;
}
