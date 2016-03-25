#include<iostream>    
#include<cstring>   
#include<string>  
using namespace std;    
int Next[10001];  
//��KMP��Next����    
void GetNext(const string& p)    
{    
    int len=p.size();    
    int i=0;    
    int j=-1;    
    Next[i]=j;    
    while(i<len)    
    {    
        if(j==-1||p.at(i)==p.at(j))    
        {    
            i++;    
            j++;    
            if(i==len||p.at(i)!=p.at(j))//���������P[i]==P[next[i]]    
                Next[i]=j;    
            else    
                Next[i]=Next[j];    
        }    
        else    
        {    
            j=Next[j];    
        }    
    }    
        
}   
  
  
//SΪĸ����pΪƥ���Ӵ������ƥ�䷵��ƥ��λ�ã����򷵻�-1    
int KMPSearch(const string& s,const string& p)    
{    
    unsigned int Slen=s.size();    
    unsigned int Plen=p.size();  
    //int *Next=new int[Plen];//Next����洢λ��    
    
    GetNext(p);//���Next����    
    
    unsigned int i=0;//��S���е��±�    
    unsigned int j=0;//��P���е��±�    
    unsigned int count=0;//ƥ�䴮���ֵĴ���  
    while(i<Slen)    
    {    
        if(j==-1||s.at(i)==p.at(j))    
        {    
            i++;    
            j++;    
        }    
        else  if(j<Plen)  
            j=Next[j];    
        if(j==Plen)  
        {  
            count++;  
            j=Next[Plen];  
        }  
    }     
    return count;  
}  
  
int main()    
{    
    string str1;    
    string str2;    
    int n;  
    cin>>n;  
    for(int i=0;i<n;i++)  
    {  
        cin>>str2;  
        cin>>str1;   
           
        int pos=KMPSearch(str1,str2);    
        cout<<pos<<endl;   
      
    }  
     
    return 0;    
}    