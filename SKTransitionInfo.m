//
//  SKTransitionInfo.m
//  Skim
//
//  Created by Christiaan Hofman on 8/10/09.
/*
 This software is Copyright (c) 2009-2021
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

#import "SKTransitionInfo.h"
#import "SKThumbnail.h"

NSString *SKPasteboardTypeTransition = @"net.sourceforge.skim-app.pasteboard.transition";

@implementation SKTransitionInfo

@synthesize transitionStyle, duration, shouldRestrict, thumbnail, toThumbnail;
@dynamic properties, label, title, transitionName;

+ (NSSet *)keyPathsForValuesAffectingValueForKey:(NSString *)key {
    NSSet *keyPaths = [super keyPathsForValuesAffectingValueForKey:key];
    if ([key isEqualToString:@"transitionName"])
        keyPaths = [keyPaths setByAddingObjectsFromSet:[NSSet setWithObjects:@"transitionStyle", nil]];
    return keyPaths;
}

- (id)init {
    self = [super init];
    if (self) {
        transitionStyle = SKNoTransition;
        duration = 1.0;
        shouldRestrict = YES;
        thumbnail = nil;
        toThumbnail = nil;
    }
    return self;
}

- (void)dealloc {
    SKDESTROY(thumbnail);
    SKDESTROY(toThumbnail);
    [super dealloc];
}

+ (NSArray *)readableTypesForPasteboard:(NSPasteboard *)pasteboard {
    return [NSArray arrayWithObjects:SKPasteboardTypeTransition, nil];
}

+ (NSPasteboardReadingOptions)readingOptionsForType:(NSString *)type pasteboard:(NSPasteboard *)pasteboard {
    if ([type isEqualToString:SKPasteboardTypeTransition])
        return NSPasteboardReadingAsPropertyList;
    return NSPasteboardReadingAsData;
}

- (NSArray *)writableTypesForPasteboard:(NSPasteboard *)pasteboard {
    return [NSArray arrayWithObjects:SKPasteboardTypeTransition, nil];
}

- (id)pasteboardPropertyListForType:(NSString *)type {
    if ([type isEqualToString:SKPasteboardTypeTransition])
        return [self properties];
    return nil;
}

- (id)initWithPasteboardPropertyList:(id)propertyList ofType:(NSString *)type {
    self = [self init];
    if (self) {
        if ([type isEqualToString:SKPasteboardTypeTransition]) {
            [self setProperties:propertyList];
        } else {
            [self release];
            self = nil;
        }
    }
    return self;
}

- (NSString *)description {
    return [NSString stringWithFormat:@"<%@ %p> %@", [self class], self, [self properties]];
}

- (NSDictionary *)properties {
    return [NSDictionary dictionaryWithObjectsAndKeys:
                ([SKTransitionController nameForStyle:transitionStyle] ?: @""), SKStyleNameKey,
                [NSNumber numberWithDouble:duration], SKDurationKey,
                [NSNumber numberWithBool:shouldRestrict], SKShouldRestrictKey, nil];
}

- (void)setProperties:(NSDictionary *)dictionary {
    id value;
    if ((value = [dictionary objectForKey:SKStyleNameKey]))
        [self setTransitionStyle:[SKTransitionController styleForName:value]];
    if ((value = [dictionary objectForKey:SKDurationKey]))
        [self setDuration:[value doubleValue]];
    if ((value = [dictionary objectForKey:SKShouldRestrictKey]))
        [self setShouldRestrict:[value doubleValue]];
}

- (NSString *)label {
    if ([self thumbnail] && [self toThumbnail])
        return [NSString stringWithFormat:@"%@\u2192%@", [[self thumbnail] label], [[self toThumbnail] label]];
    return nil;
}

- (NSString *)title {
    return NSLocalizedString(@"Page Transition", @"Box title");
}

- (NSString *)transitionName {
    return [SKTransitionController localizedNameForStyle:[self transitionStyle]];
}

@end
