/* This program calculates the Key for two persons  
using the Diffie-Hellman Key exchange algorithm and use  key for encrypting message */
#include<stdio.h> 
#include<math.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
// Power function to return value of a ^ b mod P 
long long int generator(long long int a, long long int b, 
                                     long long int P) 
{  
    if (b == 1) 
        return a; 
  
    else
        return (((long long int)pow(a, b)) % P); 
} 
  bool is_prime(long long int  p){
	 int i,j;
    j = sqrt(p);
    for (i = 2; i <= j; i++)
    {
        if (p % i == 0)
            return false;
    }
    return true;
}

//Driver program 
int main() 
{

    long long int P, G, x, a, y, b, ka, kb,i; 
      char  message[1000];
    // Both the persons will be agreed upon the  
        // public keys G and P  
     // A prime number P is taken 
      
    printf("The value of P : "); 
	scanf("%lld",&P);
  if(!is_prime(P)){
  	printf("Wrong input,P  should  be a prime  number \n");
  	exit(0);
  }
  
    printf("The value of G : ");  
  	scanf("%lld",&G);
    // Alice will choose the private key a  
    a = rand()%P; // a is the chosen private key  
    printf("The private key a for Alice : %lld\n", a); 
    x = generator(G, a, P); // gets the generated key 
      
    // Bob will choose the private key b 
    b = rand()%P; // b is the chosen private key 
    printf("The private key b for Bob : %lld\n\n", b); 
    y = generator(G, b, P); // gets the generated key 
  
    // Generating the secret key after the exchange 
        // of keys 
    ka = generator(y, a, P); // Secret key for Alice 
    kb = generator(x, b, P); // Secret key for Bob 
      
    printf("Secret key for the Alice is : %lld\n", ka); 
    printf("Secret Key for the Bob is : %lld\n", kb); 
    
    printf("Enter  message  to  be encrypted:   ");
    scanf("%s",&message);
    
    int  len=strlen(message);
    int cipher[len];
	printf("Encrypted  message is:  \n");
    for(i=0;i<len;i++){
    	int d=("%d", (message[i]))*ka;
    	cipher[i]=d;
    	//	printf(" %d  ",d );
    	printf("%d",cipher[i] );
	}
	char  plain[len]; 
		printf("Decrypted  message is:  \n");
	for(i=0;i<len;i++){
	int c=("%c", (cipher[i]))/ka;
    	plain[i]=c;
    	//	printf(" %d  ",d );
    	printf("%c",plain[i] );
}
    return 0; 
} 
