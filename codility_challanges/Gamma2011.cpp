/**
In this problem we consider only strings consisting of lower-case English letters (a−z).
A string is a palindrome if it reads exactly the same from left to right as it does from right to left. For example, these strings are palindromes:
aza
abba
abacaba
These strings are not palindromes:
zaza
abcd
abacada
Given a string S of length N, a slice of S is a substring of S specified by a pair of integers (p, q), such that 0 ≤ p < q < N. A slice (p, q) of string S is palindromic if the string consisting of letters S[p], S[p+1], ..., S[q] is a palindrome. For example, in a string S = abbacada:
slice (0, 3) is palindromic because abba is a palindrome,
slice (6, 7) is not palindromic because da is not a palindrome,
slice (2, 5) is not palindromic because baca is not a palindrome,
slice (1, 2) is palindromic because bb is a palindrome.
Write a function
int solution(string &S);
that, given a string S of length N letters, returns the number of palindromic slices of S. The function should return −1 if this number is greater than 100,000,000.
For example, for string S = baababa the function should return 6, because exactly six of its slices are palindromic; namely: (0, 3), (1, 2), (2, 4), (2, 6), (3, 5), (4, 6).
Assume that:
N is an integer within the range [0..20,000];
string S consists only of lower-case letters (a−z).
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N) (not counting the storage required for input arguments).
*/
#include <iostream>


using namespace std;

int example();

int solution(string &S);
int countEvenPalindromes(string &S);
int countOddPalindromes(string &S);

int bruteforceSolution(string &S);
int cntBtEvenPalindromes(string &S);
int cntBtOddPalindromes(string &S);

// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
    int n = s.length();
    if (n == 0) return "^$";
    string ret = "^";
    for (int i = 0; i < n; i++)
        ret += "#" + s.substr(i, 1);

    ret += "#$";
    return ret;
}

string longestPalindrome(string s) {
    string T = preProcess(s);
    int n = T.length();
    int *P = new int[n];
    int C = 0, R = 0;
    for (int i = 1; i < n-1; i++) {
        int i_mirror = 2*C-i; // equals to i' = C - (i-C)

        P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
        int x = 0;
        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]){
            P[i]++;
            x++;

        }
        cout << T[i] << " i: " << i << " x : " << x << " P[i] " << P[i] << endl;

        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Find the maximum element in P.
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n-1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    //calculate palindromes
    int total = 0;
    for (int i = 1; i < n-1; i++) {
        if (P[i] > 0) {
            total += P[i]-1;
        }
    }
    delete[] P;

    for(int i=0; i<n; i++)
        cout << " " << P[i];

    cout << endl;

    return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

long cntPalindromes(string s) {
    string T = preProcess(s);
    int n = T.length();
    int *P = new int[n];
    int C = 0, R = 0;
    for (int i = 1; i < n-1; i++) {
        int i_mirror = 2*C-i; // equals to i' = C - (i-C)

        P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]){
            P[i]++;
        }
        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    //calculate palindromes
    long total = 0;
    for (int i = 1; i < n-1; i++) {
        if (P[i] > 0) {
            total += (P[i])/2;
        }
    }
    delete[] P;

    return total;
}

int main() {
    example();
    return 0;
}

int example(){
    string s = "baababa";
    string s2 = "abaababa";
    string s3 = "abababbbabbbaba";  //24
    string s4 = "caabbbaa"; //7

    cout << "Longest palindrome in abababbbabbbaba has: " << longestPalindrome(s3);

    cout << "Solution for example should return 6 : "   << solution(s)    << "\n";
    cout << "Solution for example should return 8 : "   << solution(s2)   << "\n";
    cout << "Solution for example should return 24 : "  << solution(s3)  << "\n";
    cout << "Solution for example should return 7 : "   << solution(s4)   << "\n";

    return 0;
}

int solution(string &S) {
    long result = cntPalindromes(S);

    if(result > 100000000)
        return -1;

    return result;
}
