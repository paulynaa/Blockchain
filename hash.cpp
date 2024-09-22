#include<iostream>
#include<fstream>
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
int x=0,y;
int z=2;//z od bituw
string h,c,p;
char b[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char H[64];
char L[64];
robienie64(H,b,x);
y=4;//y do bituw ^2
x=0;
for(int i=0;i<64;i+=z){
    H[i]=b[(i*2)%16];
}
y=4-1;// bo ^2-1
for(int i=0;i<64;i+=y){
    H[i]=b[(i*3)%16];
}
for(int i=0;i<64;i++){
    L[i]=H[i];
}
y=4;
for(int i=4;i<64;i+=8){
    for(int j=0;j<y;j++){
    H[i+j]=L[i+j-y];
    }
}
for(int i=0;i<64;i+=y){
    H[i]=b[((i*3)%16)];
}
for(int i=4;i<64;i+=3){
    for(int j=0;j<3;j++){
    H[i+j]=L[i+j-y];
    }
}
wypisywanie(H,x);
return 0;}
