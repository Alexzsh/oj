#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

class Student {
    public:
        string name;
        int score;
        Student(string name,int score):name(name),score(score){}
        bool operator<(const Student& s) const{
            return this->score<s.score;
        }
        void print() {
            cout<<"name: "<<name<<"\t"<<"score: "<<score<<endl;
        }
        ~Student() {
        }
};
list<Student> l;
void print(){
    list<Student>::iterator it=l.begin();
    for(;it!=l.end();++it)
        it->print();
    cout<<endl;
}
void searchByName(string name){
    list<Student>::iterator it;
    for(it=l.begin();it!=l.end();++it)
        if(it->name==name){
        
            it->print();
            return;
        }
    cout<<"Can't find this one.Please check your input!\n";
}
void addScore(Student t){
    l.push_back(t);
}
bool sortFunc(Student a,Student b) {
    return a.score>b.score;
}
void sortList(){

    l.sort();
    print();
}
int main(){
    cout<<"Welcome to score system!Please input someone with name and score!End By 'Done!'\n";
    string name;
    int score;
    while(cin>>name){
        if(name=="Done!") break;
        cin>>score;
        addScore(Student(name,score));
    }
    cout<<"Please search someone's score by name\n";
    cin>>name;
    searchByName(name);
    getchar();
    cout<<"Show U the whole list~Please input anykey to continue\n";
    getchar();
    print();
    cout<<"Show U the whole list After sorted~ Please input anykey to continue\n";
    getchar();
    sortList();
}
