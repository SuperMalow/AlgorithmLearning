#include <iostream>
using namespace std;
 
void Game_start()
{
    cout << "��������Ĭ��һ�� 1 �� 10000 ��������" << endl;
    cout << "����˾�����1��ʼ��Ϸ�ɣ�0�˳���" << endl;
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
                cout << endl << "��" << number << "��? (�����ҵ�" << conunt 
                    << "�β²�) �������� >  С������ <  ��ȷ���� = (������Ч�ַ����ƴ�)";
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
                    cout << endl << "�Ҳµ���������: " << number << endl
                        << "һ������: " << conunt << endl
                        << "����1����һ�Σ�0�˳�" << endl;
                    break;
                }
            }
        }
        else
            cout<< "������Ч��������ѡ��(1��ʼ��0�˳�)��" << endl ;
    }
}

int main()
{
    Game_start();
    return 0;
}