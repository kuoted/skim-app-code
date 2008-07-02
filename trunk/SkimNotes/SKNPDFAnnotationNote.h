//
//  SKNPDFAnnotationNote.h
//  SkimNotes
//
//  Created by Christiaan Hofman on 6/15/08.
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

/*!
    @header      SKNPDFAnnotationNote.h
    @discussion  This file defines a concrete PDFAnnotation class representing a SKim anchored note.
*/
#import <Cocoa/Cocoa.h>
#import <Quartz/Quartz.h>

extern NSString *SKNPDFAnnotationTextKey;
extern NSString *SKNPDFAnnotationImageKey;

extern NSSize SKNPDFAnnotationNoteSize;

/*!
    class        SKNPDFAnnotationNote
    @abstract    A concrete PDFAnnotation subclass, a subclass of PDFAnnotationText, representing a Skim anchored note.
    @discussion  This is a PDFAnnotationText subclass containing a separate short string value, a longer rich text property, and an image property.
*/
@interface SKNPDFAnnotationNote : PDFAnnotationText {
    NSString *string;
    NSImage *image;
    NSTextStorage *textStorage;
    NSAttributedString *text;
    NSArray *texts;
}

/*!
    @method     string
    @abstract   This is overridden and different from the contents.
    @discussion This should give a short string value for the anchored note annotation. 
    @result     A string representing the string value associated with the annotation.
*/
- (NSString *)string;

/*!
    @method     setString:
    @abstract   This is overridden and different from the contents.
    @discussion This should set the short string value of the annotation.  This updates the contents using updateContents.
    @param      newString The new string value for the annotation.
*/
- (void)setString:(NSString *)newString;

/*!
    @method     text
    @abstract   The rich text of the annotation.
    @discussion This is the longer rich text contents of the anchored note annotation.
*/
- (NSAttributedString *)text;

/*!
    @method     setText:
    @abstract   Sets the rich text of the annotation.
    @discussion This should set the longer rich text contents of the annotation.  This updates the contents using updateContents.
    @param      newText The new rich text value for the annotation.
*/
- (void)setText:(NSAttributedString *)newText;

/*!
    @method     image
    @abstract   The image of the annotation.
    @discussion 
*/
- (NSImage *)image;

/*!
    @method     setImage:
    @abstract   Sets the image of the annotation.
    @discussion 
    @param      newImage The new image for the annotation.
*/
- (void)setImage:(NSImage *)newImage;

/*!
    @method     updateContents
    @abstract   Synchronizes the contents of the annotation with the string and text.
    @discussion This sets the contents to the string value and the text appended, separated by a double space.
*/
- (void)updateContents;

@end
