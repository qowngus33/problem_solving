#include <iostream>
#include <string>

using namespace std;

int main(void) {
   ios::sync_with_stdio(0);
   cin.tie(0);

   string p; // 주어진 문제
   string sub = ""; // 처음 숫자
   cin >> p;

   int i = 1;

   while (true) {
      if (i == p.size()) {
         cout << p << " " << p; // 자기 자신 출력
         return 0; // 종료
      }

      sub = p.substr(0, i); // 초기값
      int s = stoi(sub); // 숫자로 변환
      
      if (p.find(to_string(s+1)) == i) { // 나열일 때
         while (true) {
            s++;
            if (p.find(to_string(s + 1)) > 2900) {
               cout << sub << " " << to_string(s); // 걍 숫자 위치를 출력하지 말고 그 숫자를 출력(point)
               return 0;
            }
         }
      }
      else{
         i++; // 자릿수 증가
      }
   }
}
