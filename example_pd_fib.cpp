#include <iostream>
#include <string.h>

using namespace std;

int memo[1001]; //Permite computar até f(1000)

int f(int n){
  
  if(n == 0 || n == 1) return n; //Caso base.
  if(memo[n]!=-1) return memo[n];
  
  return memo[n] = f(n-1) + f(n-2); //Caso geral.
}

int main() 
{
    
  int n;
  cin>>n;
  
  memset(memo, -1, sizeof memo); //Inicializa o vetor memo com -1.
  cout<<f(n)<<endl;
    
    
  return 0;
}
