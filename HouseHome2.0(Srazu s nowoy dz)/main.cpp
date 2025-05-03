#include "prog.h"

int main() {
    int n;
    std::cout << "How many apartments? ";
    std::cin >> n;

    House h(n);
    h.show();

    return 0;
}
