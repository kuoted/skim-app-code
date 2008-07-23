//
//  NSObject_SKExtensions.h
//  Skim
//
//  Created by Christiaan Hofman on 2/15/07.
/*
 This software is Copyright (c) 2008
 Christiaan Hofman. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 
 - Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 
 - Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in
 the documentation and/or other materials provided with the
 distribution.
 
 - Neither the name of Christiaan Hofman nor the names of any
 contributors may be used to endorse or promote products derived
 from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Cocoa/Cocoa.h>

#define OBINITIALIZE \
    do { \
        static BOOL hasBeenInitialized = NO; \
        [super initialize]; \
        if (hasBeenInitialized) \
            return; \
        hasBeenInitialized = YES;\
    } while (0);


@interface NSObject (SKExtensions)

+ (IMP)setMethod:(IMP)anImp typeEncoding:(const char *)types forSelector:(SEL)aSelector;
- (IMP)setMethod:(IMP)anImp typeEncoding:(const char *)types forSelector:(SEL)aSelector;
+ (IMP)setInstanceMethod:(IMP)anImp typeEncoding:(const char *)types forSelector:(SEL)aSelector;

+ (IMP)setMethodFromSelector:(SEL)impSelector forSelector:(SEL)aSelector;
- (IMP)setMethodFromSelector:(SEL)impSelector forSelector:(SEL)aSelector;
+ (IMP)setInstanceMethodFromSelector:(SEL)impSelector forSelector:(SEL)aSelector;

+ (void)exchangeMethodForSelector:(SEL)aSelector1 withMethodForSelector:(SEL)aSelector2;
- (void)exchangeMethodForSelector:(SEL)aSelector1 withMethodForSelector:(SEL)aSelector2;
+ (void)exchangeInstanceMethodForSelector:(SEL)aSelector1 withInstanceMethodForSelector:(SEL)aSelector2;

@end
