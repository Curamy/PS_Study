using namespace std;

long long solution(int price, int money, int count)
{
    long long sum = 0;
    long long tmp = price + (price * count);
    
    if (count % 2 == 0){
        sum += (tmp * (count / 2));
    }
    else {
        sum += ((tmp * (count / 2)) + (tmp / 2));
    }

    if (sum <= money){
        return 0;
    }
    else {
        return sum - money;
    }
}