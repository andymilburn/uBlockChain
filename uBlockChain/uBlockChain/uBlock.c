//
//  uBlock.c
//  uBlockChain
//
//  Created by Andy Milburn on 11/7/17.
//  Copyright © 2017 uNET. All rights reserved.
//

/*
 
 We have to decide and decree if the data is binary or ascii
 
 COULD store binary data and uuencode/decode for hash production and transmission but this is inefficient
 
 */

#include "uBlock.h"
#include <stdlib.h>


// the block's data can be any binary values
// this utility makes it ascii-safe for transmission and hashing

dobj stringFromBlockData(UBlock *aBlock) {
    
}


/*
 The simple requirement is that everyone knows how to generate a block’s header, and within the header is the previous block’s hash. This is so everyone can confirm the correct hash for the new block, and validate the link between the two blocks.
 */

char *headerForBlock(UBlock *aBlock) {
    char *dataString = stringFromBlockData(aBlock)->stringObj.ptr;
    unsigned long headerSize = strlen(dataString) + strlen(aBlock->prevHash->stringObj.ptr);
    char *answer = malloc(headerSize + 1); // add 1 for the ending 0
    strcpy(answer, aBlock->prevHash->stringObj.ptr);
    
    return answer;
}

char *updateHashForBlock(UBlock *aBlock) {
    char *aHeader = headerForBlock(aBlock); // the string from which we create the block's hash
    SHA256_CTX    ctx256;
    SHA256_Init(&ctx256);
    SHA256_Update(&ctx256, (u_int8_t *)aHeader, strlen((char *)aHeader));
    char *answer = malloc(SHA256_DIGEST_LENGTH);
    SHA256_End(&ctx256, answer);
    free(aHeader);
    aBlock->hash = StringObjectConstruct(answer);
    return answer;
}
