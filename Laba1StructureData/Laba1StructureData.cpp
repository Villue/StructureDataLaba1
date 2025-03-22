#include <iostream>
#include <chrono>
int gcd(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
int main()
{
    int x, y;
    int a, n;
    std::cout << "a:"; std::cin >> a;
    std::cout << "n:"; std::cin >> n;

    auto start = std::chrono::high_resolution_clock::now();
    int g = gcd(a, n, x, y);
    if (g != 1)
        std::cout << "0";
    else {
        x = (x % n + n) % n;
        std::cout << x;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds> (end - start);
    std::cout << std::endl << "time: " << duration.count() << " milliseconds" << std::endl;
    std::cout << "Lebedeva Olga Romanovna. Group: 090304-RPIb-o24";

}
