//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright © 2022 Vivartan Technologies., All rights reserved/////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//All works published under Zilla_Gen_0 by Vivartan Technologies is copyrighted by the Association and ownership// 
//of all right, title and interest in and to the works remains with Vivartan Technologies. No works or documents//
//published under Zilla_Gen_0 by Vivartan Technologies may be reproduced,transmitted or copied without the expre//
//-ss written permission of Vivartan Technologies will be considered as a violations of Copyright Act and it may//
//lead to legal action.                                                                                         //
//                                                                                                              //
//**************************************************************************************************************//                                                                                                              //
//                                                                                                              //
//FILE NAME:                                                                                                    //
//DESCRIPTION:                                                                                                  //   
//AUTHOR:                                                                                                       //               
//DATE:                                                                                                         //
//LAST MODIFIED BY:                                                                                             //
//LAST MODIFIED ON:                                                                                             //
//                                                                                                              //      
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define SHA_256
//#define SHA_512

#define ARR_SIZE 10

#ifdef  SHA_256
    typedef unsigned int  WORD;
    typedef unsigned char BYTE;   
    #define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
    #define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

    #define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
    #define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
    #define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
    #define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
    #define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
    #define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))
    #define LOAD64H(x, y)                                                      \
   { x = (((WORD)((y)[0]  ))<<24)|(((WORD)((y)[1]  ))<<16) | \
         (((WORD)((y)[2]  ))<<8)|((WORD)((y)[3]  )) ; }

    #define SHA_DATALEN 64
	#define SHA_DATA 64
	#define SHA_HASH 32
	#define SHA_ITER 4
	#define SHA_PAD0 56
	#define SHA_BIT 512
	#define SHA_BLOCK_SIZE 32 
   
   
    #define P0  0x6a09e667
	#define P1  0xbb67ae85
	#define P2  0x3c6ef372
	#define P3  0xa54ff53a
	#define P4  0x510e527f
	#define P5  0x9b05688c
	#define P6  0x1f83d9ab
	#define P7  0x5be0cd19
    
    #define SHA_PAD_MAX 63
    #define SHA_PAD_MIN 55

    #define SHA_REV_A 4
    #define SHA_REV_B 24
    #define SHA_REV_C 255

    static const WORD k[SHA_DATA] = {
	0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
	0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
	0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
	0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
	0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
	0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
	0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
	0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
    };

#endif

