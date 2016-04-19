#include <iostream>
#include <cstddef>
#include <gmp.h>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;
int main(int argc, char **argv)
{
	//generate public and private key
	if( strcmp(argv[1], "-g") == 0 && argc == 3) {
		long sizeInBits = atol(argv[2]);
		


	} else if (strcmp(argv[1], "-e") == 0 && argc == 5) {
		//encryption
		mpz_t publicExp;
		mpz_t publicMod; 
		mpz_t message; 
		mpz_t cipher;
		mpz_init(publicExp);
		mpz_init(publicMod);
		mpz_init(message);
		mpz_init(cipher);
		mpz_set_str(publicExp,argv[2] + 2,16); 
		mpz_set_str( argv[3], NULL, 16);
		mpz_set_str( argv[4], NULL, 16);
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
		mpz_init(publicExp);
		mpz_init(publicMod);
		mpz_init(message);
		mpz_init(cipher);
		privateExp = strtoul( argv[2], NULL, 16);
		publicMod = strtoul( argv[3], NULL, 16);
		cipher = strtoul( argv[4], NULL, 16);

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


 function GCD(x,y) returns integer;
         /* return greatest common divisor of x > 0 and y > 0 */
         s := x; t := y; 
         while (s > 0) do
            div := s; s := t mod s; t := div;
         end while;
         return(div);
      end GCD;


      function INVERSE(n,x) returns integer;
         /* for n > 0 and x î Zn* return u î Zn* 
            with u * x đ 1 (mod n) */
         procedure Update(a,b);
            temp := b; b := a - y * temp; a := temp;
         end Update;
         g := n; h := x; w := 1; z := 0; v := 0; r := 1;
         while (h > 0) do
            y : = [g/h]; Update(g,h); Update(w,z); Update(v,r);
         end while;
         return(v mod n);
      end INVERSE;