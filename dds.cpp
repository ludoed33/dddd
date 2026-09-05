#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> a;
    for (int i=0; i<n; ++i) {
        if (s[i] == '@') a.push_back(i);
    }

    if (a.empty() or a[0]==0 or a.back() == n-1) {
        cout << "No solution" << endl;
        return;
    }

    for (int i=0; i+1 < a.size(); ++i) {
        if (a[i+1]-a[i] < 3) {
            cout << "No solution" << endl;
            return;
        }
    }

    string ans = "";
    int k = 0;
    for (int i = 0; i < n; ++i) {
        ans += s[i];
        if (k+1 < a.size() and i == a[k]+1) {
            ans += ',';
            k++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}