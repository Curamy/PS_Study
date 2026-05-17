#include <string>
#include <vector>
#include <climits> // LLONG_MAX, LLONG_MIN 사용을 위해 추가

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    // 1. 초기값을 2e9 대신 long long의 최대/최소값으로 변경
    long long lmost = LLONG_MAX;
    long long rmost = LLONG_MIN;
    long long bmost = LLONG_MAX;
    long long tmost = LLONG_MIN;
    
    // 2. set 대신 vector 사용 (중복 제거 불필요, 삽입 속도 훨씬 빠름)
    vector<pair<long long, long long>> intersections;
    vector<string> answer;
    
    for (int i = 0; i < line.size(); i++){
        for (int j = i + 1; j < line.size(); j++){
            int a = line[i][0];
            int b = line[i][1];
            int e = line[i][2];
            int c = line[j][0];
            int d = line[j][1];
            int f = line[j][2];
            
            long long bm = (long long)a * d - (long long)b * c;
            
            if (bm == 0){
                continue;
            }
            
            long long bj1 = (long long)b * f - (long long)e * d;
            long long bj2 = (long long)e * c - (long long)a * f;
            
            if (bj1 % bm != 0 || bj2 % bm != 0){
                continue;
            }
            
            long long x = bj1 / bm;
            long long y = bj2 / bm;
            
            if (x < lmost) lmost = x;
            if (x > rmost) rmost = x;
            if (y < bmost) bmost = y;
            if (y > tmost) tmost = y;
            
            // 단순 push_back으로 성능 향상
            intersections.push_back({x, y});
        }
    }

    for (long long i = 0; i <= tmost - bmost; i++){
        answer.push_back(string(rmost - lmost + 1, '.'));
    }
    
    for (auto pt : intersections){
        long long px = pt.first - lmost;
        long long py = tmost - pt.second;
        answer[(int)py][(int)px] = '*'; // 중복 좌표여도 단순히 *을 덮어쓰므로 문제 없음
    }
    
    return answer;
}