#pragma once
#define TAB_SIZE      34
#define LTC_SHA256
typedef unsigned __int64 ulong64;
typedef unsigned long ulong32;
#ifdef LTC_SHA256
#include <stdlib.h>
#include <vcruntime.h>
#include <memory.h>
#define LTC_NORETURN __declspec(noreturn)

void crypt_argchk(const char *v, const char *s, int d);


#define MIN(x, y) ( ((x)<(y))?(x):(y) )

#define STORE32H(x, y)                                                                     \
  do { (y)[0] = (unsigned char)(((x)>>24)&255); (y)[1] = (unsigned char)(((x)>>16)&255);   \
       (y)[2] = (unsigned char)(((x)>>8)&255); (y)[3] = (unsigned char)((x)&255); } while(0)

#define LOAD32H(x, y)                            \
  do { x = ((ulong32)((y)[0] & 255)<<24) | \
           ((ulong32)((y)[1] & 255)<<16) | \
           ((ulong32)((y)[2] & 255)<<8)  | \
           ((ulong32)((y)[3] & 255)); } while(0)



#define STORE64H(x, y)                                                                     \
do { (y)[0] = (unsigned char)(((x)>>56)&255); (y)[1] = (unsigned char)(((x)>>48)&255);     \
     (y)[2] = (unsigned char)(((x)>>40)&255); (y)[3] = (unsigned char)(((x)>>32)&255);     \
     (y)[4] = (unsigned char)(((x)>>24)&255); (y)[5] = (unsigned char)(((x)>>16)&255);     \
     (y)[6] = (unsigned char)(((x)>>8)&255); (y)[7] = (unsigned char)((x)&255); } while(0)


#define LTC_ARGCHK(x) do { if (!(x)) { crypt_argchk(#x, __FILE__, __LINE__); } }while(0)
#define LTC_ARGCHKVD(x) do { if (!(x)) { crypt_argchk(#x, __FILE__, __LINE__); } }while(0)

#define RORc(x,n) _lrotr(x,n)
#define XMEMCPY  memcpy

/* a simple macro for making hash "process" functions */
#define HASH_PROCESS(func_name, compress_name, state_var, block_size)                       \
int func_name (hash_state * md, const unsigned char *in, unsigned long inlen)               \
{                                                                                           \
    unsigned long n;                                                                        \
    int           err;                                                                      \
    LTC_ARGCHK(md != NULL);                                                                 \
    LTC_ARGCHK(in != NULL);                                                                 \
    if (md-> state_var .curlen > sizeof(md-> state_var .buf)) {                             \
       return CRYPT_INVALID_ARG;                                                            \
    }                                                                                       \
    if ((md-> state_var .length + inlen) < md-> state_var .length) {                        \
      return CRYPT_HASH_OVERFLOW;                                                           \
    }                                                                                       \
    while (inlen > 0) {                                                                     \
        if (md-> state_var .curlen == 0 && inlen >= block_size) {                           \
           if ((err = compress_name (md, in)) != CRYPT_OK) {                                \
              return err;                                                                   \
           }                                                                                \
           md-> state_var .length += block_size * 8;                                        \
           in             += block_size;                                                    \
           inlen          -= block_size;                                                    \
        } else {                                                                            \
           n = MIN(inlen, (block_size - md-> state_var .curlen));                           \
           XMEMCPY(md-> state_var .buf + md-> state_var.curlen, in, (size_t)n);             \
           md-> state_var .curlen += n;                                                     \
           in             += n;                                                             \
           inlen          -= n;                                                             \
           if (md-> state_var .curlen == block_size) {                                      \
              if ((err = compress_name (md, md-> state_var .buf)) != CRYPT_OK) {            \
                 return err;                                                                \
              }                                                                             \
              md-> state_var .length += 8*block_size;                                       \
              md-> state_var .curlen = 0;                                                   \
           }                                                                                \
       }                                                                                    \
    }                                                                                       \
    return CRYPT_OK;                                                                        \
}


