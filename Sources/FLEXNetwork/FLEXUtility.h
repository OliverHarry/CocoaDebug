//
//  Example
//  man
//
//  Created by man on 11/11/2018.
//  Copyright © 2018 man. All rights reserved.
//

#import <Availability.h>
#import <AvailabilityInternal.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <objc/runtime.h>

#define FLEXFloor(x) (floor([[UIScreen mainScreen] scale] * (x)) / [[UIScreen mainScreen] scale])

#if defined(__IPHONE_11_0)
#define FLEX_AT_LEAST_IOS11_SDK (__IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_11_0)
#else
#define FLEX_AT_LEAST_IOS11_SDK NO
#endif

@interface FLEXUtility : NSObject

+ (UIColor *)consistentRandomColorForObject:(id)object;
+ (NSString *)descriptionForView:(UIView *)view includingFrame:(BOOL)includeFrame;
+ (NSString *)stringForCGRect:(CGRect)rect;
+ (UIViewController *)viewControllerForView:(UIView *)view;
+ (UIViewController *)viewControllerForAncestralView:(UIView *)view;
+ (NSString *)detailDescriptionForView:(UIView *)view;
+ (UIImage *)circularImageWithColor:(UIColor *)color radius:(CGFloat)radius;
+ (UIColor *)scrollViewGrayColor;
//+ (UIColor *)hierarchyIndentPatternColor; //liman
+ (NSString *)applicationImageName;
+ (NSString *)applicationName;
+ (NSString *)safeDescriptionForObject:(id)object;
+ (UIFont *)defaultFontOfSize:(CGFloat)size;
+ (UIFont *)defaultTableViewCellLabelFont;
+ (NSString *)stringByEscapingHTMLEntitiesInString:(NSString *)originalString;
+ (UIInterfaceOrientationMask)infoPlistSupportedInterfaceOrientationsMask;
+ (NSString *)searchBarPlaceholderText;
+ (BOOL)isImagePathExtension:(NSString *)extension;
+ (UIImage *)thumbnailedImageWithMaxPixelDimension:(NSInteger)dimension fromImageData:(NSData *)data;
+ (NSString *)stringFromRequestDuration:(NSTimeInterval)duration;
+ (NSString *)statusCodeStringFromURLResponse:(NSURLResponse *)response;
+ (BOOL)isErrorStatusCodeFromURLResponse:(NSURLResponse *)response;
+ (NSDictionary<NSString *, id> *)dictionaryFromQuery:(NSString *)query;
+ (NSString *)prettyJSONStringFromData:(NSData *)data;
+ (BOOL)isValidJSONData:(NSData *)data;
+ (NSData *)inflatedDataFromCompressedData:(NSData *)compressedData;

+ (NSArray<UIWindow *> *)allWindows;

// Swizzling utilities

+ (SEL)swizzledSelectorForSelector:(SEL)selector;
+ (BOOL)instanceRespondsButDoesNotImplementSelector:(SEL)selector class:(Class)cls;
+ (void)replaceImplementationOfKnownSelector:(SEL)originalSelector onClass:(Class)cls withBlock:(id)block swizzledSelector:(SEL)swizzledSelector;
+ (void)replaceImplementationOfSelector:(SEL)selector withSelector:(SEL)swizzledSelector forClass:(Class)cls withMethodDescription:(struct objc_method_description)methodDescription implementationBlock:(id)implementationBlock undefinedBlock:(id)undefinedBlock;

@end