#ifdef SHA_512
    typedef unsigned char BYTE; 
    typedef unsigned long int  WORD; 
    #define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (64-(b))))
    #define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (64-(b))))

    #define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
    #define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))


    #define EP0(x)       (ROTRIGHT(x, 28) ^ ROTRIGHT(x, 34) ^ ROTRIGHT(x, 39))
    #define EP1(x)       (ROTRIGHT(x, 14) ^ ROTRIGHT(x, 18) ^ ROTRIGHT(x, 41))
    #define SIG0(x)       (ROTRIGHT(x, 1) ^ ROTRIGHT(x, 8) ^ ((x) >> 7))
    #define SIG1(x)       (ROTRIGHT(x, 19) ^ ROTRIGHT(x, 61) ^ ((x) >> 6))

    #define LOAD64H(x, y)                                   \
   { x = (((WORD)((y)[0]  ))<<56)|(((WORD)((y)[1]  ))<<48) | \
         (((WORD)((y)[2]  ))<<40)|(((WORD)((y)[3]  ))<<32) | \
         (((WORD)((y)[4]  ))<<24)|(((WORD)((y)[5]  ))<<16) | \
         (((WORD)((y)[6]  ))<<8)|(((WORD)((y)[7]  ))); }


    #define SHA_DATALEN 80
	#define SHA_DATA 128
	#define SHA_HASH 64
	#define SHA_ITER 8
	#define SHA_PAD0 120
	#define SHA_BIT 1024
	#define SHA_BLOCK_SIZE 64
   
	
	#define P0  0x6a09e667f3bcc908
    #define P1  0xbb67ae8584caa73b
    #define P2  0x3c6ef372fe94f82b
    #define P3  0xa54ff53a5f1d36f1
    #define P4  0x510e527fade682d1
    #define P5  0x9b05688c2b3e6c1f
    #define P6  0x1f83d9abfb41bd6b
    #define P7  0x5be0cd19137e2179
    
    #define SHA_PAD_MAX 127
    #define SHA_PAD_MIN 119

    #define SHA_REV_A 8
    #define SHA_REV_B 56
    #define SHA_REV_C 65535

    static const WORD k[80] = {
    0x428A2F98D728AE22, 0x7137449123EF65CD, 0xB5C0FBCFEC4D3B2F, 0xE9B5DBA58189DBBC,
    0x3956C25BF348B538, 0x59F111F1B605D019, 0x923F82A4AF194F9B, 0xAB1C5ED5DA6D8118,
    0xD807AA98A3030242, 0x12835B0145706FBE, 0x243185BE4EE4B28C, 0x550C7DC3D5FFB4E2,
    0x72BE5D74F27B896F, 0x80DEB1FE3B1696B1, 0x9BDC06A725C71235, 0xC19BF174CF692694,
    0xE49B69C19EF14AD2, 0xEFBE4786384F25E3, 0x0FC19DC68B8CD5B5, 0x240CA1CC77AC9C65,
    0x2DE92C6F592B0275, 0x4A7484AA6EA6E483, 0x5CB0A9DCBD41FBD4, 0x76F988DA831153B5,
    0x983E5152EE66DFAB, 0xA831C66D2DB43210, 0xB00327C898FB213F, 0xBF597FC7BEEF0EE4,
    0xC6E00BF33DA88FC2, 0xD5A79147930AA725, 0x06CA6351E003826F, 0x142929670A0E6E70,
    0x27B70A8546D22FFC, 0x2E1B21385C26C926, 0x4D2C6DFC5AC42AED, 0x53380D139D95B3DF,
    0x650A73548BAF63DE, 0x766A0ABB3C77B2A8, 0x81C2C92E47EDAEE6, 0x92722C851482353B,
    0xA2BFE8A14CF10364, 0xA81A664BBC423001, 0xC24B8B70D0F89791, 0xC76C51A30654BE30,
    0xD192E819D6EF5218, 0xD69906245565A910, 0xF40E35855771202A, 0x106AA07032BBD1B8,
    0x19A4C116B8D2D0C8, 0x1E376C085141AB53, 0x2748774CDF8EEB99, 0x34B0BCB5E19B48A8,
    0x391C0CB3C5C95A63, 0x4ED8AA4AE3418ACB, 0x5B9CCA4F7763E373, 0x682E6FF3D6B2B8A3,
    0x748F82EE5DEFB2FC, 0x78A5636F43172F60, 0x84C87814A1F0AB72, 0x8CC702081A6439EC,
    0x90BEFFFA23631E28, 0xA4506CEBDE82BDE9, 0xBEF9A3F7B2C67915, 0xC67178F2E372532B,
    0xCA273ECEEA26619C, 0xD186B8C721C0C207, 0xEADA7DD6CDE0EB1E, 0xF57D4F7FEE6ED178,
    0x06F067AA72176FBA, 0x0A637DC5A2C898A6, 0x113F9804BEF90DAE, 0x1B710B35131C471B,
    0x28DB77F523047D84, 0x32CAAB7B40C72493, 0x3C9EBE0A15C9BEBC, 0x431D67C49C100D4C,
    0x4CC5D4BECB3E42B6, 0x597F299CFC657E2A, 0x5FCB6FAB3AD6FAEC, 0x6C44198C4A475817};

#endif

typedef struct {
	BYTE data[SHA_DATA];
	WORD datalen;
	unsigned long long bitlen;
	WORD state[8];
    } SHA_CTX;


/*********************** FUNCTION DEFINITIONS ***********************/
int sha_transform(SHA_CTX *ctx, const BYTE data[])
{

	WORD a, b, c, d, e, f, g, h, i, t1, t2, m[SHA_DATALEN];

	for (i = 0; i < 16; ++i)
    {
      LOAD64H(m[i], data + (SHA_ITER*i));

    }
	for ( ; i < SHA_DATALEN; ++i)
    {
		m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];
    }
   
	a = ctx->state[0];
	b = ctx->state[1];
	c = ctx->state[2];
	d = ctx->state[3];
	e = ctx->state[4];
	f = ctx->state[5];
	g = ctx->state[6];
	h = ctx->state[7];

	for (i = 0; i < SHA_DATALEN; ++i)
    {
		t1 = h + EP1(e) + CH(e,f,g) + k[i] + m[i];
		t2 = EP0(a) + MAJ(a,b,c);
		h = g;
		g = f;
		f = e;
		e = d + t1;
		d = c;
		c = b;
		b = a;
		a = t1 + t2;
	}

	ctx->state[0] += a;
	ctx->state[1] += b;
	ctx->state[2] += c;
	ctx->state[3] += d;
	ctx->state[4] += e;
	ctx->state[5] += f;
	ctx->state[6] += g;
	ctx->state[7] += h;

    return 0;
}

int sha_init(SHA_CTX *ctx)
{


	ctx->datalen = 0;
	ctx->bitlen = 0;

    ctx->state[0] = P0;
	ctx->state[1] = P1;
	ctx->state[2] = P2;
	ctx->state[3] = P3;
	ctx->state[4] = P4;
	ctx->state[5] = P5;
	ctx->state[6] = P6;
	ctx->state[7] = P7;

    return 0;

}

