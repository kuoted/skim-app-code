//
//  SKTRevealTransition.h
//  SkimTransitions
//
//  Created by Christiaan Hofman on 22/5/2019.
//  Copyright Christiaan Hofman 2019-2021. All rights reserved.

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>


@interface SKTRevealTransition : CIFilter
{
    CIImage     *inputImage;
    CIImage     *inputTargetImage;
    CIVector    *inputExtent;
    NSNumber    *inputAngle;
    NSNumber    *inputTime;
}

@property (nonatomic, retain) CIImage *inputImage;
@property (nonatomic, retain) CIImage *inputTargetImage;
@property (nonatomic, retain) CIVector *inputExtent;
@property (nonatomic, retain) NSNumber *inputAngle;
@property (nonatomic, retain) NSNumber *inputTime;

@end
