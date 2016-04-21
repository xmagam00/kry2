#include <iostream>
#include <cstddef>
#include <gmp.h>
#include <cstdlib>
#include <string>
#include <cstring>
#define ll long long


using namespace std;

 ll modulo(ll base, ll exponent, ll mod);
 int calculateJacobian(ll a,ll n);
 bool Solovoy(ll p, int iteration);

int main(int argc, char **argv)
{
	//generate public and private key
	if( strcmp(argv[1], "-g") == 0 && argc == 3) {
		long sizeInBits = atol(argv[2]);
con= true;
long firstNumber = random(0,sizeInBits/2);
long secondNumber = random(0,sizeInBits/2);

while(con) {
 int iteration = 100;
    ll num;
    cout<<"Enter integr to test primality: ";
    cin>>num;
    if (Solovoy(firstNumber, iteration) && Solovoy(firstNumber, iteration)) {
    	con = false;
    } else {
    	firstNumber = random(0,sizeInBits/2);
    	secondNumber = random(0,sizeInBits/2);
    	//generateNew Numbers
    }
}
mpz_t modulus, phin, publicKey;
mpz_init(modulus);
mpz_init(phin);
mpz_init(publicExp);

mpz_mul(modulus, firstNumber, secondNumber);
mpz_mul(phin, firstNumber -1, secondNumber -1);
if (gmp_cmp(gcd(3,phin) == 1) {
	publicExp = 3;
} else {
  publicExp = 2^16+1;
}


	} else if (strcmp(argv[1], "-e") == 0 && argc == 5) {
		//encryption
		mpz_t publicExp;
		mpz_t publicMod; 
		mpz_t message; 
		mpz_t cipher;
	
		mpz_init(cipher);
		 mpz_init_set_str (publicExp, argv[2], 16);
		 mpz_init_set_str( message, argv[3], 16);
		 mpz_init_set_str( publicMod, argv[4], 16);
		//function with do message^publicExp mod publicMod
		mpz_powm(cipher, message, publicExp, publicMod);

		gmp_printf ("%#Zx\n", cipher);
		mpz_clear (publicExp);
		mpz_clear (publicMod);
		mpz_clear (message);
		mpz_clear(cipher);

	} else if (strcmp(argv[1], "-d") == 0 && argc == 5) {
		//encryption
		mpz_t privateExp;
		mpz_t publicMod;
		mpz_t cipher;
		mpz_t message;
	
		mpz_init(message);
	
	 mpz_init_set_str (privateExp, argv[2], 16);
		 mpz_init_set_str( publicMod, argv[3], 16);
		 mpz_init_set_str( cipher, argv[4], 16);

		//function with do message^publicExp mod publicMod
		mpz_powm(message, cipher, privateExp, publicMod);

		gmp_printf ("%#Zx\n", message);


		mpz_clear (privateExp);
		mpz_clear (publicMod);
		mpz_clear (cipher);
		mpz_clear(message);

	} else if (strcmp(argv[1], "-b") == 0 && argc == 3 ) {

	} else {
		cout << "Undefined" << '\n';
	}
	return EXIT_SUCCESS;
}


 ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
/* 
 * calculates Jacobian(a/n) n>0 and n is odd 
 */
int calculateJacobian(ll a,ll n)
{
    if (!a) 
        return 0;
    int ans = 1;
    ll temp;
    if (a < 0)
    {
        a = -a;
        if (n % 4 == 3) 
            ans=-ans; 
    }
    if (a == 1) 
        return ans;
    while (a)
    {
        if (a < 0)
        {
            a = -a;
            if (n % 4 == 3) 
                ans = -ans;  
        }
        while (a % 2 == 0)
        {
            a = a / 2;
            if (n % 8 == 3 || n % 8 == 5) 
                ans = -ans;    
        }
        swap(a, n);
        if (a % 4 == 3 && n % 4 == 3) 
            ans = -ans;
        a = a % n;
        if (a > n / 2) 
            a = a - n; 
    }
    if (n == 1) 
        return ans;
    return 0; 
}
 
/* 
 * Solovay-Strassen Primality Test
 * Iterations determine the accuracy of the test 
 */
bool Solovoy(ll p, int iteration)
{
    if (p < 2) 
        return false;
    if (p != 2 && p % 2 == 0) 
        return false;
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1;
        ll jacobian = (p + calculateJacobian(a, p)) % p;
        ll mod = modulo(a, (p - 1) / 2, p);
        if (!jacobian || mod != jacobian)
        { 
            return false;
        }
    }
    return true;
}


int random(int min, int max) //range : [min, max)
{
   static bool first = true;
   if ( first ) 
   {  
      srand(time(NULL)); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (max - min);
}


 mpz_t gcd( mpz_t x, mpz_t y )
 {
       if(gmp_cmp(x,y) < 0)
          swap( x, y );
      	mpz_t f;
      	mpz_init(f);
       while(gmp_cmp(y,0) > 0 )
       {
          mpz_mod(f,x,y);
          x = y;
          y = f;
       }
       mpz_clear(f);
       return x;
 }  



 mpz_t modInverse(mpz_t a, mpz_t m)
{
    mpz_t m0, t, q;
     mpz_inits(m0,t,q);
     m0 = m;
    mpz_t x0, x1;
      mpz_set_str(x0, "0", 16);
 mpz_set_str(x1, "0", 16);
 
    if (gmp_cmp(m,1) == 0) {
      return 0;
   }
 
    while (a > 1)
    {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}