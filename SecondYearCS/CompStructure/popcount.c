// gcc popcount.c -o popcount -Og -g -D TEST=1
/*
=== TESTS === ____________________________________
    for i in 0 g 1 2; do
        printf "__OPTIM%1c__%48s\n" $i "" | tr " " "="
        for j in $(seq 1 4); do
            printf "__TEST%02d__%48s\n" $j "" | tr " " "-"
            rm popcount
            gcc popcount.c -o popcount -O$i -D TEST=$j -g
            ./popcount
        done
    done
=== CRONOS === ____________________________________
    for i in 0 g 1 2; do
        printf "__OPTIM%1c__%48s\n" $i "" | tr " " "="
        rm popcount
        gcc popcount.c -o popcount -O$i -D TEST=0
        for j in $(seq 0 10); do
            echo $j; ./popcount
         done | pr -11 -l 22 -w 80
    done
___________________________________________________
*/
#include <stdio.h>		// para printf()
#include <stdlib.h>		// para exit()
#include <sys/time.h>		// para gettimeofday(), struct timeval

/*#define SIZE (1<<16) 		// tamaÃ±o suficiente para tiempo apreciable
int lista[SIZE];*/
int resultado=0;

#ifndef TEST
#define TEST 1
#endif
/* -------------------------------------------------------------------- */
#if TEST==1
/* -------------------------------------------------------------------- */
#define SIZE 4
unsigned lista[SIZE]={0x80000000, 0x00400000, 0x00000200, 0x00000001};
#define RESULT 4
/* -------------------------------------------------------------------- */
#elif TEST==2
/* -------------------------------------------------------------------- */
#define SIZE 8
unsigned lista[SIZE]={0x7fffffff,0xffbfffff,0xfffffdff,0xfffffffe,0x01000023,0x00456700,0x8900ab00,0x00cd00ef};
#define RESULT 156
/* -------------------------------------------------------------------- */
#elif TEST==3
#define SIZE 8
unsigned lista[SIZE]={0x0,0x01020408,0x35906a0c,0x70b0d0e0,0xffffffff,0x12345678,0x9abcdef0,0xdeadbeef};
#define RESULT 116
#elif TEST==4 || TEST==0
/* -------------------------------------------------------------------- */
#define NBITS 20
#define SIZE (1<<NBITS)
// tamaÃ±o suficiente para tiempo apreciable
unsigned lista[SIZE];
// unsigned para desplazamiento derecha lÃ³gico
#define RESULT ( NBITS * ( 1 << NBITS-1 ) )
// pistas para deducir fÃ³rmula
/* -------------------------------------------------------------------- */
#else
#error "Definir TEST entre 0..4"
#endif
/* -------------------------------------------------------------------- */

#define WSIZE 8*sizeof(long)
long pcount_for(unsigned long x)
{
    size_t i;
    long result = 0;
    for (i = 0; i < WSIZE; i++)
    {
        result += x & 0x1;
        x >>= 1;
    }
    return result;
}

// ############################################################### //

long pcount_while(unsigned long x)
{
    long result = 0;
    while (x)
    {
        result += x & 0x1;
        x >>= 1;
    }
    return result;
}

// ############################################################### //

int popcount1(unsigned* array, size_t len){
    int suma = 0;
    for(int i=0;i<len;i++){
        suma += pcount_for(array[i]);
    }
    return suma;
}

// ############################################################### //

int popcount2(unsigned* array, size_t len){
    int suma = 0;
    for(int i=0;i<len;i++){
        suma += pcount_while(array[i]);
    }
    return suma;
}

// ############################################################### //

int popcount3(unsigned * array, size_t len){
    size_t i;
    unsigned x;
    int result = 0;
    for(i=0; i < len; i++){
        x = array[i];
        asm("\n"
        "ini3:                 \n\t"
                "shr %[x]       \n\t"
                "adc $0,%[r]    \n\t"
                "test %[x], %[x] \n\t"
                "jnz ini3"

                : [r] "+r" (result)
                : [x] "r" (x)

            );
    }
    return result;
}

