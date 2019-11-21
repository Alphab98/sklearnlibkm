import java.util.*;
class lfn
{
public static void main(String args[])
{
int b[]=new int[15];
String st[]=new String[15];
int j=-1,d=-1,w=-1,r=-1,min=8;
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

String minstr="";

for(int i=0;i<d;i++){
if(str[i].length()<min)
{
min=str[i].length();
minstr=str[i];
}
}


int minpl=min;
for(int i=0;i<d;i++)
{int x;
for(x=0;x<minpl;x++){
if(minstr.charAt(x)!=str[i].charAt(x))
break;
}
if(x<minpl && minpl>0)
minpl=x;
}
System.out.println(c[0]+"->"+minstr.substring(0,minpl)+c[0]+"'");
 
for(int k=0;k<d;k++)
{
if(str[k].substring(0,minpl).equals(minstr.substring(0,minpl)))
System.out.println(c[0]+"'->"+str[k].substring(minpl));
else
System.out.println(c[0]+"'->"+str[k]);
}
  
}}                                                                                                                                                                                                               