/* error codes [will be expanded in future releases] */
enum {
	CRYPT_OK = 0,             /* Result OK */
	CRYPT_ERROR,            /* Generic Error */
	CRYPT_NOP,              /* Not a failure but no operation was performed */

	CRYPT_INVALID_KEYSIZE,  /* Invalid key size given */
	CRYPT_INVALID_ROUNDS,   /* Invalid number of rounds */
	CRYPT_FAIL_TESTVECTOR,  /* Algorithm failed test vectors */

	CRYPT_BUFFER_OVERFLOW,  /* Not enough space for output */
	CRYPT_INVALID_PACKET,   /* Invalid input packet given */

	CRYPT_INVALID_PRNGSIZE, /* Invalid number of bits for a PRNG */
	CRYPT_ERROR_READPRNG,   /* Could not read enough from PRNG */

	CRYPT_INVALID_CIPHER,   /* Invalid cipher specified */
	CRYPT_INVALID_HASH,     /* Invalid hash specified */
	CRYPT_INVALID_PRNG,     /* Invalid PRNG specified */

	CRYPT_MEM,              /* Out of memory */

	CRYPT_PK_TYPE_MISMATCH, /* Not equivalent types of PK keys */
	CRYPT_PK_NOT_PRIVATE,   /* Requires a private PK key */

	CRYPT_INVALID_ARG,      /* Generic invalid argument */
	CRYPT_FILE_NOTFOUND,    /* File Not Found */

	CRYPT_PK_INVALID_TYPE,  /* Invalid type of PK key */

	CRYPT_OVERFLOW,         /* An overflow of a value was detected/prevented */

	CRYPT_PK_ASN1_ERROR,    /* An error occurred while en- or decoding ASN.1 data */

	CRYPT_INPUT_TOO_LONG,   /* The input was longer than expected. */

	CRYPT_PK_INVALID_SIZE,  /* Invalid size input for PK parameters */

	CRYPT_INVALID_PRIME_SIZE,/* Invalid size of prime requested */
	CRYPT_PK_INVALID_PADDING, /* Invalid padding on input */

	CRYPT_HASH_OVERFLOW      /* Hash applied to too many bits */
};

struct sha256_state {
	ulong64 length;
	ulong32 state[8], curlen;
	unsigned char buf[64];
};
#endif




typedef union Hash_state {
	char dummy[1];
	struct sha256_state sha256;
	void *data;
} hash_state;


/** hash descriptor */
extern struct ltc_hash_descriptor {
	/** name of hash */
	const char *name;
	/** internal ID */
	unsigned char ID;
	/** Size of digest in octets */
	unsigned long hashsize;
	/** Input block size in octets */
	unsigned long blocksize;
	/** ASN.1 OID */
	unsigned long OID[16];
	/** Length of DER encoding */
	unsigned long OIDlen;

	/** Init a hash state
	  @param hash   The hash to initialize
	  @return CRYPT_OK if successful
	*/
	int(*init)(hash_state *hash);
	/** Process a block of data
	  @param hash   The hash state
	  @param in     The data to hash
	  @param inlen  The length of the data (octets)
	  @return CRYPT_OK if successful
	*/
	int(*process)(hash_state *hash, const unsigned char *in, unsigned long inlen);
	/** Produce the digest and store it
	  @param hash   The hash state
	  @param out    [out] The destination of the digest
	  @return CRYPT_OK if successful
	*/
	int(*done)(hash_state *hash, unsigned char *out);
	/** Self-test
	  @return CRYPT_OK if successful, CRYPT_NOP if self-tests have been disabled
	*/
	int(*test)(void);

	/* accelerated hmac callback: if you need to-do multiple packets just use the generic hmac_memory and provide a hash callback */
	int(*hmac_block)(const unsigned char *key, unsigned long  keylen,
		const unsigned char *in, unsigned long  inlen,
		unsigned char *out, unsigned long *outlen);

} hash_descriptor[];


int sha256_init(hash_state * md);
int sha256_process(hash_state * md, const unsigned char *in, unsigned long inlen);
int sha256_done(hash_state * md, unsigned char *out);
int sha256_test(void);
extern const struct ltc_hash_descriptor sha256_desc;