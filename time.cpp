// 2023.07.16
//

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    // 基于当前系统的时间
    time_t now = time(0);

    char *dt = ctime(&now);
    cout << "本地日期和时间：" << dt << endl;

    cout << "1970年到目前经过的秒数" << +now << endl;
    tm *ltm = localtime(&now);

    cout << "年:" << 1900 + ltm->tm_year << endl;
    cout << "月:" << 1 + ltm->tm_mon << endl;
    cout << "日:" << ltm->tm_mday << endl;
    cout << "时间:" << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

    return 0;
}