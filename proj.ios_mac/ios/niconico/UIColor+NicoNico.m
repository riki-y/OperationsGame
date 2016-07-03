#import "UIColor+NicoNico.h"

@implementation UIColor (NicoNico)

- (int)intValue
{
    CGFloat red, green, blue, alpha;
    
    if (![self getRed:&red green:&green blue:&blue alpha:&alpha]) {
        CGFloat white;
        if ([self getWhite:&white alpha:&alpha]) {
            red = green = blue = white;
        }
    }
    
    int r = red * 255;
    int g = green * 255;
    int b = blue * 255;
    int a = alpha * 255;
    int color = (r << 16) | (g << 8) | (b) | (a << 24);
    
    return color;
}

@end
