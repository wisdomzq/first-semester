#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符

    // 读取元素
    string line;
    getline(cin, line);
    vector<string> elements;
    stringstream ss(line);
    string item;
    while(getline(ss, item, ',')){
        elements.push_back(item);
    }

    // 读取运算表
    vector<vector<string>> op(n, vector<string>());
    for(int i=0;i<n;i++) {
        getline(cin, line);
        stringstream ss_op(line);
        while(getline(ss_op, item, ',')){
            op[i].push_back(item);
        }
    }

    // 判断交换律
    bool commutative = true;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(op[i][j] != op[j][i]){
                commutative = false;
                break;
            }
        }
        if(!commutative) break;
    }
    cout << "commutative law:" << (commutative ? "y" : "n") << endl;

    // 判断结合律
    bool associative = true;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<n;k++) {
                string a = op[i][j];
                int a_idx = -1;
                for(int x=0; x<n; x++) if(elements[x] == a){ a_idx = x; break;}
                if(a_idx == -1){
                    associative = false;
                    break;
                }
                int b_idx = -1;
                for(int y=0; y<n; y++) if(elements[y] == op[j][k]){ b_idx = y; break;}
                if(b_idx == -1 || op[a_idx][k] != op[i][b_idx]){
                    associative = false;
                    break;
                }
            }
            if(!associative) break;
        }
        if(!associative) break;
    }
    cout << "associative law:" << (associative ? "y" : "n") << endl;

    // 判断幂等律
    bool idempotent = true;
    for(int i=0;i<n;i++) {
        if(op[i][i] != elements[i]){
            idempotent = false;
            break;
        }
    }
    cout << "idempotent law:" << (idempotent ? "y" : "n") << endl;

    // 判断幺元
    string identity = "n";
    for(int i=0;i<n;i++) {
        bool is_identity = true;
        for(int j=0;j<n;j++) {
            if(op[i][j] != elements[j] || op[j][i] != elements[j]){
                is_identity = false;
                break;
            }
        }
        if(is_identity){
            identity = elements[i];
            break;
        }
    }
    cout << "identity element:" << identity << endl;

    // 判断零元
    string zero = "n";
    for(int i=0;i<n;i++) {
        bool is_zero = true;
        for(int j=0;j<n;j++) {
            if(op[i][j] != elements[i] || op[j][i] != elements[i]){
                is_zero = false;
                break;
            }
        }
        if(is_zero){
            zero = elements[i];
            break;
        }
    }
    cout << "zero element:" << zero << endl;

    return 0;
}
