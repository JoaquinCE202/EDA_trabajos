#include <iostream>

using namespace std;

int fibonacci(int n)
{
  if(n==1 || n==0)
  {
    return n;
  }

  else
  {
    return fibonacci(n-1)+fibonacci(n-2);
  }
}

int fibo_iterativo(int n)
{
  int a =0;
  int b=1;
  int c;
  for(int x=0;x<n-1;x++)
    {
      c=a+b;
      a=b;
      b=c;
    }
  return c;
}


int** multiplicacion_matrices(int **A, int **B) {
  int **C;
  C=new int*[2];
  for(int x=0;x<2;x++)
    {
    C[x]=new int[2];
    }
  for(int x=0;x<2;x++)
    {
      for(int y=0;y<2;y++)
        {
          C[x][y]=1;
        }
    }
    int aux=0;
    for (int x = 0; x < 2; x++) 
    {
        for (int y = 0; y < 2; y++)
          {
            for (int z = 0; z < 2; z++) 
            {
                aux+= A[x][z] * B[z][y];
            }
            C[x][y]=aux;
            aux=0;
        }
    }
  return C;
  
}

int ** potencia(int ** &a, int n,int **identity)
{
  if(n==0)
  {
    return identity;
  }
  if(n==1)
  {
    return a;
  }
  int** aux=potencia(a,n/2,identity);
  return multiplicacion_matrices(multiplicacion_matrices(aux,aux),potencia(a,n%2,identity));
}

int fibo_log(int n)
{
  int **A;
  A=new int*[2];
  for(int x=0;x<2;x++)
    {
    A[x]=new int[2];
    }
  int **result;
  A[0][0]=0;
  A[0][1]=1;
  A[1][0]=1;
  A[1][1]=1;
  
  int **identity;
  identity=new int*[2];
  for(int x=0;x<2;x++)
    {
    identity[x]=new int[2];
    }
  for(int x=0;x<2;x++)
    {
      for(int y=0;y<2;y++)
        {
          if(x==y)
          {
            identity[x][y]=1;
          }
          else{
            identity[x][y]=0;
          }
        }
    }
  
  result=potencia(A,n-1,identity);
  return result[1][1];
  
}


int main() {

  cout<<"recursivo: "<<fibonacci(5)<<endl;
  cout<<"iterativo: "<<fibo_iterativo(5)<<endl;
  cout<<"log: "<<fibo_log(5)<<endl;

  cout<<"recursivo: "<<fibonacci(7)<<endl;
  cout<<"iterativo: "<<fibo_iterativo(7)<<endl;
  cout<<"log: "<<fibo_log(7)<<endl;
  
  cout<<"recursivo: "<<fibonacci(9)<<endl;
  cout<<"iterativo: "<<fibo_iterativo(9)<<endl;
  cout<<"log: "<<fibo_log(9)<<endl;
  
  cout<<"recursivo: "<<fibonacci(11)<<endl;
  cout<<"iterativo: "<<fibo_iterativo(11)<<endl;
  cout<<"log: "<<fibo_log(11)<<endl;

}
