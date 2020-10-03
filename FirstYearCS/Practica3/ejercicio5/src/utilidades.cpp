#include "utilidades.h"
#include "Node.h"
#include "List.h"
/**
 * Primeramente tenemos que saber la longitud de la lista.
 * Luego tenemos que Crear una lista de longitud igual a la de
 * los segmentos. Añadimos sus valores y luego la pasamos a nuestra
 * Lista de Listas y lo volvemos a hacer hasta llegar a la ultima posicion.
 * @param A
 * @param sz
 * @param Segments
 * @return
 */
int Divide(List A, int sz, List* Segments) {
    if (sz>=0) {
        int cont = 0;
        int index = 0;
        for (int j = 0; j <= A.Length() / sz; j++) {
            if (cont < A.Length()) {
                List B;
                for (int i = 0; i < sz && cont + i < A.Length(); i++) {
                    B.AddEnd(A.Obtain(i + cont)->Get_Data());
                }
                cont += sz;
                Segments[index] = B;
                index++;
            }
        }
        return index;
    }else{
        return 0;
    }
}


