#include<iostream>
using namespace std;
template <class T>
class MyArray{
    private:
        T *data;
        int size;
    public:
        void sort();
        void append(T t);
};


int main(){
   int a[1000],i;
   cin>>a[0];
   for(i=1;;++i){
    char ch=getchar();
    if(ch==','){
        getchar();
        cin>>a[i];
    }
    else{
        break;
    }

   }
   sort(a,a+i);
   int flag=0;
   for(int j=0;j<i;++j)
   {
       if(flag++) cout<<"     ";
       cout<<a[j];
   }
   cout<<endl<<"请输入一个要求删除的整数\n";
   int de;
   cin>>de;
   for(int j=0;j<i;++j){
        if(a[j]==de)
            for(int g=j;g<i;++g)
                a[g]=a[g+1];
   }
   i--;
   flag=0;
   for(int j=0;j<i;++j)
   {
       if(flag++) cout<<"     ";
       cout<<a[j];
   }
   cin>>de;
   a[i]=de;
   i++;
  sort(a,a+i);
   flag=0;
   for(int j=0;j<i;++j)
   {
       if(flag++) cout<<"     ";
       cout<<a[j];
   }
     
}
