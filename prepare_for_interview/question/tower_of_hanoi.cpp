// ハノイの塔を実装しろ
// move 1 from A to C

#include <bits/stdc++.h>
using namespace std;

void hanoi(int disk, char current, char dest, char center)
{
    if (disk < 1)
        return;
    hanoi(disk - 1, current, center, dest);
    cout << "move" << disk << "from" << current << "to" << dest << endl;
    hanoi(disk - 1, center, dest, current);
}

int main()
{
    hanoi(3, 'A', 'C', 'B');

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// void hanoi(int disk, char current, char dest, char center)
// {
//     if (disk < 1)
//         return;

//     hanoi(disk - 1, current, center, dest);
//     cout << "move" << disk << "from" << current << "to" << dest << endl;
//     hanoi(disk - 1, center, dest, current);
// }
// int main()
// {

//     hanoi(3, 'A', 'C', 'B');
// }
// #include <bits/stdc++.h>
// using namespace std;

// void hanoi(int disk, int current, int dest, int center)
// {

//     if (disk < 1)
//         return;

//     hanoi(disk - 1, current, center, dest);
//     cout << "move" << disk << "from" << (char)current << "to" << (char)dest << endl;
//     hanoi(disk - 1, center, dest, current);
// }

// int main()
// {

//     hanoi(3, 'A', 'C', 'B');

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void hanoi(int disc, char current, char dest, char center)
// {
//     if (disc < 1)
//         return;
//     hanoi(disc - 1, current, center, dest);
//     cout << "move" << disc << "from" << current << "to" << dest << endl;
//     hanoi(disc - 1, center, dest, current);
// }

// int main()
// {
//     hanoi(3, 'A', 'C', 'B');

//     return 0;
// }