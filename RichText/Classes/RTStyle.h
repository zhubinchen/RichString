//
//  ZHStyle.h
//  Pods-ZHRichText_Example
//
//  Created by zhubch on 2018/1/16.
//

#import <UIKit/UIKit.h>

@class RTStyle;

typedef NSString RTStyleIdentifier;

typedef void(^RTStyleBlock)(RTStyle *style);

@interface RTStyle : NSObject

@property (nonatomic,strong) UIColor             *color;
@property (nonatomic,strong) UIFont              *font;
@property (nonatomic,strong) UIColor             *backgroundColor;
@property (nonatomic,strong) UIColor             *underlineColor;
@property (nonatomic,strong) UIColor             *shadowColor;
@property (nonatomic,assign) CGSize              shadowOffset;
@property (nonatomic,assign) CGFloat             shadowBlurRadius;
@property (nonatomic,strong) UIColor             *strokeColor;
@property (nonatomic,assign) CGFloat             strokeWidth;
@property (nonatomic,assign) CGFloat             obliqueness;
@property (nonatomic,assign) CGFloat             expansion;
@property (nonatomic,assign) CGFloat             kern;
@property (nonatomic,assign) CGFloat lineSpacing;
@property (nonatomic,assign) CGFloat paragraphSpacing;
@property (nonatomic,assign) NSTextAlignment alignment;
@property (nonatomic,assign) CGFloat firstLineHeadIndent;
@property (nonatomic,assign) CGFloat headIndent;
@property (nonatomic,assign) CGFloat tailIndent;
@property (nonatomic,assign) NSLineBreakMode lineBreakMode;
@property (nonatomic,assign) CGFloat minimumLineHeight;
@property (nonatomic,assign) CGFloat maximumLineHeight;
@property (nonatomic,assign) CGFloat lineHeightMultiple;
@property (nonatomic,assign) CGFloat paragraphSpacingBefore;
@property (nonatomic,assign) CGFloat hyphenationFactor;

@property (readonly) NSDictionary      *attributes;

+ (instancetype)findStyleByIdentifier:(RTStyleIdentifier*)identifier;

- (void)registerWithIdentifier:(RTStyleIdentifier*)identifier;

+ (instancetype)create:(RTStyleBlock)maker;

@end

 __attribute__((unused)) static void register_style(RTStyleIdentifier *identifier,RTStyleBlock block) {
    RTStyle *style = [RTStyle create:block];
    [style registerWithIdentifier:identifier];
};

__attribute__((unused)) static RTStyle* find_style(RTStyleIdentifier *identifier) {
    return [RTStyle findStyleByIdentifier:identifier];
}
