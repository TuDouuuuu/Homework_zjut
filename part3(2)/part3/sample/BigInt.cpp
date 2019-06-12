//=====================================
// BigInt.cpp  -- string version
//=====================================
#include"BigInt.h"
#include<cstdlib>
using namespace std;
//-------------------------------------
static void adding(string& a, const string& b);   // a += b
static void complement(string& s);
static bool absLessThan(const string& a, const string& b);
static void substract(string& a, const string& b);  // suppose a>b
//-------------------------------------
string add(const string& a, const string& b){
  if(a[0]=='0') return b;
  if(b[0]=='0') return a;
  string aa( a[0]=='-' ? a.substr(1) : a );
  aa = string(BYTENUM - aa.length(), '0') + aa;
  if(a[0]=='-') complement( aa );

  string bb( b[0]=='-' ? b.substr(1) : b );
  bb = string(BYTENUM - bb.length(), '0') + bb;
  if(b[0]=='-') complement( bb );

  adding(aa, bb);

  string sign;
  if(aa[0]=='9'){
    complement(aa);
    sign = "-";
  }
  int pos = aa.find_first_not_of('0');
  if(pos==string::npos)
    return "0";
  else
    return sign+aa.substr(pos);
  //return pos==string::npos ? const string("0") : (sign + aa.substr(pos)); !!!
}//------------------------------------
string sub(const string& a, const string& b){
  return add( a, (b[0]=='-' ? b.substr(1) : '-'+b ));
}//------------------------------------
string mul(const string& a, const string& b){
  if(a[0]=='0' || b[0]=='0') return "0";
  string aa(a[0]=='-' ? a.substr(1) : a);
  aa = string(BYTENUM - aa.length(), '0') + aa;
  string bb(b[0]=='-' ? b.substr(1) : b);
  string s(BYTENUM, '0');
  for(int j=bb.length()-1; j>=0; --j)
    for(int temp=0, i=aa.length()-1, k=s.length()-bb.length()+j; bb[j]!='0' && i>=0; --i,--k){
      temp += (aa[i]-'0')*(bb[j]-'0') + s[k]-'0';
      s[k] = char(temp%10+'0');
      temp/=10;
    }
  int pos = s.find_first_not_of('0');
  if(pos!=string::npos) s = s.substr(pos);
  return ((a[0]=='-')+(b[0]=='-')==1 ? '-'+s : s);
}//------------------------------------
string div(const string& a, const string& b){
  string sign=((a[0]=='-')+(b[0]=='-')==1 ? "-":"");
  string aa(a[0]=='-' ? a.substr(1) : a);
  string bb(b[0]=='-' ? b.substr(1) : b);
  if(absLessThan(aa, bb)) return "0";
  string s;
  string y(aa.substr(0, bb.length()-1));
  for(int i=bb.length()-1; i<aa.length(); ++i){
    y += aa[i];
    int count=0;
    for( ; !absLessThan( y, bb ); count++)
      substract( y, bb );
    s += char(count+'0');
  }
  int pos = s.find_first_not_of('0');
  if(pos!=string::npos) s = s.substr(pos);
  return sign+s;
}//------------------------------------
void adding(string& a, const string& b){
  for(int i=a.length()-1,tmp=0; i>=0; --i,tmp /= 10 ){
    tmp += a[i]-'0' + b[i]-'0';
    a[i] = char(tmp%10+'0');
  }
}//------------------------------------
void complement(string& s){
  int pos = s.find_last_not_of('0');  // pos不可能找不到
  s[pos]--;
  for(int i=0; i<=pos; ++i)
    s[i] = '9' - s[i]+'0';
}//------------------------------------
bool absLessThan(const string& a, const string& b){
  return a.length()<b.length() || a.length()==b.length() && a<b;
}//------------------------------------
void substract(string& a, const string& b){
  if(a==b){ a=""; return; }
  for(int i=1, bi=b.length()-i,ai=a.length()-i; i<=b.length(); ++i,ai--,bi--)
    if((a[ai]-=(b[bi]-'0'))<'0')
      a[ai]+=10, a[ai-1]--;
  int pos = a.find_first_not_of('0');
  if(pos!=string::npos) a = a.substr(pos);
}//------------------------------------


