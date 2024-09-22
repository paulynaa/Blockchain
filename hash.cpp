#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
void wypisywanie(char H[],int x){
    x=0;
for(int j=0;j<4;j++){
for(int i=0;i<16;i++)
{
    cout<<H[x]<<" ";x++;
}
cout<<endl;
}
}
void robienie64(char H[],char b[],int x){
for(int j=0;j<4;j++){
for(int i=0;i<16;i++)
{
    H[x]=b[i];x++;
}
}
}

int main()
{
int x=0,y,laikinas;
int z;//z od bituw
string h,c,p;
char b[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char H[64];
char L[64];
char F[99];
robienie64(H,b,x);


int q;
for(int i=0;i<64;i++){
    L[i]=H[i];
}
cin>>h;
int Skaicius=h.size();
cout<<Skaicius;
for(int i=0;i<Skaicius;i++){
q = (int)h[i];
cout<<q<<endl;
}

y=q%16;//y do bituw ^2
x=0;
z=q*2%16;
for(int i=0;i<64;i+=z){
    H[i]=b[(i*z)%16];
    cout<<H[i];
}
cout<<endl;
//laikinas = (((y^2)-1)%16);
for(int i=0;i<64;i+=(((y^2)-1)%16)){// jei y^2-1>=16
    H[i]=b[(i*3)%16];
    cout<<H[i];
}
cout<<endl;
cout<<"Y:"<<" "<<y<<endl;
y=(y^2)+1;
for(int i=y;i<64;i+=y+y){
    for(int j=0;j<y;j++){
    H[i+j+y]=L[i+j];
    cout<<H[i];
    }
}
cout<<endl;
for(int i=0;i<64;i+=y){
    H[i]=b[((i*y)%16)];
    cout<<H[i];
}
cout<<endl;
for(int i=4;i<64;i+=((y+y)/2)%16){
    for(int j=0;j<3;j++){
    H[i+j]=L[i+j-y];
    cout<<H[i];
    }
}
cout<<endl;
wypisywanie(H,x);
return 0;}
