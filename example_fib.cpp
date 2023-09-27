#include <iostream>

using namespace std;

int f(int n){
  
  if(n == 0 || n == 1) return n; //Caso base.
  
  return f(n-1) + f(n-2); //Caso geral.
}

int main() 
{
    
  int n;
  cin>>n;
  
  cout<<f(n)<<endl;
    
    
  return 0;
}