// ############################################################### //

int popcount4(unsigned* array, size_t len){
    size_t i;
    unsigned x;
    int result = 0;

    for(i=0;i < len;i++){
        x = array[i];
        asm("\n"
        "clc                        \n\t" //Para poder empexar por ADC
        "ini4:                      \n\t"
            "adc    $0x0, %[r]        \n\t" // Sumamos los carrys a medida que los provoca shr
            "shr    %[x]            \n\t" 
            "jnz    ini4            \n\t"
            "adc    $0x0, %[r]        \n\t" // En caso de que hubiese un 1 en la ultima posicion

            : [r] "+r" (result)
            : [x] "r" (x)

            );
    }
    return result;
}

// ############################################################### //

int popcount5(unsigned* array, size_t len){
    size_t i;
    unsigned x, val;
    int result = 0;

    for( i = 0; i < len; i++){
        val = 0;
        x = array[i];
        for(size_t j=0;j<8;j++){
            val += x & 0x01010101L; // mask it
            x >>= 1; // shr
        }
        val += ( val >> 16 );
        val += ( val >> 8  );
        val &= 0xFF;
        result += val;
    }

    return result;

}

// ############################################################### //

//types and constants used in the functions below
//uint64_t is an unsigned 64-bit integer type (defined in C99 version of C language)
const unsigned long m1  = 0x5555555555555555; //binary: 0101...
const unsigned long m2  = 0x3333333333333333; //binary: 00110011..
const unsigned long m4  = 0x0f0f0f0f0f0f0f0f; //binary: 4 zeros, 4 ones ...
const unsigned long m8  = 0x00ff00ff00ff00ff; //binary: 8 zeros, 8 ones ...
const unsigned long m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
const unsigned long m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones
//This is a naive implementation, shown for comparison,
unsigned long popcount64a(unsigned long x)
{
    x = (x & m1 ) + ((x >> 1) & m1 ); //put count of each 2 bits into
    x = (x & m2 ) + ((x >> 2) & m2 ); //put count of each 4 bits into
    x = (x & m4 ) + ((x >> 4) & m4 ); //put count of each 8 bits into
    x = (x & m8 ) + ((x >> 8) & m8 ); //put count of each 16 bits into
    x = (x & m16) + ((x >> 16) & m16); //put count of each 32 bits into
    x = (x & m32) + ((x >> 32) & m32); //put count of each 64 bits into
    return x;
}

int popcount6(unsigned* array, size_t len){
    size_t i;
    unsigned long x;
    int result = 0;

    for(i = 0; i < len; i+=2){
        x = *(unsigned long*) &array[i];
        result += popcount64a(x);
    }
    return result;
}

// ############################################################### //

int popcount7(unsigned* array, size_t len){
    int result = 0;
    unsigned long x, x2;
    size_t i;
    for(i = 0; i < len; i+=4){
        x = *(unsigned long*) &array[i];
        x2 = *(unsigned long*) &array[i+2];
        result += popcount64a(x) + popcount64a(x2);
    }
    return result;
}

// ############################################################### //

