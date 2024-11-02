#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 512
float V1[N], V2[N], V3[N], V4[N], Mat[N][N], MatDD[N][N];

void InitData(){

	int i,j;
	srand(334411);

	for( i = 0; i < N; i++ )
 		for( j = 0; j < N; j++ ){

 			Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
 			if ( (abs(i - j) <= 3) && (i != j))
 				MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
 			else if ( i == j )
 				MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
 			else MatDD[i][j] = 0.0;
 		}

	for( i = 0; i < N; i++ ){

 		V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 		V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 		V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
	}
}

//------------------------------------------------------------------------
// EXERCICI 1


//------------------------------------------------------------------------
// EXERCICI 2


void PrintRow( float mat[N][N], int row, int from, int numel ){
  for ( int j = from; j <= from+numel; j++ ){
    printf("%f ", mat[row][j]);
  }
  printf("\n");
}

//------------------------------------------------------------------------
// EXERCICI 3


//------------------------------------------------------------------------
// EXERCICI 4

float Scalar( float vect1[N], float vect2[N] ) {
  float producte = 0.0;
  
  for ( int i = 0; i < N; i++ ){
    producte += vect1[i] * vect2[i];
  }
  return producte;
}

//------------------------------------------------------------------------
// EXERCICI 5 (ACABAR)

//------------------------------------------------------------------------
// EXERCICI 6

int Ortogonal( float vect1[N], float vect2[N] ){
  float producte = Scalar( vect1, vect2 );
    
  if (producte == 0){
    return 1;
  }else{
    return 0;
  }
}

//------------------------------------------------------------------------
// EXERCICI 7 (FER)



//------------------------------------------------------------------------
// EXERCICI 8

float Infininorm(float M[N][N]) {
    float max = 0.0;

    for (int i = 0; i < N; i++) {
        float fila = 0.0;

        for (int j = 0; j < N; j++) {
            fila += fabs(M[i][j]);
        }

        if (fila > max) {
            max = fila;
        }
    }

    return max;
}

//------------------------------------------------------------------------
// EXERCICI 9 (FER)



//------------------------------------------------------------------------
// EXERCICI 10

float NormFrobenius( float M[N][N] ){
  float suma = 0.0;
  float NFrob = 0.0;
  
  for (int i = 0; i < N; i++ ){
    for (int j = 0; j < N; j++ ){
      float quadrat = 0.0;
      quadrat = M[i][j] * M[i][j];
      suma += quadrat;
    }
  }
  NFrob = sqrt(suma);
  return NFrob;
}

//------------------------------------------------------------------------
// EXERCICI 11 (FER)



//------------------------------------------------------------------------
// EXERCICI 12

void Matriu_x_Vector( float M[N][N], float vect[N], float vectres[N] ){

  for (int i = 0; i < N; i++ ){
    float fila = 0.0;
    
    for (int j = 0; j < N; j++ ){
      float producte = 0.0;  
      producte = M[i][j] * vect[j];
      fila += producte;
    }
    vectres[i] = fila;
  }
}

//------------------------------------------------------------------------
// EXERCICI 13

int JAplicable( float M[N][N] ){
  int valid = 0;
  
  for (int i=0; i<N; i++){
    float fresta = 0.0;
    
    for (int j=0; i<N; j++){
      
      if (i != j){
        fresta += M[i][j];
      }
    }
    
    if ( fabs(M[i][i]) > fresta ){
      valid += 1;  
    }
  }
  
  if (valid = N){
    return 1;
    
  }else{
    return 0;
    
  }
}

int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned iter ){
  
  int retorn = JAplicable( M );
  
  if (retorn == 1){
    
    float NouV[N];
    for ( int i=0; i<N; i++){
      NouV[i]=0.0;
    }
    
    for ( int k=0; k<iter; k++){
    
      for ( int i=0; i<N; i++){
        float suma = 0.0;
        
        for ( int j=0; j<N; j++){
        
          if (i != j){
            suma += M[i][j]*NouV[i];
          }
        }
        
        NouV[i] = (vect[i] - suma) / M[i][i];
      }
    }
    vectres=NouV;
  }
  return retorn;
}  

//------------------------------------------------------------------------
// PUNT EXTRA

void Precisio( float vectres[N], float vect[N], float vectres2[N], float precisio ){
  
  for ( int i=0; i<N; i++){
    vectres2[i]=fabs(vectres[i]-vect[i]);
  }
  
  precisio = Magnitude( vect2 );
}
  
//------------------------------------------------------------------------
// MAIN

int main(){
}
