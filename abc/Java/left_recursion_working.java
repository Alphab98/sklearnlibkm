import java.util.*;
class lr
{
public static void main(String args[])
{
int b[]=new int[15];
String st[]=new String[15];
int j=-1,d=-1,w=-1;
String s[]=new String[15];
String str[]=new String[15];
Scanner sc=new Scanner(System.in);
String gm=sc.nextLine();
gm=gm+"|";
char c[]=gm.toCharArray();

for(int i=0;i<c.length;i++)
{
if(c[i]=='|'||c[i]=='>')
{
j++;
b[j]=i;
}
}

for(int k=0;k<=j;k++)
{
d++;
str[d]="";
for(int l=b[k]+1;l<b[k+1];l++)
{
str[d]=str[d]+c[l];
}
} 

for(int p=0;p<d;p++)
{ 
if(str[p].charAt(0)!=c[0])
{w++;
st[w]=str[p];
System.out.println(c[0]+"->"+st[w]+c[0]+"'");
}
}


  
for(int p=0;p<d;p++)            
{
if(str[p].charAt(0)==c[0])
{
System.out.println(c[0]+"'->"+str[p].substring(1)+c[0]+"'|@");
}}

}}                                                                                                                                                                                                               
