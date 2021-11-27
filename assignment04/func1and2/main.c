
void func1(int a, int b, int c, int d, int e);
void func2(void);

int main()
{
  func2();
  
  return 0;
}

void func1(int a,int b,int c,int d,int e)
{
  volatile int value = 0;
  value = a * b * c * d * e;
  
  return;
}

void func2()
{
  int w = 1, v = 2, x = 3, y = 4, z = 5;
  func1(w,v,x,y,z);
  
  return;
}