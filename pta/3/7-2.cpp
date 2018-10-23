#include<iostream>
#include<cstdio>
using namespace std;
class pet {
	public:
		string name;
		int height;
		int weight;
		int date;
		pet(string name,int height,int weight,int date):date(date),name(name),height(height),weight(weight){};
		virtual void growup(int)=0;
		virtual void show()=0;
};
class cat:public pet {
    public:
        cat(string name,int height,int weight,int date):pet(name,height,weight,date){};
        void growup(int n) {
            height+=n-date;
            weight+=2*(n-date);
        }
        void show() {
            printf("%s %d %d\n",name.c_str(),height,weight);
        }
};
class dog:public pet {
    public:
        dog(string name,int height,int weight,int date):pet(name,height,weight,date){};
        void growup(int n) {
            height+=2*(n-date);
            weight+=n-date;
        }
        void show() {
            printf("%s %d %d\n",name.c_str(),height,weight);
        }
};
int main() {
    int n,type,count=0,h,w,d;
    string name;
    pet *p[1000];
    while(scanf("%d",&type)) {
        if(type>10) break;
        cin>>name>>h>>w>>d;
        switch (type) {
            case 1:p[count++]=new cat(name,h,w,d);break;
            case 2:p[count++]=new dog(name,h,w,d);break;
        }
    }
    for(int i=0;i<count;++i) {
        p[i]->growup(type);
        p[i]->show();
    }
        
}
