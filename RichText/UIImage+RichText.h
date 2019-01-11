//
//  UIImage+RichText.h
//  Pods-ZHRichText_Example
//
//  Created by zhubch on 2018/1/19.
//

#import <UIKit/UIKit.h>
#import "RTText.h"

@interface UIImage(RichText) <RTText>

// 调整大小 image.withSize(20,20);
@property(readonly) UIImage*(^withSize)(CGFloat w,CGFloat h);

@end
