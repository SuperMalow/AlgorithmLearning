#include <iostream>
using namespace std;
 
void Game_start()
{
    cout << "请在心中默想一个 1 到 10000 的整数：" << endl;
    cout << "想好了就输入1开始游戏吧，0退出。" << endl;
    char IsSymbol;
    int number;
    while(cin >> IsSymbol)
    { 
        int min_shu =  1;
        int max_shu = 10000;
        if(IsSymbol == '0')
            return ;
        else if(IsSymbol == '1')
        {
            int conunt = 1;
            while(true) 
            {
                number = (min_shu + max_shu) / 2;
                cout << endl << "是" << number << "吗? (这是我第" << conunt 
                    << "次猜测) 大了输入 >  小了输入 <  正确输入 = (输入无效字符不计次)";
                cin >> IsSymbol;
                if(IsSymbol == '>')
                { 
                    max_shu = number - 1;
                    conunt ++;
                }
                if(IsSymbol == '<')
                {
                    min_shu = number+1;
                    conunt ++;
                }
                if(IsSymbol == '=')
                {
                    cout << endl << "我猜到的数字是: " << number << endl
                        << "一共猜了: " << conunt << endl
                        << "输入1再玩一次，0退出" << endl;
                    break;
                }
            }
        }
        else
            cout<< "输入无效，请重新选择(1开始，0退出)：" << endl ;
    }
}

int main()
{
    Game_start();
    return 0;
}