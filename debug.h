#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

template <typename T> void printType(T x);
template <typename T> void printType(vector <T> &x);
template <typename T> void printType(stack <T> &x);
template <typename T> void printType(queue <T> &x);
template <typename T1, typename T2> void printType(pair <T1, T2> &x);

template <typename T> void printVar(T x, bool none = false);
template <typename T> void printVar(vector <T> &x, bool index = false);
template <typename T> void printVar(stack <T> &s, bool index = false);
template <typename T> void printVar(queue <T> &s, bool index = false);
template <typename T1, typename T2> void printVar(pair <T1, T2> &x, bool none = false);

template <typename T>
string getType(T x){
    if(is_same <int, decltype(x)>::value) return "int";
    if(is_same <long long int, decltype(x)>::value) return "long long int";
    if(is_same <float, decltype(x)>::value) return "float";
    if(is_same <double, decltype(x)>::value) return "double";
    if(is_same <string, decltype(x)>::value) return "string";
    if(is_same <bool, decltype(x)>::value) return "bool";
}

template <typename T>
void printType(T x){
    cout << getType(x);
}

template <typename T>
void printType(vector <T> &x){
    cout << "vector <";
    T temp;
    printType(temp);
    cout << ">";
}

template <typename T>
void printType(stack <T> &x){
    cout << "stack <";
    T temp;
    printType(temp);
    cout << ">";
}

template <typename T>
void printType(queue <T> &  x){
    cout << "queue <";
    T temp;
    printType(temp);
    cout << ">";
}

template <typename T1, typename T2>
void printType(pair <T1, T2> &x){
    cout << "pair <";
    T1 temp1;
    printType(temp1);
    cout << ", ";
    T2 temp2;
    printType(temp2);
    cout << ">";
}

template <typename T>
void printVar(T x, bool none){
    cout << x;
}

template <typename T>
void printVar(vector <T> &x, bool index){
    if(index){
        for(int i = 0; i < (int)x.size(); i++){
            cout << "(" << i << "): ";
            printVar(x[i]);
            cout << "\n";
        }
    }else{
        cout << "[";

        for(int i = 0; i < (int)x.size(); i++){
            printVar(x[i]);
            if(i != (int)x.size() - 1) cout << ", ";
        }
        cout << "]";
    }
}

template <typename T>
void printVar(stack <T> &s, bool index){
    vector <T> v;
    while(!s.empty()) v.push_back(s.top()), s.pop();
    reverse(v.begin(), v.end());
    printVar(v, index);
    cout << "(top)";
}

template <typename T>
void printVar(queue <T> &s, bool index){
    cout << "(front)\n";
    vector <T> v;
    while(!s.empty()) v.push_back(s.front()), s.pop();
    printVar(v, index);
    cout << "(back)";
}

template <typename T1, typename T2>
void printVar(pair <T1, T2> &x, bool none){
    cout << "(";
    printVar(x.first, none);
    cout << ", ";
    printVar(x.second, none);
    cout << ")";
}

template <typename T>
void debug(T x){
    for(int i = 0; i < 30; i++) cout << "-";
    cout << "\n";

    printType(x);
    cout << "\n";

    printVar(x, true);
    cout << "\n";

    for(int i = 0; i < 30; i++) cout << "-";
    cout << "\n";
}

#endif // DEBUG_H_INCLUDED
