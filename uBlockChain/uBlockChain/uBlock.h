//
//  uBlock.h
//  uBlockChain
//
//  Created by Andy Milburn on 11/7/17.
//  Copyright © 2017 uNET. All rights reserved.
//

#ifndef uBlock_h
#define uBlock_h

#include <stdio.h>
#include <string.h>
#include "libdoh.h"
#include "sha2.h"

extern SHA256_CTX    ctx256;


typedef struct UBlock {
    dobj timeStamp;
    unsigned long index;
    dobj prevHash;
    dobj hash;
    dobj data;
} UBlock;

char *headerForBlock(UBlock *aBlock);
char *updateHashForBlock(UBlock *aBlock);

#endif /* uBlock_h */
