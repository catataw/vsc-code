#include <stdio.h>
#include <string.h>

#include "rsa.h"

#define BUFSIZE  1024

int myrand( void *rng_state);

int main(int argc, char* argv[])
{
	int i;
	unsigned char buf[BUFSIZE];
    rsa_context rsa;

    rsa_init( &rsa, RSA_PKCS_V15, 0 );
    //rsa_gen_key( &rsa, myrand, NULL, 1024, 65537 );
    rsa_gen_key(&rsa, myrand, NULL, 2048, 655373);

    memset(buf, 0, sizeof(buf));
	buf[0]='z'; buf[1]='t'; buf[2]='h';
    rsa_public( &rsa, buf, buf ); 
	printf("rsa_public op=\n");
	for(i=0; i<128; i++)
	{
		printf("%x ", buf[i]);
		if((i+1)%32==0) printf("\n");
	}
	printf("\n\n");
	
    rsa_private( &rsa, buf, buf );  //测试解密后是否是zth

	buf[0]='z'; buf[1]='t'; buf[2]='h';
    rsa_private( &rsa, buf, buf );
	printf("rsa_private op=\n");
	for(i=0; i<128; i++)
	{
		printf("%x ", buf[i]);
		if((i+1)%32==0) printf("\n");
	}

    rsa_public( &rsa, buf, buf );  //测试解密后是否是zth
    rsa_free( &rsa );
}