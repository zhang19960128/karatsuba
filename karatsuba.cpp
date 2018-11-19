#include <iostream>
#include <string>
/**/
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
   return re;
}
void powerten(std::string& input,size_t nb){
   for(size_t i=0;i<nb;i++){
      input=input+'0';
   }
}
std::string add(std::string& one,std::string& two){
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

   delete [] digitone;
   delete [] digittwo;
   delete [] digitsum;
   return transformtostr(digitsum,bigger+1);
}
size_t* prod(size_t* inputone,size_t m,size_t* inputtwo,size_t n){
   if(m<2 && n<2){

   }
   else{
   }
}
int main(){
   std::string input1="3141592653589793238462643383279502884197169399375105820974944592";
   std::string input2="2718281828459045235360287471352662497757247093699959574966967627";
   std::cout<<add(input1,input2)<<std::endl;
}
