#include <iostream>

using namespace std;

int main() {
   const int MAX = 100;
   int pos = 2, lon = 4;
   char ord[MAX] = {'I','D','I','D'};
   int frec[MAX] = {0};
   int casillas[MAX] = {0};

   int i = pos, j = 0;
   while(i>0 && i<100 && j<lon){
      if(ord[j]=='I'){
         frec[i]+=1;
         casillas[j] = i;
         i--;
      }else{
         frec[i]+=1;
         casillas[j]=i;
         i++;
      }
      j++;
   }

   bool sec_correcta = false;
   if(j==lon && (i>0 && i<100)){
      sec_correcta = true;
   }
   if(sec_correcta){
      for(int z = 0; z<lon;z++){
         cout << casillas[z] << " ";
      }
      cout << endl;
      for(int z = 0; z<MAX; z++){
         if(frec[z]!=0)
            cout << "(" << z << "," << frec[z] << ")" << endl;
      }
   }else{
   cout << "No es una instruccion valida" << endl;
   }
}
