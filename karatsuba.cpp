#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
/*karatsuba algorithm to compute the product of two numbers*/
size_t* transformtoint(std::string input){
   size_t size=input.size();
   size_t* inputone=new size_t [size];
   for(size_t i=0;i<size;i++){
      inputone[i]=input[i]-'0';
   }
   return inputone;
}
std::string transformtostr(size_t* input,size_t m){
   std::string re="";
   size_t sum=0;
   for(size_t i=0;i<m;i++){
      sum=sum+input[i];
      if(sum==0){
         continue;
      }
      re=re+std::to_string(input[i]);
   }
   if(sum==0){
      return "0";
   }
   return re;
}
std::string powerten(std::string input,size_t nb){
   std::string re=input;
   for(size_t i=0;i<nb;i++){
      re=re+'0';
   }
   return re;
}
std::string add(std::string one,std::string two){
   size_t sizeone=one.size();
   size_t sizetwo=two.size();
   size_t bigger=sizetwo>sizeone ? sizetwo : sizeone;
   size_t smaller=sizetwo<sizeone ? sizetwo: sizeone;
   size_t* digitone=transformtoint(one);
   size_t* digittwo=transformtoint(two);
   size_t* digitsum=new size_t [bigger+1];
   for(size_t i=0;i<bigger+1;i++){
      digitsum[i]=0;
   }
   /*currently we don't consider increase to one*/
   for(size_t i=0;i<smaller;i++){
      digitsum[bigger+1-1-i]=digitone[sizeone-1-i]+digittwo[sizetwo-1-i];
   }
   for(size_t i=smaller;i<bigger;i++){
      digitsum[bigger+1-1-i]=sizeone > sizetwo ? digitone[sizeone-1-i] : digittwo[sizetwo-1-i];
   }
   /*finished calculating, now considering increasing one*/
   for(size_t i=bigger;i>0;i--){
      if(digitsum[i]>9){
         digitsum[i]=digitsum[i]%10;
         digitsum[i-1]=digitsum[i-1]+1;
      }
   }
   /*debug
   for(size_t i=0;i<bigger+1;i++){
      std::cout<<digitsum[i]<<std::endl;
   }
   std::cout<<std::endl;
   */
   std::string re=transformtostr(digitsum,bigger+1);
   delete [] digitsum;
   delete [] digitone;
   delete [] digittwo;
   return re;
}
std::string prod(std::string input1,std::string input2){
   size_t m=input1.size();
   size_t n=input2.size();
   size_t valueone;
   size_t valuetwo;
   if(m<2 && n<2){
      std::stringstream streamone;
      std::stringstream streamtwo;
      streamone.str(input1);
      streamtwo.str(input2);
      streamone>>valueone;
      streamtwo>>valuetwo;
      streamone.clear();
      streamtwo.clear();
      return std::to_string(valueone*valuetwo);
   }
   else if(m<2 && n>=2){
      std::string substringone;
      std::string substringtwo;
      size_t middle=floor(input2.size()/2.0);
      substringone=input2.substr(0,middle);
      substringtwo=input2.substr(middle,input2.size()-middle);
      std::string termone;
      std::string termtwo;
      termone=powerten(prod(substringone,input1),substringtwo.size());
      termtwo=prod(substringtwo,input1);
      return add(termone,termtwo);
   }
   else if(m>=2 && n<2){
      std::string substringone;
      std::string substringtwo;
      size_t middle=floor(input1.size()/2.0);
      substringone=input1.substr(0,middle);
      substringtwo=input1.substr(middle,input1.size()-middle);
      std::string termone=powerten(prod(substringone,input2),substringtwo.size());
      std::string termtwo=prod(substringtwo,input2);
      return add(termone,termtwo);
   }
   else{
      std::string a;
      std::string b;
      std::string c;
      std::string d;
      size_t middle1=floor(input1.size()/2.0);
      size_t middle2=floor(input2.size()/2.0);
      a=input1.substr(0,middle1);
      b=input1.substr(middle1,input1.size()-middle1);
      c=input2.substr(0,middle2);
      d=input2.substr(middle2,input2.size()-middle2);
      size_t na=input1.size()-a.size();
      size_t nc=input2.size()-c.size();
      /*four term
       *(a*10^na+b)*(c*10^nc+d)=a*c*10^(na+nc)+a*d*10^(na)+b*c*10^(nc)+b*d;
       * */
      std::string termone=powerten(prod(a,c),na+nc);
      std::string termtwo=powerten(prod(a,d),na);
      std::string termthree=powerten(prod(b,c),nc);
      std::string termfour=prod(b,d);
      return add(add(add(termone,termtwo),termthree),termfour);
   }
}
int main(){
   std::string input1="3141592653589793238462643383279502884197169399375105820974944592";
   std::string input2="2718281828459045235360287471352662497757247093699959574966967627";
   std::string temp1="1";
   std::string temp2="1";
   std::cout<<prod(temp1,temp2)<<std::endl;
   for(size_t i=10;i<10000;i++){
      std::cout<<i<<std::endl;
      for(size_t j=10;j<10000;j++){
         if(prod(std::to_string(i),std::to_string(j))!=std::to_string(i*j)){
            std::cout<<"fuck you: "<<i<<" "<<j<<std::endl;
         };
      }
   }
}
