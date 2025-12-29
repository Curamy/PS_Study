#include <iostream>
#include <deque>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    deque<int> card;
    cin >> n;
    for (int i=0; i<n; i++){
        card.push_back(i + 1);
    }

    while(card.size() > 1){
        card.pop_front();
        int tmp = card.front();
        card.push_back(tmp);
        card.pop_front();        
    }

    cout << card[0] << "\n";

    return 0;
}