int popcount8(unsigned* array, size_t len){
    int result = 0;
    unsigned long valor;
    int SSE_mask[] = { 0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f};
    int SSE_LUTb[] = { 0x02010100, 0x03020201, 0x03020201, 0x04030302};
    //                    3 2 1 0,    7 6 5 4    1110 9 8    15141312

    if(len & 0x3) printf("Leyendo 128b, pero len no mÃºltiplo de 4\n");
    for(size_t i = 0; i < len; i+=4){
        asm("movdqu     %[x],   %%xmm0          \n\t"
            "movdqa     %%xmm0, %%xmm1          \n\t"
            "movdqu     %[m],   %%xmm6          \n\t"
            "psrlw      $4,     %%xmm1          \n\t"
            "pand       %%xmm6, %%xmm0          \n\t"
            "pand       %%xmm6, %%xmm1          \n\t"

            "movdqu     %[l],   %%xmm2          \n\t"
            "movdqa     %%xmm2, %%xmm3          \n\t"
            "pshufb     %%xmm0, %%xmm2          \n\t"
            "pshufb     %%xmm1, %%xmm3          \n\t"

            "paddb      %%xmm2, %%xmm3          \n\t"
            "pxor       %%xmm0, %%xmm0          \n\t"
            "psadbw     %%xmm0, %%xmm3          \n\t"
            "movhlps    %%xmm3, %%xmm0          \n\t"
            "paddd      %%xmm3, %%xmm0          \n\t"
            "movd       %%xmm0, %[valor]        \n\t"

            : [valor]   "=r"    (valor)
            : [x]       "m"     (array[i]),
              [m]       "m"     (SSE_mask[0]),
              [l]       "m"     (SSE_LUTb[0])
            );
        result += valor;
    }
    return result;
}

// ############################################################### //

int popcount9(unsigned* array, size_t len){
    size_t i;
    unsigned x;
    int val, result = 0;

    for(i = 0; i < len ; i++){
        x = array[i];
        asm("popcnt %[x],%[val]"

            : [val] "=r" (val)
            : [x] "r" (x)

            );
        result += val;
    }
    return result;
}

// ############################################################### //

int popcount10(unsigned* array, size_t len){
    size_t i;
    unsigned long x1,x2;
    long val; int result = 0;
    if(len & 0x3)printf("Leyendo 128b pero len no multiplo de 4\n");
    for(i=0;i<len;i+=4){
        x1 = *(unsigned long*) &array[i  ];
        x2 = *(unsigned long*) &array[i+2];
        asm("popcnt %[x1],%[val]\n\t"
            "popcnt %[x2],%[x1]\n\t"
            "add %[x1], %[val]\n\t"
            :[val] "=&r" (val)
            :[x1] "r" (x1),
            [x2] "r" (x2)

            );
        result += val;
    }

    return result;

}

// ############################################################### //


void crono(int (*func)(), char* msg){
    struct timeval tv1,tv2; 			// gettimeofday() secs-usecs
    long           tv_usecs;			// y sus cuentas

    gettimeofday(&tv1,NULL);
    resultado = func(lista, SIZE);
    gettimeofday(&tv2,NULL);

    tv_usecs=(tv2.tv_sec -tv1.tv_sec )*1E6+
             (tv2.tv_usec-tv1.tv_usec);

#if TEST==0
    printf( "%ld" "\n",tv_usecs);
#else
    printf("resultado = %d\t", resultado);
    printf("%s:%9ld us\n", msg, tv_usecs);
#endif
}



int main()
{
#if TEST==0 || TEST==4
        size_t i;
        for (i=0; i<SIZE; i++)
            lista[i]=i;
#endif

    crono(popcount1,"popcount1 (Lenguaje C -         for");
    crono(popcount2,"popcount2 (Lenguaje C -       while");
    crono(popcount3,"popcount3 (Leng. ASM_body while 4i)");
    crono(popcount4,"popcount4 (Leng. ASM-body while 3i)");
    crono(popcount5,"popcount5 (CSS:APP2e 3.49-group 8b)");
    crono(popcount6,"popcount6 (Wikipedia - naive - 32b)");
    crono(popcount7,"popcount7 (Wikipedia - naive -128b)");
    crono(popcount8,"popcount8 (asm  SSE3 - pshufb 128b)");
    crono(popcount9,"popcount9 (asm SSE4 - popcount 32b)");
    crono(popcount10,"popcount10(asm SSE4 popcount 128b)");


#if TEST != 0
    printf("calculado = %d\n", RESULT);
#endif

    exit(0);
}