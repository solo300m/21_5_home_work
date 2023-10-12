#include <iostream>
#include <vector>
using namespace std;

vector<int> setVect()
{
    vector<int> vec;
    vector<int> &ptr = vec;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }
    return vec;
}
int main()
{
    vector<int> s;
    s = setVect();
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}