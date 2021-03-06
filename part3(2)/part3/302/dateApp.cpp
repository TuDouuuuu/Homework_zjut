//=====================================
// 日期处理
//=====================================
#include"datePro.h"
#include"myExcept.h"
#include<conio.h>    // for clrscr(), getch()
#include<fstream>
#include<iostream>
using namespace std;
//-------------------------------------
typedef void(*PF)(istream& cin, ostream& cout);
char* iFile[] = { "A32.txt", "B32.txt", "C32.txt", "D32.txt", "E32.txt" };
char* oFile[] = { "A32.out", "B32.out", "C32.out", "D32.out", "E32.out" };
PF func[] = { pr302A, pr302B, pr302C, pr302D, pr302E };
//-------------------------------------
int main(){
  for(int choice=1; choice; ){
    clrscr();
    if( choice>5 ) cout<<"You may entered a wrong key, try again.\n\n";
    cout<<"1-----统计天数\n";
    cout<<"2-----推断日期\n";
    cout<<"3-----确定天数\n";
    cout<<"4-----星期几\n";
    cout<<"5-----安排会议\n";
    cout<<"0-----exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    if(choice>=1 && choice<=5 )
    {
      ifstream cin(iFile[choice-1]);
      ofstream cout(oFile[choice-1]);
      try{
        func[choice-1]( cin, cout );
      }catch(MyExcept& e){
        cerr<<e.getWhat()<<"\n";
      }
      cerr<<"press any key...";   //保证该输出在屏幕上
      getch();
    }
  }
}//====================================

