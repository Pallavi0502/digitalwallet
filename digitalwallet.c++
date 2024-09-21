#include <bits/stdc++.h>
using namespace std;
struct User {
    int userID;
    int balance;
};
size_t findUserIndex(const vector<User>& users, int userID) {
    for (size_t i = 0; i < users.size(); ++i) { 
        if (users[i].userID == userID) {
            return i;
        }
    }
    return -1; 
}
bool compareUsers(const User& a, const User& b) {
    if (a.balance == b.balance) {
        return a.userID < b.userID; 
    }
    return a.balance < b.balance;
}

int main() {
    int N;
    cin >> N;

    vector<User> users(N);
    for (int i = 0; i < N; ++i) {
        cin >> users[i].userID >> users[i].balance;
    }

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int from_userID, to_userID, amount;
        cin >> from_userID >> to_userID >> amount;
        size_t fromIndex = findUserIndex(users, from_userID);
        size_t toIndex = findUserIndex(users, to_userID);
        if (fromIndex != -1 && toIndex != -1 && users[fromIndex].balance >= amount) {
            users[fromIndex].balance -= amount;
            users[toIndex].balance += amount;
            cout << "Success" << endl;
        } else {
            cout << "Failure" << endl;
        }
    }
    cout<<"\n";
    sort(users.begin(), users.end(), compareUsers);
    for (const auto& user : users) {
        cout << user.userID << " " << user.balance << endl;
    }

    return 0;
}