int sha_update(SHA_CTX *ctx, const BYTE data[], size_t len)
{
    
   	WORD i;


	for (i = 0; i < len; ++i) 
    {
       	ctx->data[ctx->datalen] = data[i];
		ctx->datalen++;

        if (ctx->datalen == SHA_DATA)
        {
			sha_transform(ctx, ctx->data);
			ctx->bitlen += SHA_BIT;
			ctx->datalen = 0;
	 	}

    }
    return 0;

}

int sha_final(SHA_CTX *ctx, BYTE hash[])
{
   
	WORD i;

	i = ctx->datalen;

	// Pad whatever data is left in the buffer.
	if (ctx->datalen < SHA_PAD0)
    {
		ctx->data[i++] = 0x80;
		while (i < SHA_PAD0)
		    ctx->data[i++] = 0x00;
	}
	else
    {
		ctx->data[i++] = 0x80;
		while (i < SHA_DATA)
			ctx->data[i++] = 0x00;
		sha_transform(ctx, ctx->data);
		memset(ctx->data, 0, SHA_PAD0);
	}
    

  	// Append to the padding the total message's length in bits and transform.
	ctx->bitlen += ctx->datalen * 8;


    int xx, yy;
    for(xx= SHA_PAD_MAX, yy=0;xx>SHA_PAD_MIN ;xx--, yy++)
	{ 
		ctx->data[xx] = ctx->bitlen >> (8*yy);
	}
    sha_transform(ctx, ctx->data);

	// Since this implementation uses little endian byte ordering and SHA uses big endian,
	// reverse all the bytes when copying the final state to the output hash.
	for (int z = 0; z < SHA_REV_A; z++)
    {		
		for(int j=0;j<8;j++)
		{	
			hash[z + SHA_REV_A*j]  = (ctx->state[j] >> (SHA_REV_B - z * 8)) & SHA_REV_C;  
		}
			
    }   

 
    return hash;


   }
   

#define random_text_sha(mb,text,tn,arr,str,buf)\
            BYTE text[ARR_SIZE] = "";\
            unsigned int arr[ARR_SIZE];\
            for(int y=0;y<ARR_SIZE;y++)\
            {\
                arr[y]=((generate_random_num(mb) % (95)));\
            actual_result[(tn-1)*(SHA_HASH+ARR_SIZE)+ y ] = arr[y];\
            }\
            for(int i = 0; i<ARR_SIZE; i++)\
              { \
                char str = ' ' + arr[i];\
	            strncat(text, &str, 1);\
              }\
           	BYTE buf[SHA_BLOCK_SIZE];\
	        SHA_CTX ctx;\
			sha_init(&ctx);\
        	sha_update(&ctx, text, strlen(text));\
	        sha_final(&ctx, buf);\
            for(int y=0; y<SHA_HASH;y++)\
            {\
			actual_result[((tn-1)*(SHA_HASH+ARR_SIZE))+(y+ARR_SIZE)] =buf[y];\
            }


#define SHA_SPIKE( tn,arr1,text1,corehash,spikehash,out)\
    BYTE out[SHA_BLOCK_SIZE];\
    unsigned int arr1[ARR_SIZE];\
    BYTE text1[ARR_SIZE]="";\
   for(int k=0;k<ARR_SIZE;k++)\
    {\
        arr1[k]= data[(tn-1)*(SHA_HASH+ARR_SIZE)+k];\
        printf("arr1[%d]= %d\n", k, arr1[k]);\
    }\
   for(int q = 0; q<ARR_SIZE; q++)\
   { \
       char ch = ' ' + arr1[q];\
	   strncat(text1, &ch, 1);\
   }\
   BYTE spikehash[SHA_HASH];\
   BYTE corehash[SHA_HASH];\
   for(int p=0;p<SHA_HASH ;p++)\
   {\
   corehash[p]= data[(tn-1)*(SHA_HASH+ARR_SIZE)+ (p+ARR_SIZE)];\
   }\
	SHA_CTX ctx;\
	sha_init(&ctx);\
    sha_update(&ctx, text1, strlen(text1));\
	sha_final(&ctx, out);\
    printf("text1 =%s\n", text1);\
	for(int k=0;k<SHA_HASH;k++)\
	{\
		spikehash[k]=out[k];\
		if(corehash[k]==spikehash[k])\
		{\
			printf(" [PASS] hash value corehash=%x, spikehash=%x \n", corehash[k], spikehash[k]);\
		}\
		else\
		{\
			printf(" [FAIL] hash value corehash=%x, spikehash=%x \n", corehash[k], spikehash[k]);\
		}\
	}	


