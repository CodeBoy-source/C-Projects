#include <iostream>

using namespace std;

class SecuenciaCaracteres {
private:
   static const int SIZE = 100;
   char vec1[SIZE];
   char Vec_Vocal[SIZE] = {'a','e','i','o','u'};
   int used;
public:
   SecuenciaCaracteres() {
      used = 0;
   }
   void Add_Char() {
      char a;
      cin >> a;
      while(a!='0') {
         vec1[used] = a;
         cin >> a;
         used++;
      }
   }

   int Get_Used() {
      return used;
   }

   char Get_Index(int index) {
      return vec1[index];
   }

   bool Is_Vocal(int index) {
      char check = Get_Index(index);
      bool vocal = false;
      for(int i = 0; i < 5; i++) {
         if(check == Vec_Vocal[i]) {
            vocal = true;
         }
      }
      return vocal;
   }

   bool Rima_Asonante(SecuenciaCaracteres sec_b) {
      int i = Get_Used(), j = sec_b.Get_Used();
      bool coincide = true,running=true;
      int Max = (i>j) ? i : j;
      int cont = Max;
      while(cont > 0 && running) {
         if(i<0 || j<0) {
            running = false;
         } else if(Is_Vocal(i)&&sec_b.Is_Vocal(j)&&Get_Index(i)!=sec_b.Get_Index(j)) {
            coincide = false;
         }
         cont--;
         j--;
         i--;
      }
      return coincide;
   }
};

int main(void) {
   SecuenciaCaracteres sec_a;
   SecuenciaCaracteres sec_b;

   cout << "Aniade la sec_a" << endl;
   sec_a.Add_Char();
   cout << "Aniade la sec_b" << endl;
   sec_b.Add_Char();

   bool test = sec_a.Rima_Asonante(sec_b);
   if(test)
      cout << "Tenemos una rima asonante" << endl;
   else
      cout << "No tenemos una rima asonante" << endl;
}
