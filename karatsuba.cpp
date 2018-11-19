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
   for(size_t i=0;i<m;i++){
      re=re+std::to_string(input[i]);
   }
   return re;
}
void powerten(std::string& input,size_t nb){

}
size_t* prod(size_t* inputone,size_t m,size_t* inputtwo,size_t n){
   if(m<2 || n<2){
   }
   else{
   }
}
int main(){
   std::string input1="3141592653589793238462643383279502884197169399375105820974944592";
   std::string input2="2718281828459045235360287471352662497757247093699959574966967627";
   size_t* inputone=transformtoint(input1);
   size_t* inputtwo=transformtoint(input2);
   std::cout<<transformtostr(inputone,64);
}
