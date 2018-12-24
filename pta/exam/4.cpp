#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>


using namespace std;
bool isMatch(string text, string pattern) {
        vector<vector<bool>> evalMat(text.length()+1);
        for (auto &v:evalMat) {
            v.reserve(pattern.length()+1);
            v.resize(pattern.length()+1);
            fill(v.begin(), v.end(), false);
        }

        for (int i = 0; i < evalMat.size(); ++i) {
            if (i == 0) {
                evalMat[i][0] = true;
            } else {
                evalMat[i][0] = false;
            }
        }
        for (int j = 1; j < evalMat[0].size(); ++j) {
            if (pattern[j-1] == '*') {
                if (evalMat[0][j-2]) {
                    evalMat[0][j] = evalMat[0][j-2];
                } else {
                    evalMat[0][j] = false;
                }
            } else {
                evalMat[0][j] = false;
            }
        }
        
        for (int i = 1; i <  evalMat.size(); ++i) {
            for (int j = 1; j < evalMat[i].size(); ++j) {
                if ((text[i-1] == pattern[j-1]) || (pattern[j-1] == '.')) {
                    evalMat[i][j] = evalMat[i-1][j-1];
                } else if (pattern[j-1] == '*') {
                    if (evalMat[i][j-2]) {
                        evalMat[i][j] = evalMat[i][j-2];
                    } else {
                        if ((text[i-1] == pattern[j-2]) || (pattern[j-2] == '.')) {
                            evalMat[i][j] = evalMat[i-1][j];
                        } else {
                            evalMat[i][j] = false;
                        }
                    }
                } else {
                    evalMat[i][j] = false;
                }
            }
        }
        return evalMat[text.length()][pattern.length()];
    }
int n,m;
string s,ss;

int main(){
    cin>>s>>ss;
    cout<<(isMatch(s,ss)?"ok":"sorry");
}
