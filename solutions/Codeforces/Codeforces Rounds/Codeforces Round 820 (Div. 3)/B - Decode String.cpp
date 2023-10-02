    #include "bits/stdc++.h"
    
    using namespace std;
    
    int main() {
        ios::sync_with_stdio(0);

        int q;
        cin >> q;
    
        while(q--) {
            int n;
            cin >> n;
            string code;
            cin >> code;
            stack<char> message;
    
            for(int i = code.size()-1; i >= 0; i--) {
                string currNum;
                if(code[i] == '0') {
                    currNum.push_back(code[i-2]);
                    currNum.push_back(code[i-1]);
                    i -= 2;
                }else {
                    currNum = code[i];
                }
    
                message.push('a' + stoi(currNum)-1);
            }
    
            while(!message.empty()) {
                cout << message.top();
                message.pop();
            }
            cout << '\n';
        }
    }